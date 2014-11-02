/* ---------------------------------------------------------------------------
** SceneManager.cpp
** 
** Manages scenes in a game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "SceneManager.h"
#include "error_check.h"
#include "Scene.h"


namespace core
{
    
    SceneManager::SceneManager()
    : m_sceneCollection( ),
      m_currentScene(NULL),
      m_sceneFactory( )
    {

    }


    SceneManager::~SceneManager()
    {
        ScenePtrMapIt it = m_sceneCollection.begin();
        ScenePtrMapIt it_end = m_sceneCollection.end();
        for ( ; it != it_end ; ++it )
        {
            DEBUG_ASSERT( it->second != NULL )
            DEBUG_ASSERT( it->first.empty() == false )
            delete (it->second);
            it->second = NULL;
        }
        m_sceneCollection.clear();
    }


    void SceneManager::registerScene(const std::string& typeName, SceneFactory::Creator creator)
    {
        m_sceneFactory.registerCreator(typeName, creator);
    }

    
    Scene* SceneManager::addScene(const std::string& typeName,const std::string& name)
    {
        Scene* scene = findScene( name );
        if ( scene == NULL )
        {
            scene = m_sceneFactory.create(typeName);
            DEBUG_ASSERT( scene != NULL )
            m_sceneCollection.insert( std::make_pair(name,scene) );
            scene->init();
        }
        return scene;
    }


    void SceneManager::removeScene(const std::string& name)
    {
        ScenePtrMapIt found = m_sceneCollection.find(name);
        if ( found != m_sceneCollection.end() )
        {
            Scene* scene = found->second;
            DEBUG_ASSERT( scene != m_currentScene )
            DEBUG_ASSERT( scene != NULL )
            delete scene;
            m_sceneCollection.erase(found);
        }
    }


    Scene* SceneManager::findScene(const std::string& name) const
    {
        ScenePtrMapItC found = m_sceneCollection.find(name);
        if ( found != m_sceneCollection.end() )
        {
            return found->second;
        }
        return NULL;
    }


    void SceneManager::setCurrentScene(const std::string name)
    {
        DEBUG_ASSERT( name.empty() == false )
        Scene* scene = findScene(name);
        DEBUG_ASSERT( scene != NULL )
        scene->load();
        m_currentScene = scene;
    }


    const std::string SceneManager::getCurrentScene() const
    {
        if ( m_currentScene )
        {
            return m_currentScene->getName();
        }
        return "";
    }


    const Scene* SceneManager::getCurrentScenePtr() const
    {
        return m_currentScene;
    }


    void SceneManager::processInput(InputEvent& e)
    {
        m_currentScene->processInput(e);
    }

    
    void SceneManager::update()
    {
        m_currentScene->update();
    }


    void SceneManager::draw()
    {
        m_currentScene->draw();
    }
    


}