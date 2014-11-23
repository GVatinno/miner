/* ---------------------------------------------------------------------------
** FontSystem.cpp
** 
** Texture System
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#include "FontSystem.h"
#include "error_check.h"

namespace core 
{
    FontSystem::FontSystem()
    : m_fontMap( )
    {

    }


    FontSystem::~FontSystem()
    {
        FontPtrMapItC it = m_fontMap.begin();
        FontPtrMapItC it_end = m_fontMap.end();
        for ( ; it != it_end ; ++it )
        {
            TTF_CloseFont( it->second );
        }
        m_fontMap.clear();
    }


    void FontSystem::registerFont( const std::string& path, const std::string& name, unsigned int fontSize )
    {
        DEBUG_ASSERT( m_fontMap.find( name ) == m_fontMap.end() )
        TTF_Font* font = TTF_OpenFont( path.c_str(), fontSize );
        DEBUG_ASSERT( font != NULL )
        if ( m_fontMap.find( name ) == m_fontMap.end() )
        {
            m_fontMap.insert( std::make_pair(name, font ));
        }
    }
    

    TTF_Font* FontSystem::getFont( const std::string& name ) const
    {
        FontPtrMapItC it = m_fontMap.find( name );
        DEBUG_ASSERT( it != m_fontMap.end() )
        if ( it != m_fontMap.end() )
        {
            return it->second;
        }
        return NULL;
    }

}