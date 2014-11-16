
/* ---------------------------------------------------------------------------
** Sprite.h
** 
** Sprite
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#ifndef SPRITE_H
#define SPRITE_H

#include "core.h"
#include "Decoration.h"

namespace core 
{

    class Sprite: public Decoration
    {

    public:
                                Sprite( const std::string& name, unsigned int x = 0, unsigned int y =0, unsigned int layer = 0 );
                                
        virtual                 ~Sprite()                                       {}

        void                    setTextureName( const std::string& name )       { m_textureName = name; }
        const std::string&      getTextureName() const                          { return m_textureName; }

        Texture*                getTexture() const;

        virtual void            draw();

    private:

        std::string             m_textureName;

    };


} // end namespace core


#endif /* SPRITE_H */