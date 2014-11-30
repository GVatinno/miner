
/* ---------------------------------------------------------------------------
** Decoration.h
** 
** Decoration in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef DECORATION_H
#define DECORATION_H

#include "NonCopyable.h"

namespace core 
{

    class Decoration: private NonCopyable
    {

    public:
                                Decoration( unsigned int x = 0, unsigned int y =0, unsigned int layer = 0 )
                                : m_screenPosX(x), m_screenPosY(y), m_screenLayer(layer), m_alive( true ) { }
                                
        virtual                 ~Decoration()                                   { }

        virtual void            draw() = 0;

        virtual void            setScreenPosX( unsigned int x )                 { m_screenPosX = x; }
        virtual unsigned int    getScreenPosX() const                           { return m_screenPosX; }

        virtual void            setScreenPosY( unsigned int y )                 { m_screenPosY = y; }
        virtual unsigned int    getScreenPosY() const                           { return m_screenPosY; }

        virtual void            setScreenLayer( unsigned int layer )            { m_screenLayer = layer; }
        virtual unsigned int    getScreenLayer()const                           { return m_screenLayer; }

        virtual void            setAlive( bool alive )                          { m_alive = alive; }
        virtual bool            getAlive() const                                { return m_alive; }

    protected:

        unsigned int            m_screenPosX;
        unsigned int            m_screenPosY;
        unsigned int            m_screenLayer;
        bool                    m_alive;

    };


} // end namespace core


#endif /* DECORATION_H */