cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()

project(ABIGAIL_DEMO LANGUAGES CXX)

set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH false)
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
# Ensure that RPATH is used on OSX
set(CMAKE_MACOSX_RPATH 1)

# Enforce the C++ standard, and disable extensions
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.58.0 REQUIRED)

# Allow the user to decide whether to build the shared libaries or the static libraries.
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(libcommon
  libcommon.cpp
)
target_include_directories(libcommon
  PUBLIC ${CMAKE_SOURCE_DIR}
)

add_library(libclient
  libclient.cpp
)
target_include_directories(libclient
  PUBLIC ${CMAKE_SOURCE_DIR}
  PUBLIC ${Boost_INCLUDE_DIRS}
)
target_link_libraries(libclient
  PRIVATE libcommon
  PUBLIC boost_system
)

add_library(libserver
  libserver.cpp
)
target_include_directories(libserver
  PUBLIC ${CMAKE_SOURCE_DIR}
)
target_link_libraries(libserver
  PRIVATE libcommon
  PUBLIC boost_system
)

add_executable(client
  client.cpp
)
target_include_directories(client
  PUBLIC ${CMAKE_SOURCE_DIR}
)
target_link_libraries(client
  libclient
)

add_executable(server
  server.cpp
)
target_include_directories(server
  PUBLIC ${CMAKE_SOURCE_DIR}
)
target_link_libraries(server
  libserver
)
