cmake_minimum_required(VERSION 2.6)
project(OpenGLRenderer)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(OpenGL_GL_PREFERENCE "GLVND")

set(CMAKE_CXX_STANDARD 14)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(PROJECT_CODE
  include/renderer/window.hpp src/renderer/window.cpp
  include/renderer/shaderProgram.hpp src/renderer/shaderProgram.cpp
  src/glad/glad.c
  src/renderer/main.cpp)

include_directories(include)
include_directories(include/renderer)

add_executable(renderer ${PROJECT_CODE})
target_link_libraries(renderer ${CMAKE_DL_LIBS})
target_link_libraries(renderer glfw)
target_link_libraries(renderer ${OPENGL_gl_LIBRARY})
target_include_directories(renderer PUBLIC ${OPENGL_INCLUDE_DIR})
