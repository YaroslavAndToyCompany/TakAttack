cmake_minimum_required(VERSION 3.22)
project(TakAttack LANGUAGES C CXX)

# Create compile-commands.file for intellsense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(vendors)
add_subdirectory(src)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Link necessary libraries ---
target_link_libraries(${CMAKE_PROJECT_NAME}
PRIVATE
SFML
EnTT::EnTT
)

# --- Handle build configurations ---
get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(is_multi_config)
    message(STATUS "Generator is multi config")
else()
    message(STATUS "Generator isn't multi config")
    
    if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        message(STATUS "Build mode: Debug")    
        set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -O0 -Wall")
    elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        message(STATUS "Build mode: Release")
        set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3 -DNDEBUG -Wall")
    endif()

    target_compile_definitions(TakAttack PRIVATE
        # If Debug mode is on, we define _DEBUG macros for c++
        $<$<CONFIG:DEBUG>:_DEBUG>

        # If Relese mode is on, we define NDEBUG macros for c++
        $<$<CONFIG:RELEASE>:NDEBUG>
    )
endif()

find_package(X11 QUIET)

if (X11_FOUND)
    target_link_libraries(${CMAKE_PROJECT_NAME}
        PRIVATE
        ${X11_LIBRARIES}
        Xrandr
    )
endif()