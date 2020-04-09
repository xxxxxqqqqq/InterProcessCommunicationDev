###
cmake_minimum_required(VERSION 3.5.1)
project(CompE)
set(CMAKE_VERBOSE_MAKEFILE ON)

###
file(GLOB_RECURSE CompE_srcs "*.cpp" )
list(APPEND CompE_srcs ${CMAKE_SOURCE_DIR}/Components/all_components.cpp)
list(APPEND CompE_srcs ${CMAKE_SOURCE_DIR}/Components/all_sockets.cpp)
list(APPEND CompE_srcs ${CMAKE_CURRENT_SOURCE_DIR}/Lib/mylibE.cpp)

###
file(GLOB_RECURSE CompE_headers "*.hpp" "*.h")
list(APPEND CompE_headers ${CMAKE_SOURCE_DIR}/Components/all_components.h)
list(APPEND CompE_headers ${CMAKE_SOURCE_DIR}/Components/all_sockets.h)
list(APPEND CompE_headers ${CMAKE_CURRENT_SOURCE_DIR}/Lib/mylibE.h)
file(GLOB_RECURSE PortGenerator_headers "${CMAKE_SOURCE_DIR}/PortGenerator/*.hpp" "${CMAKE_SOURCE_DIR}/PortGenerator/*.h")

###
find_package(Protobuf)
INCLUDE_DIRECTORIES(${Protobuf_INCLUDE_DIR})
PROTOBUF_GENERATE_CPP(MY_PROTO_SRC MY_PROTO_HEADER CompE.proto)
ADD_LIBRARY(CompE_proto ${MY_PROTO_HEADER} ${MY_PROTO_SRC})

###
include(/usr/local/share/cmake/cppzmq/cppzmqConfig.cmake)
include(/usr/local/share/cmake/ZeroMQ/ZeroMQConfig.cmake)

###
add_definitions(-DZEROMQ_BIN_DIR=${CMAKE_SOURCE_DIR}/bin)
set(ZEROMQ_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

###
add_executable(${PROJECT_NAME} ${CompE_srcs} ${CompE_headers} ${PortGenerator_headers})

###
IF(UNIX)
    target_link_libraries(${PROJECT_NAME} cppzmq CompE_proto ${Protobuf_LIBRARIES})
ENDIF(UNIX)

###
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
