
/* ---------------------------------------------------------------------------
** TileSprite.h
** 
** TileSprite in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef TILESPRITE__H
#define TILESPRITE__H

#include "../miner.h"
#include <core/Sprite.h>

namespace miner 
{

    class TileSprite: public Sprite
    {

    public:
                                TileSprite( const Entity* tile );

        virtual                 ~TileSprite()                                   {}

        virtual void            draw();

    private:

        const Entity*   m_tile;
    };


} // end namespace miner


#endif /* TILESPRITE__H */