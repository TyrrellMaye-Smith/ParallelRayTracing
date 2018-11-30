cmake_minimum_required(VERSION 2.6)
project(PARALLELRAYTRACING)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(parallelraytracing
  src/main.cpp
  src/frameBuffer.cpp
  src/frameBuffer.h
  src/geometry.cpp
  src/geometry.h
  src/object.cpp
  src/object.h
  src/camera.cpp
  src/camera.h
  src/rayTracer.cpp
  src/rayTracer.h
  src/screen.cpp
  src/screen.h
)

if(MSVC)
  target_link_libraries(parallelraytracing
    SDL2
  )
endif()

if(MSVC)
  add_custom_command(TARGET parallelraytracing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:parallelraytracing>"
  )
endif()
