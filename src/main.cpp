#include "Engine.h"

int main() {
   
    Engine engine;
   
    while (!engine.GetWindowPtr()->IsDone()) {
        engine.HandleInput();
        engine.Update();
        engine.Render();
    }

}