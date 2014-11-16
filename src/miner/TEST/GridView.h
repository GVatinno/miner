
/* ---------------------------------------------------------------------------
** GridView.h
** 
** GridView
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GRID_VIEW_H
#define GRID_VIEW_H

#include "../miner.h"
#include <core/NonCopyable.h>
#include <core/Sprite.h>


namespace miner 
{

   class GridView: public NonCopyable
   {


    public:
                        GridView();
                        ~GridView();

        void            addDecoration( Decoration* decoration );

        void            draw();

    private:

      DecorationVector    m_decorationVector;

   };


} // end namespace miner


#endif /* GRID_VIEW_H */