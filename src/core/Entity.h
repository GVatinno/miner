/* ---------------------------------------------------------------------------
** Entity.h
** 
** Represent entity in a game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef ENTITY_H
#define ENTITY_H

#include "NonCopyable.h"

namespace core 
{
   class Entity: private NonCopyable
   {


    public:
        
                                Entity( unsigned int x =0, unsigned int y =0, unsigned int layer = 0 ) 
                                : m_posX( x ), m_posY( y ), m_layer( layer ) {}

        virtual                 ~Entity()                                       {}

        virtual void            update()= 0;

        virtual unsigned int    getLayer()const                                 { return m_layer; }
        virtual void            setLayer( unsigned int layer )                  { m_layer = m_layer; }

        virtual void            setPosX( float x )                              { m_posX = x; }
        virtual float           getPosX() const                                 { return m_posX; }
        virtual void            setPosY( float y )                              { m_posY = y; }
        virtual float           getPosY() const                                 { return m_posY; }

    private:

        float m_posX;
        float m_posY;
        unsigned int m_layer;
   };


} // end namespace core


#endif /* ENTITY_H */