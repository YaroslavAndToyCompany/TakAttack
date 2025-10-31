add_executable(TakAttack
	Debug/Debug.cpp
	Entities/Entity.cpp
	Game/Engine.cpp
	Game/Map.cpp
	Game/Window.cpp
	Managers/CursorManager.cpp
	Managers/EventManager.cpp
	Managers/ResourceManager.cpp
	Systems/InputSystem.cpp
	Systems/RenderSystem.cpp
	Systems/UISystem.cpp
	UI/Elements/Circle.cpp
	UI/Widgets/Buttons/ButtonDefault.cpp
	UI/Widgets/Buttons/ButtonSprite.cpp
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
