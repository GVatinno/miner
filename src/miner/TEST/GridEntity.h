
/* ---------------------------------------------------------------------------
** GridItem.h
** 
** It is an grid Entity
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GRID_ENTITY_H
#define GRID_ENTITY_H

#include "../miner.h"
#include <core/Entity.h>

namespace miner 
{
   class GridEntity: public Entity
   {

    public:
                                GridEntity( unsigned int row, unsigned int col, unsigned int layer = K_GAMELAYER_DEFAULT )
                                : Entity( col, row , layer ), m_row( row ), m_col( col ), m_state( 0 ) { }
                                

        virtual                 ~GridEntity()                                   {}

        virtual void            update()                                        { }

        virtual void            setRow( unsigned int row )                      { m_row = row; setPosY(row); }
        virtual unsigned int    getRow() const                                  { return m_row; }

        virtual void            setCol( unsigned int col )                      { m_col = col; setPosX(col); }
        virtual unsigned int    getCol() const                                  {return m_col; }

        virtual void            setRowOnly( unsigned int row )                  { m_row = row; }
        virtual void            setColOnly( unsigned int col )                  { m_col = col; }

        virtual void            setState( unsigned int s )                      { m_state = s; }
        virtual unsigned int    getState() const                                { return m_state; }

    private:

        unsigned int    m_row;
        unsigned int    m_col;
        unsigned int    m_state;
   };


} // end namespace miner


#endif /* GRID_ENTITY_H */