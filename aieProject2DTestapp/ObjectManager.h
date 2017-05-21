#pragma once
#include <string>
#include <Windows.h>

class ObjectManager
{
public:
    ObjectManager();
    virtual ~ObjectManager();


    //ash's absolute directory code
    std::string getExecutableFolder() const;


    std::string exePath;




};

