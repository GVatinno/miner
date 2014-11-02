/* ---------------------------------------------------------------------------
** Event.h
** 
** Event 
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef EVENT_H
#define EVENT_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{
    template< class T >
    class Event : public NonCopyable
    {
    public:
                        Event( const T& e) : m_event(e), m_consumed(false)      {}
        virtual         ~Event()                                                {}

        const T&        getEvent() const                                        { return m_event; }

        void            setConsumed( bool c)                                    { m_consumed = true; }
        bool            getConsumed() const                                     { return m_consumed; }

    private:
        
        const T&    m_event;
        bool        m_consumed;
        
    };

    //
    // Event definition
    //


} // end namespace core


#endif /* EVENT_H */