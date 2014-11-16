
/* ---------------------------------------------------------------------------
** TileSprite.cpp
** 
** TileSprite in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "TileSprite.h"

#include <core/Entity.h>
#include <core/GameConfig.h>
#include <core/TextureSystem.h>
#include <core/error_check.h>
#include <core/Texture.h>


namespace miner 
{

    TileSprite::TileSprite( const Entity* tile )
    : Sprite("tile_default", 0, 0, K_GAMELAYER_TILE),
      m_tile( tile )
    {
        Texture* tex = gTextureSystem::instance().getTexture( getTextureName() );
        DEBUG_ASSERT( tex != NULL )
        tex->setAlpha(0x99);
    }


    void TileSprite::draw()
    {
        const unsigned int pixU = gDisplayConfig::instance().getPixelPerUnit();
        setScreenPosX( m_tile->getPosX() * pixU );
        setScreenPosY( m_tile->getPosY() * pixU );

        Sprite::draw();
    }


} // end namespace miner
