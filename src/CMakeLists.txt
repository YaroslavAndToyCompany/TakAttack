add_executable(${CMAKE_PROJECT_NAME}
    UI/Button.cpp
    UI/DebugPanel.cpp
    UI/MainMenu.cpp
    Engine.cpp
    Entity.cpp
    InputSystem.cpp
    main.cpp
    Map.cpp
    Window.cpp
)

add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${CMAKE_CURRENT_SOURCE_DIR}/../res"
  "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/res"
  COMMENT "Copying resources to output directory"
)