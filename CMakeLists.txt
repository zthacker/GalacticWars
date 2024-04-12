cmake_minimum_required(VERSION 3.27)
project(GalacticWars)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x64)

set(SDL2_IMAGE_INCLUDE_DIR C:/libs/SDL_image/include)
set(SDL2_IMAGE_LIB_DIR C:/libs/SDL_image/lib/x64)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMAGE_LIB_DIR})

add_executable(GalacticWars main.cpp
        Game.h
        Game.cpp
        Components/Transform.h
        Math/Vec2.h
        Core/EntityManager.h
        Core/Types.h
        Core/ComponentArray.h
        Core/ComponentManager.h
        Core/System.h
        Core/SystemManager.h
        Core/Coordinator.h
        Systems/MovementSystem.h
        Systems/MovementSystem.cpp
        Components/Inputs.h
)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)
