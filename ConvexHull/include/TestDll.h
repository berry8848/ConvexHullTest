// DLLのエクスポートを指示するマクロ
#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

extern "C" EXPORT void TestDll();