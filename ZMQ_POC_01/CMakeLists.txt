###
cmake_minimum_required(VERSION 3.5.1)
project(Backbone_Template)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-std=c++0x -fpermissive)
set(ALL_FOR_BUILD)
set(CMAKE_FIND_DEBUG_MODE 1)

###
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/CompA")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/CompB")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/CompC")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/CompD")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/CompE")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Components/CompF")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/PortGenerator")

###
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components/CompA)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components/CompB)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components/CompC)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components/CompD)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components/CompE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components/CompF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/PortGenerator)

###
export(PACKAGE Backbone_Template)

 
