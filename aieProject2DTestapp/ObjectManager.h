#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "Gameobject.h"
#include "SpriteObject.h"
#include "Texture.h"
#include "Matrix3.h"
class ObjectManager
{
public:
    ObjectManager();
    virtual ~ObjectManager();


    //ash's absolute directory code
    std::string getExecutableFolder() const;

    void addnewObj(SpriteObject* incomingObj);
    //Gameobject* GetGameObj();
    std::string exePath;
    //vector containing all game objects
    std::vector<Gameobject*> objectlist;


    //main object for demo and 2 childeren
    void buildRootObject();
protected:
   



};

