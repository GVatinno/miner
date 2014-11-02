/* ---------------------------------------------------------------------------
** Scene.h
** 
** Scenes in a game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef SCENE_H
#define SCENE_H

#include "GameObject.h"

namespace core 
{
   class Scene: public GameObject
   {

    static std::string  sTypeName;

    public:
        
        virtual                 ~Scene()                                        {}

        static Scene*           create(const std::string& name)                 { return new Scene(name); }

    protected:

                                Scene(const std::string& name): GameObject(name) {}

   };


} // end namespace core


#endif /* SCENE_H */