/* ---------------------------------------------------------------------------
** Texture.cpp
** 
** Texture
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "Texture.h"
#include "error_check.h"
#include "Gameconfig.h"

namespace core
{

    Texture::Texture( const std::string& filename, const RGB& key )
    : m_filename( filename ), m_colorKey( key ), m_texture( NULL ), m_w(0), m_h(0)
    {

    }

    
    void Texture::load()
    {
        if ( m_texture == NULL )
        {
            SDL_Surface* surface = NULL;
            surface = IMG_Load( m_filename.c_str() );
            if ( surface != NULL )
            {
                SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB( surface->format, m_colorKey.r, m_colorKey.g, m_colorKey.b ) );
                m_texture = SDL_CreateTextureFromSurface( gSDLConfig::instance().getRenderer(), surface );
                m_w = surface->w;
                m_h = surface->h;
                SDL_FreeSurface( surface );
                DEBUG_ASSERT( m_texture != NULL )
            }
            else
            {
                PRINT_ERROR( "Error Loading Texture:", IMG_GetError() );
                DEBUG_ASSERT( surface != NULL )
            }
        }
    }

    Texture::~Texture()
    {
        if ( m_texture )
        {
            SDL_DestroyTexture( m_texture );
            m_texture = NULL;
        }
    }


    void Texture::setColor( const RGB& color )
    {
        DEBUG_ASSERT( m_texture != NULL )
        SDL_SetTextureColorMod( m_texture, color.r, color.g, color.b );
    }

    void Texture::setBlendMode( SDL_BlendMode blending )
    {
        DEBUG_ASSERT( m_texture != NULL )
        SDL_SetTextureBlendMode( m_texture, blending );
    }

    void Texture::setAlpha( Uint8 alpha )
    {
        DEBUG_ASSERT( m_texture != NULL )
        SDL_SetTextureAlphaMod( m_texture, alpha );
    }

    bool Texture::isValid() const
    {
        return m_texture != NULL;
    }

    unsigned int Texture::getW() const
    {
        DEBUG_ASSERT( m_texture != NULL )
        return m_w;
    }
    
    unsigned int Texture::getH() const
    {
        DEBUG_ASSERT( m_texture != NULL )
        return m_h;
    }


    void Texture::draw( int x, int y, SDL_Rect* clip )
    {
        //Set rendering space and render to screen
        SDL_Rect renderQuad = { x, y, (int)m_w, (int)m_h };

        //Set clip rendering dimensions
        if( clip != NULL )
        {
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }

        //Render to screen
        SDL_RenderCopy( gSDLConfig::instance().getRenderer(), m_texture, clip, &renderQuad );
    }



} // end namespace core
