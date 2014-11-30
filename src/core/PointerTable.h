/* ---------------------------------------------------------------------------
** PointerTable.h
** 
** 2d table of pointers
**
** Author: Gianluca
** -------------------------------------------------------------------------*/


#ifndef POINTER_TABLE_H
#define POINTER_TABLE_H

#include "NonCopyable.h"
#include "error_check.h"

namespace core
{

    template<class T>
    class PointerTable : private NonCopyable
    {
    public:

                    PointerTable( unsigned int x, unsigned int y, bool ownPtrs = true );
                    ~PointerTable();

        T&          getAt( unsigned int x, unsigned int y );
        const T&    getAt( unsigned int x, unsigned int y ) const;
        T&          getAt( unsigned int i );
        const T&    getAt( unsigned int i ) const;


     private:

        const unsigned int  m_x;
        const unsigned int  m_y;
        const unsigned int  m_total;
        const bool          m_ownPtrs;
        T*                  m_table;

    };


    template<class T>
    PointerTable<T>::PointerTable( unsigned int x, unsigned int y, bool ownPtrs )
    : m_x( x ), m_y( y), m_total( x*y ), m_ownPtrs( ownPtrs ), m_table( new T[x*y] )
    {
        for ( unsigned int i =0; i < m_total; ++i )
        {
             m_table[i] = NULL;
        }
    }


    template <class T>
    T& PointerTable<T>::getAt( unsigned int x, unsigned int y )
    {
         DEBUG_ASSERT( x < m_x || x > 0 );
         DEBUG_ASSERT( y < m_y || y > 0 );
         return m_table[y*m_x+x];
    }

    template <class T>
    T& PointerTable<T>::getAt( unsigned int i )
    {
        DEBUG_ASSERT( i >= 0 );
        DEBUG_ASSERT( i < m_total );
        return m_table[i];
    }

    template <class T>
    const T& PointerTable<T>::getAt( unsigned int i ) const
    {
        return getAt(i);
    }
    


    template<class T>
    PointerTable<T>::~PointerTable()
    {
         if ( m_table == NULL )
             return;
         
         if ( m_ownPtrs )
         {
            for ( unsigned int i =0; i < m_total; ++i )
            {
                if ( m_table[i] )
                    delete m_table[i];
            }
         }
         delete [] m_table;
         m_table = NULL;
    }


} // end namespace core


#endif /* POINTER_TABLE_H */