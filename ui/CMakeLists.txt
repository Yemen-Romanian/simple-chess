cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
project(chess_ui)

set(BUILD_SHARED_LIBS TRUE)
add_subdirectory(SFML)
add_subdirectory(fmt)

#modules for building
set(SFML_BUILD_GRAPHICS TRUE)
set(SFML_BUILD_WINDOW TRUE)
set(SFML_BUILD_NETWORK FALSE)
set(SFML_BUILD_AUDIO FALSE)

file(GLOB SOURCES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

file(COPY textures DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

include_directories(SFML/include)
include_directories(../engine/include)
include_directories(include)
include_directories(fmt/include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_RESULT_BIN_DIR})