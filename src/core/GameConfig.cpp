/* ---------------------------------------------------------------------------
** GameConfig.cpp
** 
** Implements the game cnfiguration
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "GameConfig.h"

#include "core.h"
#include "error_check.h"

namespace core 
{
    //
    // TimeConfig
    //

    TimeConfig::TimeConfig()
    : m_fps(60),
      m_maxFrameSkip(10)
    {
    }


    //
    // DisplayConfig
    //

    DisplayConfig::DisplayConfig()
    : m_pixelPerUnit(24),
      m_windowWidth(800),
      m_windowHeight(600),
      m_windowPosX(100),
      m_windowPosY(100),
      m_layerMap( )
    {
    }


    void DisplayConfig::registerLayer(unsigned int layer, const Point& p )
    {
        DEBUG_ASSERT( m_layerMap.find( layer ) == m_layerMap.end() )
        if ( m_layerMap.find( layer ) == m_layerMap.end() )
        {
            m_layerMap.insert( std::make_pair(layer, p ) );
        }
    }
        

    const Point& DisplayConfig::getLayer(unsigned int layer ) const
    {
        PointMapItC it = m_layerMap.find( layer );
        DEBUG_ASSERT( it != m_layerMap.end() )
        if ( it != m_layerMap.end() )
        {
            return it->second;
        }
        return sOriginPoint;
    }

          
     
    //
    // SDLConfig
    //

    SDLConfig::SDLConfig()
    : m_videoInitialized(false),
      m_imgInitialized(false),
      m_fontInitialized(false),
      m_soundInitialized(false),
      m_window(NULL),
      m_renderer(NULL)
    {

    }


    SDLConfig::~SDLConfig()
    {
        Mix_Quit();
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();

        //Destroy window    
        SDL_GL_DeleteContext(m_glContex);
        SDL_DestroyRenderer( m_renderer );
        SDL_DestroyWindow( m_window );
        
    }


    bool SDLConfig::initVideo(int flags)
    {
        if ( ! m_videoInitialized )
        {   if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            {
                PRINT_ERROR( "SDL could not initialize!", SDL_GetError() );
                m_videoInitialized = false;
                return m_videoInitialized;
            }
            else
            {
                m_videoInitialized = true;
            }
                        
            //Set texture filtering to linear
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            {
                PRINT_WARNING("Linear texture filtering not enabled!", "")
            }
            glewInit();
        }
        return m_videoInitialized;
    }


    bool SDLConfig::initImg(int flags)
    {
        if ( ! m_imgInitialized )
        {
            if( !( IMG_Init( flags ) & flags ) )
            {
                PRINT_ERROR( "SDL could not initialize!", IMG_GetError() );
                m_imgInitialized = false;
                return m_imgInitialized;
            }
            else
            {
                m_imgInitialized = true;
            }
        }
        return m_imgInitialized;
    }


    bool SDLConfig::initFont(int flags)
    {
        if ( ! m_fontInitialized )
        {
            if( TTF_Init() == -1 )
            {
                PRINT_ERROR( "SDL could not initialize!", TTF_GetError() );
                m_fontInitialized = false;
                return m_fontInitialized;
            }
            else
            {
                m_fontInitialized = true;
            }
        }
        return m_fontInitialized;
    }


    bool SDLConfig::initSound(int flags)
    {
        if ( ! m_soundInitialized )
        {
            if ( SDL_Init( SDL_INIT_AUDIO ) < 0 )
            {
                PRINT_ERROR( "SDL could not initialize!", SDL_GetError() );
                m_soundInitialized = false;
                return m_soundInitialized;
            }
            else
            {
                m_soundInitialized = true;
            }

            if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            {
                PRINT_ERROR( "Mixer could not initialize!", Mix_GetError() );
                m_soundInitialized = false;
                return m_soundInitialized;
            }
            else
            {
                m_soundInitialized = true;
            }
            
        }
        return m_soundInitialized;
    }


    bool SDLConfig::initWindow(const std::string& gameName, int flags)
    {
        //Create window
        m_window = SDL_CreateWindow( gameName.c_str(),
            gDisplayConfig::instance().getWindowPosX(),
            gDisplayConfig::instance().getWindowPosY(), 
            gDisplayConfig::instance().getWindowWidth(),
            gDisplayConfig::instance().getWindowHeight(),
            flags );
        
        if( m_window == NULL )
        {
                PRINT_ERROR( "Window could not be created!", SDL_GetError() );
            return false;
        }

        m_glContex = SDL_GL_CreateContext(m_window);
        glViewport( 0, 0, ( GLsizei )gDisplayConfig::instance().getWindowWidth(), ( GLsizei )gDisplayConfig::instance().getWindowHeight() );

        GLenum error = glGetError();
        if( error != GL_NO_ERROR )
        {
            PRINT_ERROR( "Error initializing OpenGL!", gluErrorString( error ) );
            return false;
        }

        return true;
    }


    bool SDLConfig::initRenderer(int flags)
    {
        m_renderer = SDL_CreateRenderer( m_window, -1, flags );
        if( m_renderer == NULL )
        {
            PRINT_ERROR( "Renderer could not be created!", SDL_GetError() );
            return false;
        }
        return true;
    }


    SDL_Renderer* SDLConfig::getRenderer() const
    { 
        DEBUG_ASSERT( m_renderer != NULL )
        return m_renderer; 
    }
    

    SDL_Window* SDLConfig::getWindow() const
    { 
        DEBUG_ASSERT( m_window != NULL )
        return m_window; 
    }

    SDL_Surface* SDLConfig::getScreenSurface() const
    {
        DEBUG_ASSERT( m_window != NULL )
        DEBUG_ASSERT( m_renderer != NULL )
        return SDL_GetWindowSurface(m_window);
    }

} // end namespace core

