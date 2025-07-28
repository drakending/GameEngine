
#pragma once
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else
#define ENGINE_API __attribute__((visibility("default")))
#endif
#ifdef _WIN32
#define ENGINE_CALL __stdcall
#else
#define ENGINE_CALL
#endif
