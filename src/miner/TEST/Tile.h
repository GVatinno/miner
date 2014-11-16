
/* ---------------------------------------------------------------------------
** Tile.h
** 
** Tile in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef TILE__H
#define TILE__H

#include "GridEntity.h"

namespace miner 
{
    enum TileType
    {
        K_TILETYPE_STANDARD = 0
    };

    class Tile: public GridEntity
    {

    public:
                                Tile( unsigned int row, unsigned int col, unsigned int tileType = K_TILETYPE_STANDARD )
                                : GridEntity( row, col, K_GAMELAYER_GEM ), m_tileType( tileType ) {}

        virtual                 ~Tile()                                          {}

        unsigned int            getTileType() const                              { return m_tileType; }

    private:

      unsigned int              m_tileType;

    };


} // end namespace miner


#endif /* TILE__H */