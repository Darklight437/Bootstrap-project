#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Trasnsform.h"
#include <vector>
#include <string>


enum class GOType{spriteobject};

class Gameobject
{
public:
    Gameobject();
    ~Gameobject() ;


    Transform Transform2D;
	void draw(aie::Renderer2D* renderer);
    void setSprite(aie::Texture* texture);
    
	
	void setname(std::string objectName);


protected:

    aie::Texture* m_texture;
    std::string m_name;
  
};