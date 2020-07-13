cmake_minimum_required (VERSION 2.6)
project (eksperymenty)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(usr/include/GLFW) # bo nie moze mi znalezc sam glefa :(

include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})

add_executable(eksperymenty
    main.cpp
)

target_link_libraries(eksperymenty glfw ${GLFW_LIBRARIES}  ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} )