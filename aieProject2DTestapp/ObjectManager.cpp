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

void ObjectManager::addnewObj(SpriteObject* incomingObj)
{
    if (incomingObj != nullptr)
    {
        objectlist.push_back(incomingObj);
    }
}

void ObjectManager::buildRootObject()
{
   SpriteObject* rootObject = new SpriteObject;
   addnewObj(rootObject);
   rootObject->setname("testcar");
   SpriteObject* child1 = new SpriteObject;
   addnewObj(child1);
   child1->setname("randomball");
   rootObject->addChild(child1);

}

//Gameobject * ObjectManager::GetGameObj()
//{
//
//    return nullptr;
//}
