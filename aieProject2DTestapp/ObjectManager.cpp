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