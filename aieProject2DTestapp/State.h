#pragma once
//set up so that update just calls this update
enum class states {initState, correctState, incorrectState, endState };
class State
{
public:
    
    State();
    virtual ~State();

  virtual void update() = 0;


};

