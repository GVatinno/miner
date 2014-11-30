/* ---------------------------------------------------------------------------
** IGameObject.h
** 
** Common interface for game Objects
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef FPS_H
#define FPS_H

#include "core.h"
#include "NonCopyable.h"

#define AVGFPS_MAX_TICK_VALUES 10

namespace core 
{
    class AvgFPS: private NonCopyable
    {
    public:

                        AvgFPS();
        virtual         ~AvgFPS()                                               {}

        void            addTick( int newTick );
        double          getAvgTickPerFrame() const;
        double          getAvgFramePerSecond() const;

    private:

      int          m_tickVector[AVGFPS_MAX_TICK_VALUES];
      int          m_tickId;
      int          m_tickSum;
      double       m_lastAvg;
      bool         m_arrayFull;

    };


    AvgFPS::AvgFPS()
    : m_tickId(0), m_tickSum(0), m_lastAvg(0.0), m_arrayFull(false)
    {
        memset(&m_tickVector[0], 0, sizeof(int) *AVGFPS_MAX_TICK_VALUES );
    }


    void AvgFPS::addTick( int newTick )
    {
        m_tickSum -= m_tickVector[m_tickId];
        m_tickSum += newTick;             
        m_tickVector[m_tickId] = newTick;   
        ++m_tickId;
        if( m_tickId >= AVGFPS_MAX_TICK_VALUES )  
        {
            m_tickId = 0;
            m_arrayFull = true;
        }
        m_lastAvg = (double)(m_tickSum / ( m_arrayFull ? AVGFPS_MAX_TICK_VALUES : (m_tickId+1) ) );
    }

    double AvgFPS::getAvgTickPerFrame() const 
    {
        return m_lastAvg;
    }


    double AvgFPS::getAvgFramePerSecond() const
    {
        return 1000.0 / getAvgTickPerFrame();
    }





} // end namespace core


#endif /* FPS_H */