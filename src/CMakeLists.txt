add_executable(${CMAKE_PROJECT_NAME}
    Entities/Entity.cpp
    Game/Engine.cpp
    Game/Map.cpp
    Game/Window.cpp
    Managers/CursorManager.cpp
    Systems/InputSystem.cpp
    Systems/RenderSystem.cpp
    UI/Button.cpp
    UI/DebugPanel.cpp
    UI/MainMenu.cpp
    UI/View.cpp
    Utils/Screen.cpp
    main.cpp
)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")



if(UNIX)
    add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${CMAKE_CURRENT_SOURCE_DIR}/../res"
  "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/res"
  COMMENT "Copying resources to output directory"
)
endif()

