
/* ---------------------------------------------------------------------------
** Gridtraverser.h
** 
** Gridtraverser in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "GridTraverser.h"
#include "error_check.h"

namespace core 
{

    DirectionalGridTraverser::DirectionalGridTraverser( GridDirection dir, GridVisitor* visitor,
                            unsigned int maxX, unsigned int maxY  )
    : m_direction( dir ), m_gridVisitor( visitor ), m_maxX( maxX ), m_maxY( maxY ),
      m_traversal( NULL )
    {
        DEBUG_ASSERT( visitor != NULL )
        switch ( m_direction )
        {
            case K_GRIDDIRECTION_LEFT:  m_traversal = &DirectionalGridTraverser::traverseLeft;    break;
            case K_GRIDDIRECTION_RIGHT: m_traversal = &DirectionalGridTraverser::traverseRight;   break;
            case K_GRIDDIRECTION_UP:    m_traversal = &DirectionalGridTraverser::traverseUp;      break;
            case K_GRIDDIRECTION_DOWN:  m_traversal = &DirectionalGridTraverser::traverseDown;    break;
        }
    }

    void DirectionalGridTraverser::traverse( int x , int y )
    {
        DEBUG_ASSERT( m_gridVisitor != NULL )
        (this->*m_traversal)( x, y );
    }

    void DirectionalGridTraverser::traverseLeft( int x , int y )
    {
        if ( m_gridVisitor->visit( x, y ) )
        {
            if ( y > 0 )
               traverseLeft( x, y-1 );
        }
    }
    
    void DirectionalGridTraverser::traverseRight( int x , int y )
    {
        if ( m_gridVisitor->visit( x, y ) )
        {
            if ( y < (int)m_maxY-1 )
                traverseRight( x, y+1 );
        }
    }

    void DirectionalGridTraverser::traverseUp( int x , int y )
    {
        if ( m_gridVisitor->visit( x, y ) )
        {
            if ( x > 0 )
                traverseUp( x-1, y );
        }
    }
    
    void DirectionalGridTraverser::traverseDown( int x , int y )
    {
        if ( m_gridVisitor->visit( x, y ) )
        {
            if ( x < (int)m_maxX -1 )
                traverseUp( x+1, y );
        }
    }


    //
    // GridTraverser
    //


    GridTraverser::GridTraverser( GridVisitor* visitor, unsigned int maxX, unsigned int maxY  )
    : m_gridVisitor( visitor ), m_maxX( maxX ), m_maxY( maxY )
    {
        DEBUG_ASSERT( visitor != NULL )
    }

    void GridTraverser::traverse( int x , int y )
    {
        if ( m_gridVisitor->visit( x, y ) )
        {
            traverseLeft(x,y);
            traverseRight(x,y);
            traverseUp(x,y);
            traverseDown(x,y);
        }
    }

    void GridTraverser::traverseLeft( int x , int y )
    {
        if ( y > 0 )
           traverse( x, y-1 );
    }
    
    void GridTraverser::traverseRight( int x , int y )
    {
        if ( y < (int)m_maxY-1 )
            traverse( x, y+1 );
    }

    void GridTraverser::traverseUp( int x , int y )
    {
        if ( x > 0 )
            traverse( x-1, y );
    }
    
    void GridTraverser::traverseDown( int x , int y )
    {
        if ( x < (int)m_maxX -1 )
            traverse( x+1, y );
    }

} // end namespace core