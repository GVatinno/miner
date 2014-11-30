/* ---------------------------------------------------------------------------
** FontSystem.h
** 
** Font System
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#ifndef FONT_SYSTEM_H
#define FONT_SYSTEM_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{
    class FontSystem: private NonCopyable
    {
    public:
                                ~FontSystem();

        static FontSystem*      create()                                        { return new FontSystem(); }

        void                    registerFont( const std::string& path, const std::string& name, unsigned int fontSize );
        TTF_Font*               getFont( const std::string& name ) const;

    private:
                                FontSystem();

        FontPtrMap              m_fontMap;
    };

} // end namespace core


#endif /* FONT_SYSTEM_H */