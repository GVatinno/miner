
/* ---------------------------------------------------------------------------
** GemSprite.h
** 
** GemSprite in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GEM_SPRITE__H
#define GEM_SPRITE__H

#include "../miner.h"
#include <core/Sprite.h>

namespace miner 
{

    class GemSprite: public Sprite
    {

    public:
                                GemSprite( const Entity* gem );

        virtual                 ~GemSprite()                                   {}

        virtual void            draw();

    private:

        const Gem*          m_gem;
        AnimatedSpritePtr   m_dyingSprite;
        Uint8               m_dyingAlpha;
    };


} // end namespace miner


#endif /* GEM_SPRITE__H */