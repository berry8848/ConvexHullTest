#ifdef _WIN32
    #define EXPORT __declspec(dllimport)
#else
    #define EXPORT
#endif

#include <iostream>
#include <string>
#include "TestDll.h"

int main()
{
	TestDll();
	return 0;
}