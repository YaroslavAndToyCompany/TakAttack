#include "Game/Engine.hpp"
#include <filesystem>

int main() {
    std::cout << "Current path is " << std::filesystem::current_path()
        << std::endl;
    Engine engine;
   
    

    while (!engine.GetWindowPtr()->IsDone()) {
        engine.HandleInput();
        engine.ProcessEvents();
        engine.Update();
        engine.Render();
    }

}