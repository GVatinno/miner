/* ---------------------------------------------------------------------------
** error_check.h
** 
** Utility for handling errors and asserts
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef ERROR_CHECK_H
#define ERROR_CHECK_H

#include <stdio.h>
#include <assert.h>

#define PRINT_WHERE()                                                           \
     printf( "\tin file %s line %d\n", __FILE__, __LINE__ );                    \


#define PRINT_ERROR(msg, desc)                                                  \
    printf( "ERROR -> %s: %s \n", msg, desc);                                   \
    PRINT_WHERE()                                                               \


#define PRINT_WARNING(msg, desc)                                                \
    printf( "WARNING -> %s: %s \n", msg, desc);                                 \
    PRINT_WHERE()                                                               \

#ifdef _DEBUG 

#define DEBUG_ASSERT( condition )                                               \
    assert(condition);                                                          \

#define DEBUG_MSG( msg )                                                        \
    printf( "DEBUG: %s \n", msg);                                               \

#else

#define DEBUG_ASSERT( condition )
#define DEBUG_MSG( msg )

#endif                                                                          \


namespace core
{


} // end namespace core

#endif /* ERROR_CHECK_H */
