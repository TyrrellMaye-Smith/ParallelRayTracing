cmake_minimum_required(VERSION 2.6)
project(PARALLELRAYTRACING)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/SDL2/include
		contrib
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(parallelraytracing
  src/Main.cpp
  src/FrameBuffer.cpp
  src/FrameBuffer.h
  src/Geometry.cpp
  src/Geometry.h
  src/Object.cpp
  src/Object.h
  src/Camera.cpp
  src/Camera.h
  src/RayTracer.cpp
  src/RayTracer.h
  src/Ray.h
  src/Sphere.h
  src/Sphere.cpp
  src/Source.h
  src/Source.cpp
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
