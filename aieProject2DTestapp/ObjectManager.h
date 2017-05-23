#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "Gameobject.h"
#include "SpriteObject.h"
#include "Texture.h"

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


    //main object for demo and 2 childeren
    void buildRootObject();
protected:
    std::vector<Gameobject*> objectlist;



};

