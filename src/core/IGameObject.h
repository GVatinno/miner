/* ---------------------------------------------------------------------------
** IGameObject.h
** 
** Common interface for game Objects
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{
   class IGameObject: private NonCopyable
   {
   public:

        virtual         ~IGameObject()                                        {}

        virtual void    init()=0;
        virtual void    load()=0;
        virtual void    save()=0;

        virtual void    processInput(InputEvent& e) =0;
        virtual void    update() =0;
        virtual void    draw() =0;

    protected:

                        IGameObject()                                         {}


   };


} // end namespace core


#endif /* I_GAME_OBJECT_H */