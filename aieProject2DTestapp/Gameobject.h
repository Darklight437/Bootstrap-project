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
    virtual ~Gameobject() = 0;

   



    Trasnsform Trasnform2D;
	virtual void draw(aie::Renderer2D* renderer);

	virtual void update(float deltaTime);
    
	void setname(std::string objectName);


 

 


protected:


    std::string m_name;
  
    

};