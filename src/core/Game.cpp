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
#include "fps.h"
#include "Texture.h"

namespace core 
{
    Game::Game() 
    : m_sceneManagerPtr( SceneManager::create() ),
      m_gameIsRunning(false), m_avgFps( new AvgFPS() )
      
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
        Uint32 start_tick = SDL_GetTicks();
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
            
            m_avgFps->addTick( SDL_GetTicks() - start_tick );
            start_tick = SDL_GetTicks();
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
        SDL_RenderClear( gSDLConfig::instance().getRenderer() );
        DEBUG_ASSERT( m_sceneManagerPtr->getCurrentScenePtr() != NULL )
        
        m_sceneManagerPtr->draw();
        DEBUG_CALL(drawAvgFps());
        
        SDL_RenderPresent( gSDLConfig::instance().getRenderer() );
        
    }


    void Game::drawAvgFps()
    {
        
        std::stringstream timeText;
        timeText << m_avgFps->getAvgFramePerSecond();
        Texture fps_texture(sBlackColor);
        fps_texture.loadFromText(timeText.str() , "lazy-15");
        fps_texture.draw(0,0);
    }


} // end namespace core