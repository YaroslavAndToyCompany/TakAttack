#include "Game/Engine.hpp"

int main() {
   
    Engine engine;
   
    while (!engine.GetWindowPtr()->IsDone()) {
        engine.HandleInput();
        engine.Update();
        engine.Render();
    }

}