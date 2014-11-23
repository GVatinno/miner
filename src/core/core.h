/* ---------------------------------------------------------------------------
** core.h
** 
** Forward declaration for classes in the core and common include
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef CORE_H
#define CORE_H


#include <GL/Glew.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include <memory>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <deque>

// boost include
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>



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
    class Entity;
    class Decoration;
    class Texture;
    class TextureSystem;
    class FontSystem;
    class Point;
    class GridTraverser;
    class DirectionalGridTraverser;
    class GridVisitor;
    class AnimatedSprite;
    class AvgFPS;
    class AnimationDesc;
    class AnimationSystem;
    

    template < class T >
    class Singleton;

    template< class T >
    class Factory;

    template< class T >
    class Event;

    template< class T >
    class PointerTable;

    //
    // type definitions
    //

    typedef std::auto_ptr<SceneManager>                 SceneManagerPtr;

    typedef Singleton<TimeConfig>                       gTimeConfig;
    typedef Singleton<DisplayConfig>                    gDisplayConfig;
    typedef Singleton<SDLConfig>                        gSDLConfig;
    typedef Singleton<TextureSystem>                    gTextureSystem;
    typedef Singleton<FontSystem>                       gFontSystem;
    typedef Singleton<AnimationSystem>                  gAnimationSystem;

    typedef boost::unordered_map< std::string, Scene*>  ScenePtrMap;
    typedef ScenePtrMap::iterator                       ScenePtrMapIt;
    typedef ScenePtrMap::const_iterator                 ScenePtrMapItC;

    typedef boost::unordered_map<std::string, Texture*> TexturePtrMap;
    typedef TexturePtrMap::iterator                     TexturePtrMapIt;
    typedef TexturePtrMap::const_iterator               TexturePtrMapItC;

    typedef boost::unordered_map<std::string,TTF_Font*> FontPtrMap;
    typedef FontPtrMap::iterator                        FontPtrMapIt;
    typedef FontPtrMap::const_iterator                  FontPtrMapItC;

    typedef std::vector<Decoration*>                    DecorationVector;
    typedef DecorationVector::iterator                  DecorationVectorIt;
    typedef DecorationVector::const_iterator            DecorationVectorItC;

    typedef boost::unordered_map<unsigned int, Point>   PointMap;
    typedef PointMap::iterator                          PointMapIt;
    typedef PointMap::const_iterator                    PointMapItC;

    typedef Factory<Scene>                              SceneFactory;

    typedef Event<SDL_Event>                            InputEvent;

    typedef std::vector<SDL_Rect>                       RectVector;

    typedef std::auto_ptr<AvgFPS>                       AvgFPSPtr;

    typedef std::vector<SDL_Rect>                       RectVector;
    typedef RectVector::iterator                        RectVectorIt;
    typedef RectVector::const_iterator                  RectVectorItC;

    typedef boost::unordered_map<std::string, AnimationDesc*>    AnimDescPtrMap;
    typedef AnimDescPtrMap::iterator                             AnimDescPtrMapIt;
    typedef AnimDescPtrMap::const_iterator                       AnimDescPtrMapItC;

    struct RGB
    {
        Uint8 r;
        Uint8 g;
        Uint8 b;
    };

    struct RGBA
    {
        Uint8 r;
        Uint8 g;
        Uint8 b;
        Uint8 a;
    };

    struct Point
    {
        unsigned int x;
        unsigned int y;
    }; 

    static Point sOriginPoint  = { 0, 0 };
    static RGB   sWhiteColor   = { 0xFF, 0xFF, 0xFF };
    static RGB   sBlackColor   = { 0x00, 0x00, 0x00 };


    //
    //
    //


} // end namespace core
#endif /* CORE_H */
