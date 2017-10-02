cmake_minimum_required(VERSION 3.8)
project(RemotememoryProyectoUno)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp server.h server.cpp Estructura.h Estructura.cpp lista.h)
add_executable(RemotememoryProyectoUno ${SOURCE_FILES} server.h server.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(RemotememoryProyectoUno ${GTK3_LIBRARIES})