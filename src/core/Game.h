/* ---------------------------------------------------------------------------
** core.h
** 
** Implements the game loop
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GAME_H
#define GAME_H

#include "core.h"
#include "IGameObject.h"

namespace core 
{
    class Game: public IGameObject
    {
    public:

        virtual         ~Game()                                                {}
        
        void            run();

        virtual void    init()=0;
        virtual void    load()=0;
        virtual void    save()=0;

        virtual void    processInput(InputEvent& e);
        virtual void    update();
        virtual void    draw();

    protected:

                        Game();

        void            setGameRunning( bool value )                            { m_gameIsRunning  = value; }
        bool            getGameRunning() const                                  { return m_gameIsRunning; }

        SceneManagerPtr m_sceneManagerPtr;

    private:

        void            playGameLoop();
        void            drawAvgFps();

        bool            m_gameIsRunning;
        AvgFPSPtr       m_avgFps;
       

    };

} // end namespace core


#endif /* GAME_H */
