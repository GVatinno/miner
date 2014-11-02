/* ---------------------------------------------------------------------------
** NonCopyable.h
** 
** Non copiable base class
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H

namespace core 
{

    class NonCopyable
    {
    protected:
                NonCopyable ()                                            {}
                ~NonCopyable ()                                           {} /// Protected non-virtual destructor
    private: 
                NonCopyable (const NonCopyable &);
                NonCopyable & operator = (const NonCopyable &);
    };


} // end namespace core


#endif /* NON_COPYABLE_H */