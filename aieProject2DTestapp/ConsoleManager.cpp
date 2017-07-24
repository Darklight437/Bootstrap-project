#include "ConsoleManager.h"



ConsoleManager::ConsoleManager()
{
    startup();
}


ConsoleManager::~ConsoleManager()
{
    releaseSharedMemory();
    destroyMutex();
}

void ConsoleManager::startup()
{
    //set everything that needs to be set up so main can loop
    createMutex();
    createSharedMemory("Foo Memory", 10000);
}

void ConsoleManager::createMutex()
{

    g_hMutex = CreateMutex(NULL, FALSE, "Mutex_Alpha");
    if (g_hMutex == NULL)
        throw "CreateMutex failed";
}

void ConsoleManager::destroyMutex()
{
    CloseHandle(g_hMutex);
    g_hMutex = INVALID_HANDLE_VALUE;
}

bool ConsoleManager::getMutexOwnership()
{
    DWORD timeoutMilliseconds = 0;
    switch (WaitForSingleObject(g_hMutex, timeoutMilliseconds))
    {
    case WAIT_OBJECT_0:
        // Mutex is now owned by this process
        return true;

    case WAIT_TIMEOUT:
        // A timeout means that the mutex is currently owned by some other process
        return false;

    case WAIT_ABANDONED:
        // This means that another process owns the mutX but that process terminated 
        // without releasing the mutex. It may therefore be in an inconsistent state.
        throw "WaitForSingleObject abandoned";

    case WAIT_FAILED:
        throw "WaitForSingleObject failed";

    default: throw "Unknown wait result";
    };

}

void ConsoleManager::releaseMutexOwnership()
{
    if (!ReleaseMutex(g_hMutex))
        throw "ReleaseMutex failed";
}

void ConsoleManager::createSharedMemory(const char * name, unsigned numBytes)
{
    // Create a file mapping object
    g_hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, numBytes, name);
    if (g_hFileMapping == NULL)
    {
        throw "CreateFileMapping failed";
    }

    // Create a 'view' into the file mapping. The view is effectivel a block of
    // memory backed up by the system paging file.
    g_pSharedMemory = MapViewOfFile(g_hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, numBytes);
    if (!g_pSharedMemory)
    {
        throw "MapViewOfFile failed";
    }
}

void ConsoleManager::releaseSharedMemory()
{
    if (g_pSharedMemory)
    {
        if (UnmapViewOfFile(g_pSharedMemory))
        {
            g_pSharedMemory = nullptr;
        }
        else
        {
            throw "UnmapViewOfFile failed";
        }
    }

    if (g_hFileMapping)
    {
        CloseHandle(g_hFileMapping);
        g_hFileMapping = NULL;
    }
}

bool ConsoleManager::run()
{
    //will play every frame to prevent game hanging




    try
    {



        //if the consle returns true so will this function


        if (!mutexOwned)
        {

            //attempt to get mutex
            //check here once per frame
            if (!getMutexOwnership())
            {

               
            }
            
        }


    }
    catch (const char *e)
    {
        system("pause");
    }

}
