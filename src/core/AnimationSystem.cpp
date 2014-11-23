/* ---------------------------------------------------------------------------
** AnimationSystem.cpp
** 
** Texture System
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#include "AnimationSystem.h"
#include "error_check.h"

namespace core 
{
    AnimationSystem::AnimationSystem()
    : m_animDescMap( )
    {

    }


    AnimationSystem::~AnimationSystem()
    {
        AnimDescPtrMapItC it = m_animDescMap.begin();
        AnimDescPtrMapItC it_end = m_animDescMap.end();
        for ( ; it != it_end ; ++it )
        {
            DEBUG_ASSERT( it->second != NULL )
            delete it->second;
        }
        m_animDescMap.clear();
    }


    void AnimationSystem::registerAnimation( const std::string& name, AnimationDesc* animDesc )
    {
        DEBUG_ASSERT( m_animDescMap.find( name ) == m_animDescMap.end() )
        if ( m_animDescMap.find( name ) == m_animDescMap.end() )
        {
            m_animDescMap.insert( std::make_pair(name, animDesc ));
        }
    }
    

    AnimationDesc* AnimationSystem::getAnimation( const std::string& name ) const
    {
        AnimDescPtrMapItC it = m_animDescMap.find( name );
        DEBUG_ASSERT( it != m_animDescMap.end() )
        if ( it != m_animDescMap.end() )
        {
            return it->second;
        }
        return NULL;
    }

}