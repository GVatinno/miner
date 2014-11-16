/* ---------------------------------------------------------------------------
** miner.h
** 
** Forward declaration for classes in the miner and common include
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef MINER_H
#define MINER_H

//////// Third Party///////////
#include "3rdParty/Signal.h"
using namespace Gallant;
//////////////////////////////

#include <core/core.h>


using namespace core;

namespace miner
{
    //
    // Forward declarations
    //
    
    class MinerGame;
    class Tile;
    class Gem;
    class GridModel;
    class GridController;
    class GridView;
    class Matchvisitor;

    //
    // type definitions
    //

    typedef std::auto_ptr<MinerGame>        MinerGamePtr;

    typedef PointerTable<Tile*>             TileTable;
    typedef std::auto_ptr<TileTable>        TileTablePtr;

    typedef PointerTable<Gem*>              GemTable;
    typedef std::auto_ptr<GemTable>         GemTablePtr;

    typedef std::auto_ptr<GridModel>        GridModelPtr;
    typedef std::auto_ptr<GridController>   GridControllerPtr;
    typedef std::auto_ptr<GridView>         GridViewPtr;

    typedef std::auto_ptr<AnimatedSprite>   AnimatedSpritePtr;

    typedef std::vector<Gem*>               GemVector;
    typedef GemVector::iterator             GemVectorIt;
    typedef GemVector::const_iterator       GemVectorItC;

    typedef std::vector<Tile*>              TileVector;
    typedef std::set<const Gem*>            GemSetC;
    typedef std::deque<Point>               PointQueue;
    typedef std::deque<unsigned int>        IntQueue;
    

    
    

    


    enum GameLayer
    {
        K_GAMELAYER_DEFAULT = 0,
        K_GAMELAYER_BACKGROUND,
        K_GAMELAYER_TILE,
        K_GAMELAYER_GEM,
        K_GAMELAYER_GRID_BORDER,
    };


} // end namespace miner

#endif /* MINER_H */
