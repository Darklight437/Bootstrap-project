#pragma once
#include "Gameobject.h"
#include <string>
class SpriteObject :
    public Gameobject
{
public:
    SpriteObject();
    SpriteObject(aie::Texture* texture);
    virtual ~SpriteObject();


    void setSprite(aie::Texture* texture);
    virtual void draw(aie::Renderer2D* renderer);

protected:
    aie::Texture* m_texture;


};

