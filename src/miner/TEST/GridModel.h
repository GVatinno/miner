
/* ---------------------------------------------------------------------------
** GridModel.h
** 
** Implements the grid in the game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GRID_MODEL_H
#define GRID_MODEL_H

#include <core/NonCopyable.h>

namespace miner 
{

   enum GridState
   {
        K_GRIDSTATE_IDLE = 0,
        K_GRIDSTATE_LOADING, 
        K_GRIDSTATE_WAITING_FIRE,
        k_GRIDSTATE_FINDING_MATCHES,
        K_GRIDSTATE_DESTROYING_TILES,
        K_GRIDSTATE_CLEANUP_TILES,
        K_GRIDSTATE_SWAPPING_GEMS,
        K_GRIDSTATE_UPDATE_FALLING_GEMS,
        K_GRIDSTATE_REFILLING_GRID
   };

   class GridModel: private NonCopyable
   {

    //
    // Signal
    //
    typedef Signal1<const Entity*>                  EntitySignal;
    typedef Signal2<unsigned int, unsigned int>     BorderSignal;


    public:
                        GridModel( unsigned int rows , unsigned int cols, unsigned int moves );
                        ~GridModel();

        void            initializeGridRandom();
        void            update();

        EntitySignal    onGemCreated;
        EntitySignal    onTileCreated;
        BorderSignal    onBorderCreated;

        Gem*            createGem(unsigned int row, unsigned int col, unsigned type);
        Tile*           createTile(unsigned int row, unsigned int col, unsigned type);

        void            fireOnTile( unsigned int row, unsigned int col );
        bool            findMatch( unsigned int row, unsigned int col );

        void            updateDying();
        void            cleanUp();
        void            swapGem();
        void            updateFallingGems();


    private:

        const unsigned int    m_rows;
        const unsigned int    m_cols;
        unsigned int          m_moves;

        TileTablePtr          m_tiles;
        GemTablePtr           m_gems;
        GridState             m_state;

        friend class          MatchVisitor;
        friend class          SwapVisitor;
   };


} // end namespace miner


#endif /* GRID_MODEL_H */