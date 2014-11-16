
/* ---------------------------------------------------------------------------
** Gem.h
** 
** gem in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GEM_H
#define GEM_H

#include "GridEntity.h"

namespace miner 
{
    enum GemType
    {
        K_GEMTYPE_CRYSTAL = 0,
        K_GEMTYPE_DIAMOND,
        K_GEMTYPE_RUBIN,
        K_GEMTYPE_TOPAZ
    };

    enum GemState
    {
        K_GEMTYPE_IDLE = 0,
        K_GEMTYPE_FALLING,
        K_GEMTYPE_DYING,
        K_GEMTYPE_DEAD
    };

    class Gem: public GridEntity
    {

    public:
                                Gem( unsigned int row, unsigned int col, unsigned int gemType = K_GEMTYPE_CRYSTAL )
                                : GridEntity( row, col, K_GAMELAYER_GEM ), 
                                  m_gemType( gemType ), m_dyningFrame(20), m_currentDyingFrame( 0 ) {}

        virtual                 ~Gem()                                          {}

        unsigned int            getGemType() const                              { return m_gemType; }
        unsigned int            getCurentDyingFrame() const                     { return m_currentDyingFrame; }


        void                    update();

    private:

      unsigned int    m_gemType;
      unsigned int    m_dyningFrame;
      unsigned int    m_currentDyingFrame;



    };


} // end namespace miner


#endif /* GEM_H */