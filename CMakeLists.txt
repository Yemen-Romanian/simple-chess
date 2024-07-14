cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RESULT_BIN_DIR ${CMAKE_BINARY_DIR}/bin)
file(MAKE_DIRECTORY ${CMAKE_RESULT_BIN_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RESULT_BIN_DIR})

project(chess_game)

add_executable(chess_game main.cpp)

add_subdirectory(engine)
add_subdirectory(ui)

include_directories(ui/include)

target_link_libraries(chess_game chess_engine chess_ui)