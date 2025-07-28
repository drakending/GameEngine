#pragma once
#include "Application.h"
extern Engine::Application* CreateApplication();
#ifdef WIN32
int main(int argc, char** argv){
    auto app = CreateApplication();
    app->Run();
    delete app;
}
#endif