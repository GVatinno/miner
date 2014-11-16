/* ---------------------------------------------------------------------------
** TextureSystem.cpp
** 
** Texture System
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#include "TextureSystem.h"
#include "Texture.h"
#include "error_check.h"

namespace core 
{
    TextureSystem::TextureSystem()
    : m_textureMap( )
    {

    }


    TextureSystem::~TextureSystem()
    {
        TexturePtrMapItC it = m_textureMap.begin();
        TexturePtrMapItC it_end = m_textureMap.end();
        for ( ; it != it_end ; ++it )
        {
            delete (it->second);
        }
        m_textureMap.clear();
    }


    void TextureSystem::registerTexture( const std::string& path, const std::string& name, const RGB& key )
    {
        DEBUG_ASSERT( m_textureMap.find( name ) == m_textureMap.end() )
        if ( m_textureMap.find( name ) == m_textureMap.end() )
        {
            m_textureMap.insert( std::make_pair(name, new Texture( path, key )) );
        }
    }
    

    Texture* TextureSystem::getTexture( const std::string& name ) const
    {
        TexturePtrMapItC it = m_textureMap.find( name );
        DEBUG_ASSERT( it != m_textureMap.end() )
        if ( it != m_textureMap.end() )
        {
            it->second->load();
            return it->second;
        }
        return NULL;
    }

}