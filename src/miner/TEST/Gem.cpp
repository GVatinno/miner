
/* ---------------------------------------------------------------------------
** Gem.h
** 
** gem in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/


#include "Gem.h"


namespace miner
{

    void Gem::update()
    {
        if ( getState() == K_GEMTYPE_DYING )
        {
            if ( m_currentDyingFrame < m_dyningFrame )
                ++m_currentDyingFrame;
            else
                setState( K_GEMTYPE_DEAD );
        }
        else
        if ( getState() == K_GEMTYPE_FALLING )
        {
            if ( (float)getRow() > getPosY() )
            {
                setPosY( getPosY() + 0.2 );
            }
            else
            {
                 setRow( getRow() );
                 setState(K_GEMTYPE_IDLE);
            }
        }
        
    }

}