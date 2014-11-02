/* ---------------------------------------------------------------------------
** Singleton.h
** 
** Singlenton Pattern
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef SINGLETON_H
#define SINGLETON_H

#include "core.h"

namespace core 
{
    template< class T >
    class Singleton
    {
    public:
        
        static T&       instance() 
                        { static std::auto_ptr<T> m_ptr(T::create()); return *(m_ptr.get()); }

    private:
                        Singleton<T>()                                          {}
                        Singleton & operator = (const Singleton & o)            { return o; }
                        ~Singleton()                                            {}
    };


} // end namespace core


#endif /* SINGLETON_H */