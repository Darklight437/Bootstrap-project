#pragma once
#include <string>
#include <Windows.h>
#include <vector>

class ObjectManager
{
public:
    ObjectManager();
    virtual ~ObjectManager();


    //ash's absolute directory code
    std::string getExecutableFolder() const;

    void addnewObj(Gameobject*);

    std::string exePath;

protected:
    std::vector<Gameobject*> objectlist;



};

