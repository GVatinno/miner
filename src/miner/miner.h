/* ---------------------------------------------------------------------------
** miner.h
** 
** Forward declaration for classes in the miner and common include
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef MINER_H
#define MINER_H

#include <core/core.h>

using namespace core;

namespace miner
{
    //
    // Forward declarations
    //
    
    class MinerGame;

    //
    // type definitions
    //

    typedef std::auto_ptr<MinerGame>        MinerGamePtr;


} // end namespace miner
#endif /* MINER_H */
