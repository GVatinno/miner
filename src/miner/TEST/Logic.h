
/* ---------------------------------------------------------------------------
** Logic.h
** 
** Logic in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef LOGIC_H
#define LOGIC_H

#include "../miner.h"
#include <core/GridTraverser.h>


namespace miner 
{
    
    class MatchVisitor: public GridVisitor
    {
    public:
                MatchVisitor( const GridModel* gridModel, unsigned int seed );

        bool    visit( int x, int y );

        const GridModel*    m_gridModel;
        unsigned int        m_seed;
        unsigned int        m_matches;
        GemSetC             m_visited;
        GemVector           m_dying; 
    };


    class SwapVisitor: public GridVisitor
    {
    public:
                SwapVisitor( const GridModel* gridModel );

        bool    visit( int x, int y );

        const GridModel*    m_gridModel;
        IntQueue            m_rowHoleQueue;
    };

} // end namespace miner


#endif /* LOGIC_H */