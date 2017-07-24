#pragma once
#include <string>
#include <conio.h>
#include <Windows.h>
class ConsoleManager
{
public:
    //basic process
    //=====================================================================================================//
    //=====================================================================================================//
    //make a new console manager, start polling for the mutex
    //when the mutex is owned read the shared bool and output the result to the current state
    //immediatley hand off the mutex to the console so it can write the memory


    ConsoleManager();
    ~ConsoleManager();

    struct consoleResults
    {
        bool gotResult = false;
        bool consoleResult = false;
    } console;
    

    HANDLE g_hMutex = INVALID_HANDLE_VALUE;
    HANDLE g_hFileMapping = NULL;
    void *g_pSharedMemory = NULL;
    bool mutexOwned = false;

    void startup();

    void createMutex();

    void destroyMutex();

    bool getMutexOwnership();

    void releaseMutexOwnership();

    void createSharedMemory(const char *name, unsigned numBytes);

    void releaseSharedMemory();

    consoleResults run();




};

