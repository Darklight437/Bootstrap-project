#pragma once
#include "Gameobject.h"
class SpriteObject :
    public Gameobject
{
public:
    SpriteObject(aie::Texture* texture);
    virtual ~SpriteObject();

virtual void draw(aie::Renderer2D* renderer);

protected:
    aie::Texture* m_texture;


};

