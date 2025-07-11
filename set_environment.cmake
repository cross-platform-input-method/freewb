cmake_minimum_required(VERSION 3.6)

# os type
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(OS_TYPE "linux")
    add_definitions(-D__LINUX__)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(OS_TYPE "win")
    add_definitions(-D__WIN__)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(OS_TYPE "mac")
    add_definitions(-D__MAC__)
else()
    set(OS_TYPE "unknown")
    message(WARNING "Unsupported operating system: ${CMAKE_SYSTEM_NAME}")
endif()

message(STATUS "os type is ${OS_TYPE}")

# arch type
if(CMAKE_HOST_SYSTEM_PROCESSOR)
    string(TOLOWER "${CMAKE_HOST_SYSTEM_PROCESSOR}" RAW_ARCH)
else()
    string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" RAW_ARCH)
endif()

if(RAW_ARCH MATCHES "amd64|x86_64|x64")
    set(ARCH_TYPE "x86_64")
elseif(RAW_ARCH MATCHES "aarch64|arm64|armv8|armv9")
    set(ARCH_TYPE "arm64")
elseif(RAW_ARCH MATCHES "i[3-6]86")
    set(ARCH_TYPE "x86")
elseif(RAW_ARCH MATCHES "arm")
    set(ARCH_TYPE "arm")
else()
    set(ARCH_TYPE "unknown")
endif()

message(STATUS "arch type is ${ARCH_TYPE}")