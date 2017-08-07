
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <Windows.h>


HANDLE g_hMutex = INVALID_HANDLE_VALUE; //this is a win32 mutex oject essentially a key that is traded between multiple processes (this applies to multi-threading too)
HANDLE g_hFileMapping = NULL;           //a handle to a memory-wrapped file object, i.e. shared memory
void *g_pSharedMemory = NULL;           //A pointer to a block of shared memory backed by a memory wrapped file

void createMutex()
{
    g_hMutex = CreateMutex(NULL, FALSE, "Mutex_Alpha");
    if (g_hMutex == NULL)
    {
        throw "createMutex failed";
    }

}


void destroyMutex()
{
    CloseHandle(g_hMutex);
    g_hMutex = INVALID_HANDLE_VALUE;
}

bool getMutexOwnership()
{
    //there is a timeout option on getting the mutex, this is used for network stuff more than local transfer
    //the program cant continue while it is waiting for the mutex
    //so having a timeout can allow the program to get along with anything else it could be doing without the mutex
    //in this example we will check every frame/loop so the timeout will be instant
    DWORD timeoutMilliseconds = 0;
    switch (WaitForSingleObject(g_hMutex, timeoutMilliseconds))
    {
    case WAIT_OBJECT_0:
        //mutex is owned by this object
        return true;

    case WAIT_TIMEOUT:
        //a timeout means that the mutex is currently held by another process
        return false;

    case WAIT_ABANDONED:
        //this means that another process owns the mutex but that process has terminated
        //without releasing the mutex therefore all manner of oddness has occured
        throw "waitForSingleObject abandoned";

    case WAIT_FAILED:
        throw "WaitForSingleObject failed";



    default:
        throw "Unknown Wait Code";
    };
}

void releaseMutexOwnership()
{
    if (!ReleaseMutex(g_hMutex))
    {
        throw "ReleaseMutex failed";
    }
}


void createSharedMemory(const char *name, unsigned numBytes)
{

    //create a file mapping object
    g_hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, numBytes, name);
    if (g_hFileMapping == NULL)
    {
        throw "CreateMappingFile failed";
    }

    //creating a 'view' into the shared mapping
    //a view is effectively a block of memory that has been backed up by the system paging file
    //using the pointer to access the block of data when allowed by the mutex
    g_pSharedMemory = MapViewOfFile(g_hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, numBytes);
    if (!g_pSharedMemory)
    {
        throw "MapViewOfFile failed";
    }

}

void releaseSharedMemory()
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

bool gameloopQuestionnaire()
{
    int input;
    std::cout << "=======================================================";
    std::cout << "WELCOME TO THE WONDEROUS QUESTIONNAIRE!";
    std::cout << "=======================================================";


    std::cout << "awnser 1 to prove the game isnt broken or dont, i'm just a console not a cop";
    std::cin >> input;

    switch (input)
    {

    case 1:
    {
        std::cout << "heyy everything is working as intended right main screen?";
        return true;
    }



    default:
    {
        std::cout << "invalid input this probably broke something";
        return false;
    }
}


}




int main()
{

    try
    {

        //other process will poll for mutex when it recieves it it will read a shared memory block that has one bool
        //the bool will setermine if the awnser was correct or not
        //ask a bunch of binary question with either 2 option multiple choice or yes or no questions
        createSharedMemory("yesNo Memory", 1000);
        getMutexOwnership();

        bool tempBool = gameloopQuestionnaire();
        




        _getch();
    }
    





    catch (const char *e)
    {
        std::cout << "EXCEPTION - " << e << "\n\n";
        system("pause");
    }

    return 0;
}