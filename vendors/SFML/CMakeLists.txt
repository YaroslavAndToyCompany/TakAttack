set(SFML_BUILD_STATIC_LIBS ON)
set(SFML_BUILD_AUDIO OFF)
include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(SFML)

add_library(SFML INTERFACE)

target_link_libraries(SFML
    INTERFACE
    sfml-graphics
    sfml-window
    sfml-system
)