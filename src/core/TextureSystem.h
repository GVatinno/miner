/* ---------------------------------------------------------------------------
** TextureSystem.h
** 
** Texture System
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#ifndef TEXTURE_SYSTEM_H
#define TEXTURE_SYSTEM_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{
    class TextureSystem: public NonCopyable
    {
    public:
                                ~TextureSystem();

        static TextureSystem*   create()                                            { return new TextureSystem(); }

        void                    registerTexture( const std::string& path, const std::string& name, const RGB& key );
        Texture*                getTexture( const std::string& name ) const;

    private:
                                TextureSystem();

        TexturePtrMap       m_textureMap;
    };

} // end namespace core


#endif /* TEXTURE_SYSTEM_H */