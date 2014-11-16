
/* ---------------------------------------------------------------------------
** AnimatedSprite.cpp
** 
** AnimatedSprite
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "AnimatedSprite.h"
#include "Texture.h"
#include "TextureSystem.h"
#include "error_check.h"
#include "Singleton.h"
#include "GameConfig.h"

namespace core 
{
    
    AnimatedSprite::AnimatedSprite( const std::string& name, unsigned int spriteRow, unsigned int spriteCol,
                                unsigned int x, unsigned int y, unsigned int layer )
    : Sprite( name, x, y, layer), m_spriteRow( spriteRow ), m_spriteCol(spriteCol), m_currentClip( 0 )
    {
        Texture* tex = gTextureSystem::instance().getTexture( getTextureName() );
        DEBUG_ASSERT( tex != NULL )
        unsigned int w = tex->getW() / m_spriteCol;
        unsigned int h = tex->getH() / m_spriteRow;

        m_frames.reserve( spriteRow*spriteCol-1 );
        
        unsigned int col, row;

        for ( row = 0; row < m_spriteRow; ++row )
        {
            for ( col = 0; col < m_spriteCol; ++col )
            {
                SDL_Rect rect;
                rect.x = col * w;
                rect.y = row * h;
                rect.w = w;
                rect.h = h;
                m_frames.push_back( rect );
            }
        }
    }


    void AnimatedSprite::next()
    {
        if ( m_currentClip < m_frames.size()-1 )
            ++m_currentClip;
    }

    void AnimatedSprite::draw()
    {
        Texture* tex = gTextureSystem::instance().getTexture( getTextureName() );
        DEBUG_ASSERT( tex != NULL )
        const Point& layer_transform = gDisplayConfig::instance().getLayer( m_screenLayer );
        tex->draw( m_screenPosX+layer_transform.x, m_screenPosY+layer_transform.y, &m_frames[m_currentClip] );
    }


} // end namespace core