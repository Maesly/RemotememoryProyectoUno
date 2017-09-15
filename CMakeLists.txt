cmake_minimum_required(VERSION 3.8)
project(RemotememoryProyectoUno)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp server.h server.cpp Estructura.h)
add_executable(RemotememoryProyectoUno ${SOURCE_FILES} server.h server.cpp)