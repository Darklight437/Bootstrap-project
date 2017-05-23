#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
    exePath = getExecutableFolder();
}


ObjectManager::~ObjectManager()
{
}

std::string ObjectManager::getExecutableFolder() const
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    char *pos;
    if (pos = strrchr(buffer, '\\'))
    {
        *pos = 0;
    }

    return buffer;
}

void ObjectManager::addnewObj(Gameobject* incomingObj)
{
    if (incomingObj != nullptr)
    {
        objectlist.push_back(incomingObj);
    }
}

Gameobject ObjectManager::buildRootObject()
{
   Gameobject* rootObject = new Gameobject;
   addnewObj(rootObject);

   Gameobject* child1 = new Gameobject;
   addnewObj(child1);

   rootObject->addChild(child1);

    return Gameobject();
}

//Gameobject * ObjectManager::GetGameObj()
//{
//
//    return nullptr;
//}
