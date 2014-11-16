
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
                                AnimatedSprite( const std::string& name, unsigned int spriteRow, unsigned int spriteCol,
                                                unsigned int x = 0, unsigned int y =0, unsigned int layer = 0 );
                                
        virtual                 ~AnimatedSprite()                                       {}


        virtual void            next();


        virtual void            draw();

    private:

        unsigned int            m_spriteRow;
        unsigned int            m_spriteCol;
        unsigned int            m_currentRow;
        unsigned int            m_currentCol;
        RectVector              m_frames;
        unsigned int            m_currentClip;


    };


} // end namespace core


#endif /* ANIMATED_SPRITE_H */