/* ---------------------------------------------------------------------------
** Texture.h
** 
** Texture
**
** Author: Gianluca
** -------------------------------------------------------------------------*/
#ifndef TEXTURE_H
#define TEXTURE_H

#include "core.h"
#include "NonCopyable.h"

namespace core 
{

    class Texture: public NonCopyable
    {
    public:

                        Texture( const std::string& filename, const RGB& key );
                        ~Texture();

        void            load();
        bool            isValid() const;
        void            draw( int x, int y, SDL_Rect* clip = NULL );

        void            setColor( const RGB& color );
        void            setBlendMode( SDL_BlendMode blending );
        void            setAlpha( Uint8 alpha );

        unsigned int    getW() const;
        unsigned int    getH() const;


    private:

        std::string         m_filename;
        RGB                 m_colorKey;
        SDL_Texture*        m_texture;
        unsigned int        m_w;
        unsigned int        m_h;
    };

} // end namespace core


#endif /* TEXTURE_H */