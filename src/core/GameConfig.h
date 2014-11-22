/* ---------------------------------------------------------------------------
** GameConfig.h
** 
** Implements the game cnfiguration
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include "NonCopyable.h"
#include "Singleton.h"

namespace core 
{
    //
    // TimeConfig
    //

    class TimeConfig: public NonCopyable
    {
    public:
                                ~TimeConfig()                                   { }

        static TimeConfig*      create()                                        { return new TimeConfig(); }
        
        inline void             setFps( unsigned int fps )                      { m_fps = fps; }
        inline unsigned int     getFps() const                                  { return m_fps; }

        inline void             setMaxFrameSkip( unsigned int maxFrameSkip )    { m_maxFrameSkip = maxFrameSkip; }
        inline unsigned int     getMaxFrameSkip() const                         { return m_maxFrameSkip; }

        inline unsigned int     getSkipTicks() const                            { return 1000 / m_fps; }

    private:
                                TimeConfig();

        unsigned int m_fps;
        unsigned int m_maxFrameSkip;
    };



    //
    // DisplayConfig
    //
    class DisplayConfig : public NonCopyable
    {
    protected:
                                

    public:
                                ~DisplayConfig()                                { }
        
        static DisplayConfig*   create()                                        { return new DisplayConfig(); }

        inline void             setPixelPerUnit( unsigned int pixel )           { m_pixelPerUnit = pixel; }
        inline unsigned int     getPixelPerUnit() const                          { return m_pixelPerUnit; }

        inline void             setWindowWidth( unsigned int width)             { m_windowWidth = width; }
        inline unsigned int     getWindowWidth() const                          { return m_windowWidth; }

        inline void             setWindowHeight( unsigned int height)           { m_windowHeight = height; }
        inline unsigned int     getWindowHeight() const                         { return m_windowHeight; }

        inline void             setWindowPosX( unsigned int x)                  { m_windowPosX = x; }
        inline unsigned int     getWindowPosX() const                           { return m_windowPosX; }

        inline void             setWindowPosY( unsigned int y)                  { m_windowPosY = y; }
        inline unsigned int     getWindowPosY() const                           { return m_windowPosY; }



        void                    registerLayer(unsigned int layer, const Point& p );
        const Point&            getLayer(unsigned int layer ) const;

    private:
                                DisplayConfig();


        unsigned int m_pixelPerUnit;
        unsigned int m_windowWidth;
        unsigned int m_windowHeight;
        unsigned int m_windowPosX;
        unsigned int m_windowPosY;
        PointMap     m_layerMap;
    };


    //
    // SDLConfig
    //
    class SDLConfig : public NonCopyable
    {
    public:
                                ~SDLConfig();
        static SDLConfig*       create()                                        { return new SDLConfig(); }

        bool                    initVideo(int flags=0);
        bool                    initImg(int flags=0);
        bool                    initFont(int flags=0);
        bool                    initSound(int flags=0);
        bool                    initWindow(const std::string& gameName,int flags=0);
        bool                    initRenderer(int flags=0);

        SDL_Renderer*           getRenderer() const;
        SDL_Window*             getWindow() const;
        SDL_Surface*            getScreenSurface() const;
        

    private:

                                SDLConfig();
        
        bool            m_videoInitialized;
        bool            m_imgInitialized;
        bool            m_fontInitialized;
        bool            m_soundInitialized;

        SDL_Window*     m_window;
        SDL_Renderer*   m_renderer;
        SDL_GLContext   m_glContex;
    };

} // end namespace core


#endif /* GAME_H */
