/* ---------------------------------------------------------------------------
** GridScene.h
** 
** Implements grid scene
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GRID_SCENE_H
#define GRID_SCENE_H

#include "miner.h"
#include <core/Scene.h>

namespace miner 
{
   class GridScene: public Scene
   {
    public:

        static std::string  sTypeName;

        
        virtual                 ~GridScene();

        static Scene*           create(const std::string& name)                 { return new GridScene(name); }

    protected:

                                GridScene(const std::string& name): Scene(name) {}

   };


} // end namespace miner


#endif /* GRID_SCENE_H */