#pragma once
#include "Export.h"
namespace Engine{
    class ENGINE_API Application{
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    Application* CreateApplication();
}