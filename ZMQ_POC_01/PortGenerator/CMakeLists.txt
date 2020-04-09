###
cmake_minimum_required(VERSION 3.5.1)
project(PortGenerator)
set(CMAKE_VERBOSE_MAKEFILE ON)

###
file(GLOB_RECURSE PortGenerator_srcs "*.cpp" )
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/all_components.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/all_sockets.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/CompA/CompA_interface.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/CompB/CompB_interface.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/CompC/CompC_interface.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/CompD/CompD_interface.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/CompE/CompE_interface.cpp)
list(APPEND PortGenerator_srcs ${CMAKE_SOURCE_DIR}/Components/CompF/CompF_interface.cpp)

###
file(GLOB_RECURSE PortGenerator_headers "*.hpp" "*.h")
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/all_components.h)
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/all_sockets.h)
file(GLOB_RECURSE Components_headers "${CMAKE_SOURCE_DIR}/Components/*.hpp" "${CMAKE_SOURCE_DIR}/Components/*.h")
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/CompA/CompA_interface.h)
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/CompB/CompB_interface.h)
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/CompC/CompC_interface.h)
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/CompD/CompD_interface.h)
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/CompE/CompE_interface.h)
list(APPEND PortGenerator_headers ${CMAKE_SOURCE_DIR}/Components/CompF/CompF_interface.h)

###
include(/usr/local/share/cmake/cppzmq/cppzmqConfig.cmake)
include(/usr/local/share/cmake/ZeroMQ/ZeroMQConfig.cmake)

###
add_definitions(-DZEROMQ_BIN_DIR=${CMAKE_SOURCE_DIR}/bin)
set(ZEROMQ_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

###
add_executable(${PROJECT_NAME} ${PortGenerator_srcs} ${PortGenerator_headers} ${Components_headers})

###
IF(UNIX)
    target_link_libraries(${PROJECT_NAME} cppzmq)
ENDIF(UNIX)

###
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
