#pragma once

#include "Gameobject.h"
#define FACTORY ObjectFactory::getInstance()


//singleton

class ObjectFactory
{
public:

    static ObjectFactory *getInstance();

    Gameobject *makeGameObject(GOType);




private:
    ObjectFactory();
    ~ObjectFactory();
};

