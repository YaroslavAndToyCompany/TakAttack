add_executable(TakAttack
	Debug/Debug.cpp
	Entities/Entity.cpp
	Game/Engine.cpp
	Game/Map.cpp
	Game/Window.cpp
	Managers/CursorManager.cpp
	Managers/ResourceManager.cpp
	Systems/InputSystem.cpp
	Systems/RenderSystem.cpp
	UI/Widgets/Button.cpp
	UI/Widgets/CheckBox.cpp
	UI/Widgets/Label.cpp
	UI/Widgets/ResizeSide.cpp
	UI/MainMenu.cpp
	UI/View.cpp
	Utils/Screen.cpp
	Utils/Utils.cpp
	Utils/Widgets.cpp
	main.cpp
)

add_dependencies(TakAttack copy_resources)
