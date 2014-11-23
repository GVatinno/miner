/* ---------------------------------------------------------------------------
** AnimationSystem.h
** 
** Texture System
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#ifndef ANIMATION_SYSTEM_H
#define ANIMATION_SYSTEM_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{
    
    struct AnimationDesc
    {
        unsigned int frameDuration;
        RectVector   frameDesc;
    };

    class AnimationSystem: public NonCopyable
    {
    public:
                                ~AnimationSystem();

        static AnimationSystem* create()                                        { return new AnimationSystem(); }

        void                    registerAnimation( const std::string& name, AnimationDesc* animDesc );
        AnimationDesc*          getAnimation( const std::string& name ) const;

    private:
                                AnimationSystem();

        AnimDescPtrMap          m_animDescMap;
    };

} // end namespace core


#endif /* ANIMATION_SYSTEM_H */