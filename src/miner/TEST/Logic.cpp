
/* ---------------------------------------------------------------------------
** Logic.cpp
** 
** Logic in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "Logic.h"
#include "GridModel.h"
#include "Gem.h"
#include "Tile.h"

#include <core/Pointertable.h>
#include <core/error_check.h>
#include <core/GridTraverser.h>
#include <core/PointerTable.h>



namespace miner 
{

    MatchVisitor::MatchVisitor( const GridModel* gridModel, unsigned int seed )
    : m_gridModel( gridModel ), 
      m_seed( seed ), m_matches( 0 ), m_visited( )
    {

    }

    bool MatchVisitor::visit( int x, int y )
    {
        Tile* tile = m_gridModel->m_tiles->getAt( x, y );
        Gem* gem = m_gridModel->m_gems->getAt( x, y );

        if ( m_visited.find( gem ) == m_visited.end() )
            m_visited.insert( gem );
        else
            return false;

        if ( tile == NULL )
            return false;

        DEBUG_ASSERT( gem != NULL)
        DEBUG_ASSERT( tile->getRow() == gem->getRow())
        DEBUG_ASSERT( tile->getCol() == gem->getCol())

        if ( gem->getGemType() != m_seed )
            return false;

        
        m_dying.push_back( gem );
        ++m_matches;

        return true;
    }



    SwapVisitor::SwapVisitor( const GridModel* gridModel )
    : m_gridModel( gridModel )
    {

    }

    bool SwapVisitor::visit( int x, int y )
    {
        Tile* tile = m_gridModel->m_tiles->getAt( x, y );
        Gem* gem = m_gridModel->m_gems->getAt( x, y );

        if ( tile == NULL )
            return true;
        if ( gem == NULL )
        {
            m_rowHoleQueue.push_back( x );
        }
        else
        {
            // do the swap
            if ( ! m_rowHoleQueue.empty() )
            {
                unsigned int row_to = m_rowHoleQueue.front();
                m_gridModel->m_gems->getAt( x, y ) = NULL;
                m_gridModel->m_gems->getAt( row_to, y ) = gem;
                gem->setRowOnly( row_to );
                gem->setState(K_GEMTYPE_FALLING);
                m_rowHoleQueue.pop_front();
                if ( row_to != (unsigned int)x )
                    m_rowHoleQueue.push_back( x );
            }
        }
        return true;
    }

} // end namespace miner
 