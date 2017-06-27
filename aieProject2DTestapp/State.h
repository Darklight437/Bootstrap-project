#pragma once

enum class states {initState, correctState, incorrectState, endState };
class State
{
public:

    State();
    virtual ~State();
};

