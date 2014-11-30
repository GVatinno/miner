/* ---------------------------------------------------------------------------
** Factory.h
** 
** Factory Pattern
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef FACTORY_H
#define FACTORY_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{
    template< class T >
    class Factory : private NonCopyable
    {
    public:
        
        typedef T* (*Creator)(const std::string& name);
        typedef typename std::map<std::string, Creator >        CreatorMap;
        typedef typename CreatorMap::iterator                   CreatorMapIt;
        typedef typename CreatorMap::const_iterator             CreatorMapItC;

                        Factory();
        virtual         ~Factory()                                              {}
        
        T*              create( const std::string& name ) const;
        void            registerCreator(const std::string& typeName, Creator creator );

    private:
        

        CreatorMap  m_creatorMap; 
    };

    //
    // Factory definition
    //

    template< class T >
    Factory<T>::Factory()
    : m_creatorMap()
    {
    }


    template< class T >
    T* Factory<T>::create( const std::string& name ) const
    {
        CreatorMapItC it = m_creatorMap.find( name );
        if ( it != m_creatorMap.end() )
        {
            return it->second(name);
        }
        return NULL;
    }


    template< class T >
    void Factory<T>::registerCreator(const std::string& typeName, Creator creator )
    {
        CreatorMapIt it = m_creatorMap.find( typeName );
        if ( it == m_creatorMap.end() )
        {
            m_creatorMap.insert(std::make_pair( typeName, creator ));
        }
    }

    


} // end namespace core


#endif /* FACTORY_H */