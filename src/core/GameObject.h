/* ---------------------------------------------------------------------------
** GameObject.h
** 
** Common interface for game Objects with name
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "core.h"
#include "IGameObject.h"

namespace core 
{
   class GameObject: public IGameObject
   {

   public:

        static std::string  sTypeName;

        virtual             ~GameObject()                                       {}

        virtual void        init()                                              {}
        virtual void        load()                                              {}
        virtual void        save()                                              {}

        virtual void        processInput(InputEvent& e)                         {}
        virtual void        update()                                            {}
        virtual void        draw()                                              {}

        const std::string&  getName() const                                     { return m_name; }
        const std::string&  getTypeName() const                                 { return sTypeName; }

    protected:

                            GameObject(const std::string& name): m_name(name)   {}

        const std::string    m_name;

   };



} // end namespace core


#endif /* GAME_OBJECT_H */