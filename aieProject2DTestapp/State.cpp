#include "State.h"



State::State()
{
    correctSprite = new aie::Texture((getExecutableFolder() + "/textures/YES.png").c_str());
    inCorrectSprite = new aie::Texture((getExecutableFolder() + "/textures/NO.png").c_str());
    welcomeSprite = new aie::Texture((getExecutableFolder() + "/textures/Youkoso1.png").c_str());
}


State::~State()
{
    delete correctSprite;
    delete inCorrectSprite;
}

std::string State::getExecutableFolder() const
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