
/* ---------------------------------------------------------------------------
** GridModel.cpp
** 
** Implements the grid in the game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/


#include "../miner.h"
#include "GridModel.h"
#include "Tile.h"
#include "Gem.h"
#include "Logic.h"

#include <core/Pointertable.h>

namespace
{
    unsigned int randomGem()
    {
        return std::rand() & 3;
    }

}

namespace miner
{

    GridModel::GridModel( unsigned int rows , unsigned int cols, unsigned int moves )
    : m_rows( rows ), m_cols( cols ), m_moves( moves ), 
      m_tiles( new TileTable( rows, cols, true) ),
      m_gems( new GemTable( rows, cols, true) ),
      m_state( K_GRIDSTATE_IDLE )
    {
    }


    GridModel::~GridModel()
    {
    }


    void GridModel::initializeGridRandom()
    {

        m_state = K_GRIDSTATE_LOADING;
        
        unsigned int row = 0;
        unsigned int col = 0;
        for ( row = 0; row < m_rows; ++row )
        {
            for ( col = 0; col < m_cols; ++col )
            {
                m_tiles->getAt( row, col ) = createTile( row, col,K_TILETYPE_STANDARD );
                m_gems->getAt( row, col ) = createGem( row, col, randomGem() );
            }
            
        }

        const unsigned int row_plus_one = m_rows+1;
        const unsigned int col_plus_one = m_cols+1;

        for ( row = 0; row <= row_plus_one; ++row )
        {
            for ( col = 0; col <=col_plus_one; ++col )
            {
                if ( col == 0 || row == 0 || col == col_plus_one || row == row_plus_one )
                    onBorderCreated( col, row );
            }
        }

        m_state = K_GRIDSTATE_WAITING_FIRE;
    }


    void GridModel::update()
    {
        if ( m_state == K_GRIDSTATE_DESTROYING_TILES )
        {
            updateDying();
        }
        else
        if ( m_state == K_GRIDSTATE_CLEANUP_TILES )
        {
            cleanUp();
        }
        else
        if ( m_state == K_GRIDSTATE_SWAPPING_GEMS )
        {
            swapGem();
        }
        else
        if ( m_state == K_GRIDSTATE_UPDATE_FALLING_GEMS )
        {
            updateFallingGems();
        }

    }


    void GridModel::updateDying()
    {
        const unsigned total = m_rows*m_cols;
        Gem* gem = NULL;
        unsigned int dying = 0;
        for ( unsigned int i = 0; i < total; ++i )
        {
            if ( m_tiles->getAt( i ) != NULL )
            {
                gem = m_gems->getAt( i );
                if ( gem->getState() == K_GEMTYPE_DYING )
                {
                     gem->update();
                     ++dying;
                }
            }
        }
        if ( dying == 0 )
        {
            m_state = K_GRIDSTATE_CLEANUP_TILES;
        }
    }


    void GridModel::cleanUp()
    {
        Gem* gem = NULL;
        const unsigned total = m_rows*m_cols;
        for ( unsigned int i = 0; i < total; ++i )
        {
            if ( m_tiles->getAt( i ) != NULL )
            {
                gem = m_gems->getAt( i );
                if ( gem->getState() == K_GEMTYPE_DEAD )
                {
                     m_gems->getAt( i ) = NULL;
                     delete gem;
                }
            }
        }
        m_state = K_GRIDSTATE_SWAPPING_GEMS;
    }


    void GridModel::swapGem()
    {
        for ( unsigned int i = 0; i < m_cols; ++i )
        {
            SwapVisitor visitor( this );
            DirectionalGridTraverser traverser( K_GRIDDIRECTION_UP, &visitor, m_rows, m_cols );
            traverser.traverse( m_rows-1, i );
            if ( ! visitor.m_rowHoleQueue.empty() )
            {
                for ( unsigned int h = 0; h < visitor.m_rowHoleQueue.size(); ++h )
                {
                    Gem* gem = createGem( visitor.m_rowHoleQueue[h], i, randomGem() );
                    DEBUG_ASSERT( m_gems->getAt( visitor.m_rowHoleQueue[h], i ) ==  NULL )
                    m_gems->getAt( visitor.m_rowHoleQueue[h], i ) = gem;
                    gem->setPosY( -1.0f * ((float)h+1.0f) );
                    gem->setState(K_GEMTYPE_FALLING);
                }
                
            }
        }
        m_state = K_GRIDSTATE_UPDATE_FALLING_GEMS;
    }


    void GridModel::updateFallingGems()
    {
        Gem* gem = NULL;
        unsigned int totalFalingGems = 0;
        const unsigned total = m_rows*m_cols;
        for ( unsigned int i = 0; i < total; ++i )
        {
            if ( m_tiles->getAt( i ) != NULL )
            {
                gem = m_gems->getAt( i );
                 gem->update();
                if ( gem->getState() == K_GEMTYPE_FALLING )
                    ++totalFalingGems;
            }
        }

        if ( totalFalingGems == 0 )
        {
            m_state = K_GRIDSTATE_WAITING_FIRE;
        }
    }



    Gem* GridModel::createGem( unsigned int row, unsigned int col, unsigned type )
    {
        Gem* gem = new Gem( row, col, type );
        onGemCreated( reinterpret_cast<const Entity*>( gem ) );
        return gem;
    }
        

    Tile* GridModel::createTile( unsigned int row, unsigned int col, unsigned type )
    {
        Tile* tile = new Tile( row, col, type );
        onTileCreated( reinterpret_cast<const Entity*>( tile ) );
        return tile;
    }


    void GridModel::fireOnTile( unsigned int row, unsigned int col )
    {
        if ( m_state != K_GRIDSTATE_WAITING_FIRE || row >= m_rows || col >= m_cols )
        {
            return;
        }
        m_state = k_GRIDSTATE_FINDING_MATCHES;
        if ( findMatch( row, col ) )
        {
            m_state = K_GRIDSTATE_DESTROYING_TILES;
        }
        else
        {
            m_state = K_GRIDSTATE_WAITING_FIRE;
        }
    }


    bool GridModel::findMatch( unsigned int row, unsigned int col )
    {
        Gem* gem = m_gems->getAt( row, col );
        DEBUG_ASSERT( gem != NULL )

        MatchVisitor visitor( this, gem->getGemType() );
        GridTraverser traverser( &visitor, m_rows, m_cols );
        traverser.traverse( row, col );        

        if ( visitor.m_matches >= 3 )
        {
            GemVectorItC it = visitor.m_dying.begin();
            GemVectorItC it_end = visitor.m_dying.end();
            for ( ; it != it_end ; ++it )
            {
                (*it)->setState(K_GEMTYPE_DYING);
            }
            return true;
        }    
        return false;

    }


} // end namesace miner