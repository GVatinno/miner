
/* ---------------------------------------------------------------------------
** GridView.cpp
** 
** GridView
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "GridView.h"
#include <core/Decoration.h>
#include <core/error_check.h>
#include <core/GameConfig.h>

namespace {
    
    bool isDead( Decoration* d )
    {
        return ! d->getAlive();
    }

    bool isLessThan( Decoration* lhs, Decoration* rhs )
    {
        return lhs->getScreenLayer() < rhs->getScreenLayer();
    }
}

namespace miner 
{

    GridView::GridView()
    : m_decorationVector(  )
    {
        // add background Sprite
        addDecoration( new Sprite( "background" ) );
    }


    void GridView::addDecoration( Decoration* decoration )
    {
        DEBUG_ASSERT( decoration != NULL )
        m_decorationVector.insert(
            std::upper_bound(
                m_decorationVector.begin(),
                m_decorationVector.end(),
                decoration,
                isLessThan),
            decoration
            );
    }


    GridView::~GridView()
    {
        DecorationVectorItC it = m_decorationVector.begin();
        DecorationVectorItC it_end = m_decorationVector.end();
        for ( ; it != it_end ; ++it )
        {
            delete *(it);
        }
        m_decorationVector.clear();
    }


    void GridView::draw()
    {
        m_decorationVector.erase( 
            std::remove_if( 
                m_decorationVector.begin(), 
                m_decorationVector.end(), 
                isDead ),
            m_decorationVector.end() );

        // RGBA back_color = { 0xFF, 0x00, 0x00, 0xFF };
        // SDL_SetRenderDrawColor( gSDLConfig::instance().getRenderer(), back_color.r, back_color.g, back_color.b, back_color.a );
        // SDL_RenderClear( gSDLConfig::instance().getRenderer() );

        DecorationVectorIt it = m_decorationVector.begin();
        DecorationVectorIt it_end = m_decorationVector.end();
        for ( ; it != it_end ; ++it )
        {
            DEBUG_ASSERT( (*it) != NULL )
            (*it)->draw();
        }

        // SDL_RenderPresent( gSDLConfig::instance().getRenderer() );
    }

} // end namespace miner