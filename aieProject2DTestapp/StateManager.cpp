#include "StateManager.h"




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
    
}

void StateManager::setState(States changeTo)
{
    switch (changeTo)
    {

    case States::START:
        // learn how to do this again
        //iterate through the vector till you find the stored state that corresponds to this state

        m_currState = findState(States::START);

        break;

    case States::PLAY:
        break;

    case::States::CORRECT:
        break;

    case States::INCORRECT:
        break;

    case States::GAMEOVER:
        break;


    default:
        break;
    }

    //change to the state
}

State* StateManager::getState()
{
    return m_currState;
}



State * StateManager::findState(States findstate)
{

        
    return nullptr;
}
