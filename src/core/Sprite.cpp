
/* ---------------------------------------------------------------------------
** Sprite.cpp
** 
** Sprite
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "Sprite.h"
#include "Texture.h"
#include "TextureSystem.h"
#include "error_check.h"
#include "Singleton.h"
#include "GameConfig.h"

namespace core 
{
    
    Sprite::Sprite( const std::string& name, unsigned int x, unsigned int y, unsigned int layer )
    : Decoration( x, y, layer), m_textureName( name ) 
    {

    }

    Texture* Sprite::getTexture() const
    {
        return gTextureSystem::instance().getTexture( m_textureName );
        
    }

    void Sprite::draw()
    {
        Texture* tex = gTextureSystem::instance().getTexture( m_textureName );
        DEBUG_ASSERT( tex != NULL )
        const Point& layer_transform = gDisplayConfig::instance().getLayer( m_screenLayer );
        tex->draw( m_screenPosX+layer_transform.x, m_screenPosY+layer_transform.y );
    }


} // end namespace core