/* ---------------------------------------------------------------------------
** Miner.h
** 
** Implementatation of the game Miner
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef MINER_GAME_H
#define MINER_GAME_H

#include "miner.h"
#include <core/Game.h>


namespace miner 
{
    class MinerGame : public Game
    {
    public:
                            ~MinerGame()                                        {}
        static MinerGame*   create()                                            { return new MinerGame(); }

        void                init();
        void                load();
        void                save();

                            MinerGame();

    };

} // end namespace miner


#endif /* MINER_GAME_H */