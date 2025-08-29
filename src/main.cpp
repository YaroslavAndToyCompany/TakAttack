#include "Game/Engine.hpp"

int main() {
   
    Engine engine;
   
    while (!engine.GetWindowPtr()->IsDone()) {
        engine.HandleInput();
        engine.ProcessEvents();
        engine.Update();
        engine.Render();
    }

}