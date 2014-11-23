
/* ---------------------------------------------------------------------------
** AnimatedSprite.h
** 
** AnimatedSprite
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "core.h"
#include "Sprite.h"

namespace core 
{

    class AnimatedSprite: public Sprite
    {

    public:
                                AnimatedSprite( const std::string& name, const std::string& animationDesc,
                                                unsigned int x = 0, unsigned int y =0, unsigned int layer = 0 );
                                
        virtual                 ~AnimatedSprite()                                       {}


        virtual void            next();
        virtual unsigned int    getCurrentClip() const                          { return m_currentClip; }


        virtual void            draw();

    private:

        unsigned int            m_currentClip;
        AnimationDesc*          m_animDesc;


    };


} // end namespace core


#endif /* ANIMATED_SPRITE_H */