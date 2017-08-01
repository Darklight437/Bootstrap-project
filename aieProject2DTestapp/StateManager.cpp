#include "StateManager.h"
#include "State.h"
#include "StartState.h"
#include "PlayState.h"
#include "CorrectState.h"
#include "IncorrectState.h"
#include "GameOverState.h"


StateManager::StateManager()
{
    //create one of each state here and store a pointer of it in the vector
    State* p_startState = new StartState;
    stateVect.push_back(p_startState);

    State* p_playState = new PlayState;
    stateVect.push_back(p_playState);

    State* p_correctState = new CorrectState;
    stateVect.push_back(p_correctState);

    State* p_incorrectState = new IncorrectState;
    stateVect.push_back(p_incorrectState);

    m_currState = nullptr;
}


StateManager::~StateManager()
{
    std::vector<State*>::iterator It;

    for (It = stateVect.begin(); It != stateVect.end(); It++)
    {
        delete *It;
    }
}

void StateManager::setState(States changeTo)
{
    switch (changeTo)
    {

    case States::START:
        
        m_currState = findState(States::START);
        break;

    case States::PLAY:
        m_currState = findState(States::PLAY);
        break;

    case States::CORRECT:
        m_currState = findState(States::CORRECT);
        break;

    case States::INCORRECT:
        m_currState = findState(States::INCORRECT);
        break;

    case States::GAMEOVER:
        m_currState = findState(States::GAMEOVER);

        break;


    default:
         
        //an error lives here
        break;
    }


}

State* StateManager::getState()
{
    return m_currState;
}



State* StateManager::findState(States findstate)
{
    std::vector<State*>::iterator It;
    

        for (It  = stateVect.begin(); It != stateVect.end(); It++)
        {
            if ((*It)->ID == findstate)
            {
                break;
            }
        }
        if (It != stateVect.end())
        {
            return *It;
        }
        
        
    return nullptr;
}
