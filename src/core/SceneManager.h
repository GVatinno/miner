/* ---------------------------------------------------------------------------
** SceneManager.h
** 
** Manages scenes in a game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


#include "core.h"
#include "IGameObject.h"
#include "Factory.h"

namespace core 
{
   class SceneManager: public IGameObject
   {
    public:
        
        virtual                 ~SceneManager();

        static SceneManager*    create()                                        { return new SceneManager(); }

        virtual void            init()                                          {}
        virtual void            load()                                          {}
        virtual void            save()                                          {}

        virtual void            processInput(InputEvent& e);
        virtual void            update();
        virtual void            draw();

        void                    registerScene(const std::string& typeName, SceneFactory::Creator creator);
        Scene*                  addScene(const std::string& typeName, const std::string& name);
        void                    removeScene(const std::string& name);
        Scene*                  findScene(const std::string& name) const;

        void                    setCurrentScene(const std::string name);
        const std::string       getCurrentScene() const;
        const Scene*            getCurrentScenePtr() const;


    private:

                                SceneManager();

        

        ScenePtrMap     m_sceneCollection;
        Scene*          m_currentScene;
        SceneFactory    m_sceneFactory;
   };


} // end namespace core


#endif /* SCENE_MANAGER_H */