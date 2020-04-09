###
cmake_minimum_required(VERSION 3.5.1)
project(CompB)
set(CMAKE_VERBOSE_MAKEFILE ON)

###
file(GLOB_RECURSE CompB_srcs "*.cpp" )
list(APPEND CompB_srcs ${CMAKE_SOURCE_DIR}/Components/all_components.cpp)
list(APPEND CompB_srcs ${CMAKE_SOURCE_DIR}/Components/all_sockets.cpp)
list(APPEND CompB_srcs ${CMAKE_CURRENT_SOURCE_DIR}/Lib/mylibB.cpp)

###
file(GLOB_RECURSE CompB_headers "*.hpp" "*.h")
list(APPEND CompB_headers ${CMAKE_SOURCE_DIR}/Components/all_components.h)
list(APPEND CompB_headers ${CMAKE_SOURCE_DIR}/Components/all_sockets.h)
file(GLOB_RECURSE PortGenerator_headers "${CMAKE_SOURCE_DIR}/PortGenerator/*.hpp" "${CMAKE_SOURCE_DIR}/PortGenerator/*.h")
list(APPEND CompB_headers ${CMAKE_CURRENT_SOURCE_DIR}/Lib/mylibB.h)

###
find_package(Protobuf)
INCLUDE_DIRECTORIES(${Protobuf_INCLUDE_DIR})
PROTOBUF_GENERATE_CPP(MY_PROTO_SRC MY_PROTO_HEADER CompB.proto)
ADD_LIBRARY(CompB_proto ${MY_PROTO_HEADER} ${MY_PROTO_SRC})

###
include(/usr/local/share/cmake/cppzmq/cppzmqConfig.cmake)
include(/usr/local/share/cmake/ZeroMQ/ZeroMQConfig.cmake)

###
add_definitions(-DZEROMQ_BIN_DIR=${CMAKE_SOURCE_DIR}/bin)
set(ZEROMQ_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

###
add_executable(${PROJECT_NAME} ${CompB_srcs} ${CompB_headers} ${PortGenerator_headers})

###
IF(UNIX)
    target_link_libraries(${PROJECT_NAME} cppzmq CompB_proto ${Protobuf_LIBRARIES})
ENDIF(UNIX)

###
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
