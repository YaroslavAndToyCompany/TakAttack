add_executable(TakAttack
    Entities/Entity.cpp
    Game/Engine.cpp
    Game/Map.cpp
    Game/Window.cpp
    Managers/CursorManager.cpp
    Systems/InputSystem.cpp
    Systems/RenderSystem.cpp
    UI/Widgets/Button.cpp
    UI/Widgets/CheckBox.cpp
    UI/DebugPanel.cpp
    UI/MainMenu.cpp
    UI/View.cpp
    Utils/Screen.cpp
    Utils/Utils.cpp
    Utils/Widgets.cpp
    main.cpp
)

add_dependencies(TakAttack copy_resources)