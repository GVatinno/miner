/* ---------------------------------------------------------------------------
** core.h
** 
** Forward declaration for classes in the core and common include
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef CORE_H
#define CORE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string>
#include <utility>
#include <memory>
#include <map>



namespace core
{
    //
    // Forward declarations
    //
    
    class Game;
    class DisplayConfig;
    class SDLConfig;
    class Scene;
    class SceneManager;
    class TimeConfig;
    

    template < class T >
    class Singleton;

    template< class T >
    class Factory;

    template< class T >
    class Event;

    //
    // type definitions
    //

    typedef std::auto_ptr<SceneManager>     SceneManagerPtr;

    typedef Singleton<TimeConfig>           gTimeConfig;
    typedef Singleton<DisplayConfig>        gDisplayConfig;
    typedef Singleton<SDLConfig>            gSDLConfig;

    typedef std::map< std::string, Scene*>  ScenePtrMap;
    typedef ScenePtrMap::iterator           ScenePtrMapIt;
    typedef ScenePtrMap::const_iterator     ScenePtrMapItC;

    typedef Factory<Scene>                  SceneFactory;

    typedef Event<SDL_Event>                InputEvent;


    //
    //
    //


} // end namespace core
#endif /* CORE_H */
