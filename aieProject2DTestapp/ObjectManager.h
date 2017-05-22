#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "Gameobject.h"

class ObjectManager
{
public:
    ObjectManager();
    virtual ~ObjectManager();


    //ash's absolute directory code
    std::string getExecutableFolder() const;

    void addnewObj(Gameobject* incomingObj);
    //Gameobject* GetGameObj();
    std::string exePath;

protected:
    std::vector<Gameobject*> objectlist;



};

