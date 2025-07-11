cmake_minimum_required(VERSION 3.6)

project(freewb)

include ("set_environment.cmake")

option(ENABLE_FCITX4 "enable fcitx4 addon" ON)
option(ENABLE_FCITX5 "enable fcitx5 addon" OFF)
option(ENABLE_IBUS "enable ibus addon" OFF)
option(ENABLE_TSF "enable tsf addon" OFF)

add_subdirectory(src)
add_subdirectory(po)
add_subdirectory(data)
add_subdirectory(modules)