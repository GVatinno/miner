
/* ---------------------------------------------------------------------------
** GemSprite.cpp
** 
** GemSprite in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "GemSprite.h"
#include "Gem.h"

#include <core/Entity.h>
#include <core/GameConfig.h>
#include <core/TextureSystem.h>
#include <core/error_check.h>
#include <core/Texture.h>
#include <core/AnimatedSprite.h>

namespace {

    using namespace miner;

    typedef std::map<unsigned int, std::string> MapGemTypeSprite;
    typedef std::auto_ptr<MapGemTypeSprite> MapGemTypeSpritePtr; 

    const std::string& getTextureNameFromType( unsigned int gemType )
    {
        static MapGemTypeSpritePtr map( new MapGemTypeSprite() );
        if ( map->empty() )
        {
            map->insert( std::make_pair( K_GEMTYPE_CRYSTAL , "gem-crystal") );
            map->insert( std::make_pair( K_GEMTYPE_DIAMOND , "gem-diamond") );
            map->insert( std::make_pair( K_GEMTYPE_RUBIN , "gem-rubin") );
            map->insert( std::make_pair( K_GEMTYPE_TOPAZ , "gem-topaz") );
        }
        return map->operator[](gemType);
    }
}


namespace miner 
{

    GemSprite::GemSprite( const Entity* gem )
    : Sprite("", 0, 0, K_GAMELAYER_GEM ),
      m_gem( reinterpret_cast<const Gem*>(gem) ),
      m_dyingSprite( new AnimatedSprite("smoke", 1 , 20, 0, 0, K_GAMELAYER_GEM ) ),
      m_dyingAlpha(0xFF),
      m_lastAnimFrame( 0)
    {
        setTextureName(getTextureNameFromType(m_gem->getGemType()));
        Texture* tex = getTexture();
        DEBUG_ASSERT( tex != NULL )
        tex->setBlendMode(SDL_BLENDMODE_BLEND);
  
    }


    void GemSprite::draw()
    {
        if ( m_gem->getState() == K_GEMTYPE_DEAD )
        {
             setAlive(false);
             return;
        }

        const unsigned int pixU = gDisplayConfig::instance().getPixelPerUnit();
        setScreenPosX( m_gem->getPosX() * pixU );
        setScreenPosY( m_gem->getPosY() * pixU );
        
       
        if ( m_gem->getState() == K_GEMTYPE_DYING )
        {

            Texture* tex = getTexture();
            tex->setAlpha(m_dyingAlpha);
            Sprite::draw();
            tex->setAlpha(0xFF);
            m_dyingSprite->setScreenPosX( getScreenPosX() );
            m_dyingSprite->setScreenPosY( getScreenPosY() );
            m_dyingSprite->draw();
            if ( m_gem->getCurentDyingFrame() > m_lastAnimFrame )
            {
                m_dyingSprite->next();
                m_lastAnimFrame = m_gem->getCurentDyingFrame();
                m_dyingAlpha -= 0x9;
            }
            
        }
        else if ( m_gem->getState() != K_GEMTYPE_DEAD  )
        {
            if ( m_gem->getPosY() >= 0 )
                Sprite::draw();
        }

    }


} // end namespace miner
