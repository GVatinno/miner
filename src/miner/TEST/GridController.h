
/* ---------------------------------------------------------------------------
** GridController.h
** 
** Implements the grid in the game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GRID_CONTROLLER_H
#define GRID_CONTROLLER_H

#include "../miner.h"
#include <core/NonCopyable.h>


namespace miner 
{

   class GridController: private NonCopyable
   {
    public:
                        GridController( GridModel* model, GridView* view );
                        ~GridController();

        void            processInput(InputEvent& e);

        void            tileCreated( const Entity* e );
        void            gemCreated( const Entity* e );
        void            borderCreated( unsigned int x, unsigned int y );

    private:

        // not owned
        GridModel*      m_gridModel;
        GridView*       m_gridView;

   };


} // end namespace miner


#endif /* GRID_CONTROLLER_H */