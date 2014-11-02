/* ---------------------------------------------------------------------------
** core.cpp
** 
** Implements the game loop
**
** Author: Gianluca
** -------------------------------------------------------------------------*/



#include "Game.h"
#include "GameConfig.h"
#include "SceneManager.h"
#include "Event.h"
#include "error_check.h"

namespace core 
{
    Game::Game() 
    : m_sceneManagerPtr( SceneManager::create() ),
      m_gameIsRunning(false)
      
    {

    }

    void Game::run()
    {
        init();
        load();
        if ( getGameRunning() )
        {
            playGameLoop();
        }
    }


    void Game::playGameLoop()
    {
        DEBUG_MSG( "Game Play ..." )
        setGameRunning(true);
        const Uint32 skip_ticks = gTimeConfig::instance().getSkipTicks();
        const Uint32 max_frame_skip = gTimeConfig::instance().getMaxFrameSkip();

        unsigned short loops = 0;
        Uint32 next_game_tick = SDL_GetTicks();
        
        while( m_gameIsRunning ) 
        {
            SDL_Event e;
            while( SDL_PollEvent( &e ) != 0 )
            {
                InputEvent inputeEvent(e);
                processInput(inputeEvent);
            }
            
            loops = 0;
            while( SDL_GetTicks() > next_game_tick && loops < max_frame_skip)
            {
                update();
                next_game_tick += skip_ticks;
                loops++;
            }

            draw();
        }
    }


    void Game::init()
    {
        DEBUG_MSG( "Game Init ..." )
    }


    void Game::load()
    {
        DEBUG_MSG( "Game Load ..." )
    }


    void Game::save()
    {
        DEBUG_MSG( "Game save ..." )
    }


    void Game::processInput(InputEvent& e)
    {
        //User requests quit
        if( ! e.getConsumed() && e.getEvent().type == SDL_QUIT )
        {
            e.setConsumed(true);
            setGameRunning(false);
        }

        DEBUG_ASSERT( m_sceneManagerPtr->getCurrentScenePtr() != NULL )
        m_sceneManagerPtr->processInput(e);
    }


    void Game::update()
    {
        DEBUG_ASSERT( m_sceneManagerPtr->getCurrentScenePtr() != NULL )
        m_sceneManagerPtr->update();
    }


    void Game::draw()
    {
        DEBUG_ASSERT( m_sceneManagerPtr->getCurrentScenePtr() != NULL )
        m_sceneManagerPtr->draw();
    }


} // end namespace core