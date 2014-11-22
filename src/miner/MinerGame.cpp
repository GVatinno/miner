/* ---------------------------------------------------------------------------
** Miner.cpp
** 
** Implementatation of the game Miner
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "MinerGame.h"
#include "scenes/GridScene.h"

#include <core/GameConfig.h>
#include <core/SceneManager.h>
#include <core/error_check.h>



namespace miner
{

    MinerGame::MinerGame()
    : Game()
    {

    }


    void MinerGame::init()
    {
        Game::init();

        gDisplayConfig::instance().setWindowWidth(640);
        gDisplayConfig::instance().setWindowHeight(480);

        
        
        gDisplayConfig::instance().registerLayer( K_GAMELAYER_DEFAULT, sOriginPoint );
        gDisplayConfig::instance().registerLayer( K_GAMELAYER_BACKGROUND, sOriginPoint );
        

        bool success = true;

        success &= gSDLConfig::instance().initVideo();
        success &= gSDLConfig::instance().initWindow("Miner", SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
        success &= gSDLConfig::instance().initRenderer(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        success &= gSDLConfig::instance().initImg(IMG_INIT_PNG);
        success &= gSDLConfig::instance().initFont();
        success &= gSDLConfig::instance().initSound();
        setGameRunning(success);
       

        m_sceneManagerPtr->registerScene(GridScene::sTypeName, GridScene::create);
    }


    void MinerGame::load()
    {
        Game::load();

        Scene* scene = m_sceneManagerPtr->addScene( GridScene::sTypeName, "GridScene" );

        DEBUG_ASSERT( scene != NULL )
        m_sceneManagerPtr->setCurrentScene(scene->getName());

    }


    void MinerGame::save()
    {
        Game::save();
    }

} // end namespace miner