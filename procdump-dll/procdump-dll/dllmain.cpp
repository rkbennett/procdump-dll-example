// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>


using namespace std;

extern "C" __declspec(dllexport) void MiniDumpCallbackRoutine(void)
{
    CHAR czTempPath[MAX_PATH] = { 0 };
    GetTempPathA(MAX_PATH, czTempPath); // retrieving temp path
    cout << czTempPath << endl;

    string sPath = czTempPath;
    sPath += "test.txt"; // adding my test.txt

    ofstream test;
    test.open(sPath.c_str());
    test << "This is a test" << std::endl;
    test.close();

    //system(sPath.c_str());
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MiniDumpCallbackRoutine();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
