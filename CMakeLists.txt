cmake_minimum_required(VERSION 3.6)

project(freewb)

include ("set_environment.cmake")

add_subdirectory(src)
add_subdirectory(po)
add_subdirectory(data)
add_subdirectory(modules)