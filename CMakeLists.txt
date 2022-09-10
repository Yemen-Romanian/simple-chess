cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)

project(sfml-example)

set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(SFML)

#modules for building
set(SFML_BUILD_GRAPHICS TRUE)
set(SFML_BUILD_WINDOW TRUE)
set(SFML_BUILD_NETWORK FALSE)
set(SFML_BUILD_AUDIO FALSE)

add_executable(${PROJECT_NAME} main.cpp)
include_directories(SFML/include)

target_link_libraries(sfml-example sfml-graphics sfml-window)