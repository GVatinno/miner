
/* ---------------------------------------------------------------------------
** Gridtraverser.h
** 
** Gridtraverser in the grid
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef GRID_TRAVERSER_H
#define GRID_TRAVERSER_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{

    enum GridDirection
    {
        K_GRIDDIRECTION_LEFT = 0,
        K_GRIDDIRECTION_RIGHT,
        K_GRIDDIRECTION_UP,
        K_GRIDDIRECTION_DOWN
    };

    
    class GridVisitor : public NonCopyable
    {
    public:
        virtual bool visit( int x, int y ) = 0;
    };


    class DirectionalGridTraverser: public NonCopyable
    {
    public:
                DirectionalGridTraverser( GridDirection dir, GridVisitor* visitor,
                            unsigned int maxX, unsigned int maxY );

                ~DirectionalGridTraverser()                                     { }

        void    traverse( int x , int y );

    private:

        typedef void (DirectionalGridTraverser::*Traversal)( int x, int y );

        void    traverseLeft( int x , int y );
        void    traverseRight( int x , int y );
        void    traverseUp( int x , int y );
        void    traverseDown( int x , int y );


    private:

        GridDirection               m_direction;
        GridVisitor*                m_gridVisitor;
        const unsigned int          m_maxX;
        const unsigned int          m_maxY;
        Traversal                   m_traversal;

    };


    class GridTraverser: public NonCopyable
    {
    public:
                GridTraverser( GridVisitor* visitor,
                            unsigned int maxX, unsigned int maxY );

                ~GridTraverser()                                                { }

        void    traverse( int x , int y );

    private:

        void    traverseLeft( int x , int y );
        void    traverseRight( int x , int y );
        void    traverseUp( int x , int y );
        void    traverseDown( int x , int y );


    private:

        GridDirection           m_direction;
        GridVisitor*            m_gridVisitor;
        const unsigned int      m_maxX;
        const unsigned int      m_maxY;

    };

} // end namespace core


#endif /* GRID_TRAVERSER_H */