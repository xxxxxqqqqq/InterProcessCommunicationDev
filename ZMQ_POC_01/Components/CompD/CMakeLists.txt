###
cmake_minimum_required(VERSION 3.5.1)
project(CompD)
set(CMAKE_VERBOSE_MAKEFILE ON)

###
file(GLOB_RECURSE CompD_srcs "*.cpp" )
list(APPEND CompD_srcs ${CMAKE_SOURCE_DIR}/Components/all_components.cpp)
list(APPEND CompD_srcs ${CMAKE_SOURCE_DIR}/Components/all_sockets.cpp)
list(APPEND CompD_srcs ${CMAKE_CURRENT_SOURCE_DIR}/Lib/mylibD.cpp)

###
file(GLOB_RECURSE CompD_headers "*.hpp" "*.h")
list(APPEND CompD_headers ${CMAKE_SOURCE_DIR}/Components/all_components.h)
list(APPEND CompD_headers ${CMAKE_SOURCE_DIR}/Components/all_sockets.h)
list(APPEND CompD_headers ${CMAKE_CURRENT_SOURCE_DIR}/Lib/mylibD.h)
file(GLOB_RECURSE PortGenerator_headers "${CMAKE_SOURCE_DIR}/PortGenerator/*.hpp" "${CMAKE_SOURCE_DIR}/PortGenerator/*.h")

###
find_package(Protobuf)
INCLUDE_DIRECTORIES(${Protobuf_INCLUDE_DIR})
PROTOBUF_GENERATE_CPP(MY_PROTO_SRC MY_PROTO_HEADER CompD.proto)
ADD_LIBRARY(CompD_proto ${MY_PROTO_HEADER} ${MY_PROTO_SRC})

###
include(/usr/local/share/cmake/cppzmq/cppzmqConfig.cmake)
include(/usr/local/share/cmake/ZeroMQ/ZeroMQConfig.cmake)

###
add_definitions(-DZEROMQ_BIN_DIR=${CMAKE_SOURCE_DIR}/bin)
set(ZEROMQ_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

###
add_executable(${PROJECT_NAME} ${CompD_srcs} ${CompD_headers} ${PortGenerator_headers})

###
IF(UNIX)
    target_link_libraries(${PROJECT_NAME} cppzmq CompD_proto ${Protobuf_LIBRARIES})
ENDIF(UNIX)

###
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
