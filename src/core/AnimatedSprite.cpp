
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
#include "AnimationSystem.h"

namespace core 
{
    
    AnimatedSprite::AnimatedSprite( const std::string& name, const std::string& animationDes,
                                unsigned int x, unsigned int y, unsigned int layer )
    : Sprite( name, x, y, layer), m_currentClip( 0 ), m_animDesc( gAnimationSystem::instance().getAnimation( animationDes ) )
    {
    }


    void AnimatedSprite::next()
    {
        DEBUG_ASSERT( m_animDesc != NULL )
        if ( m_currentClip < m_animDesc->frameDesc.size()-1 )
            ++m_currentClip;
    }

    void AnimatedSprite::draw()
    {
        Texture* tex = gTextureSystem::instance().getTexture( getTextureName() );
        DEBUG_ASSERT( tex != NULL )
        const Point& layer_transform = gDisplayConfig::instance().getLayer( m_screenLayer );
        tex->draw( m_screenPosX+layer_transform.x, m_screenPosY+layer_transform.y, &m_animDesc->frameDesc[m_currentClip] );
    }


} // end namespace core