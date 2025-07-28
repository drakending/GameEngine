#include "Engine.h"

class Editor: public Engine::Application{
public:
    Editor(){};
    ~Editor(){};
};

Engine::Application* CreateApplication(){
    return new Editor();
}