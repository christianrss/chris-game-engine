cmake_minimum_required(VERSION 3.10)

project (Engine)

set(PROJECT_SOURCE_FILES
    source/Engine.h
    source/Engine.cpp
    source/Application.h
    source/Application.cpp
    source/input/InputManager.h
    source/input/InputManager.cpp
    source/graphics/ShaderProgram.h
    source/graphics/ShaderProgram.cpp
    source/graphics/GraphicsAPI.h
    source/graphics/GraphicsAPI.cpp
)

include_directories(source)
add_library(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

# Uncomment this to work on WSL
# --------------------------------------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW3 REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${GLFW3_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    ${GLFW3_STATIC_LIBRARIES}
    ${GLEW_STATIC_LIBRARIES}
    X11
    GL
)
# --------------------------------------------------------

# Uncomment this to work on Windows
# --------------------------------------------------------
# add_subdirectory(thirdparty/glfw-3.4
#     "${CMAKE_CURRENT_BINARY_DIR}/glfw_build")

# include_directories(thirdparty/glfw-3.4/include)

# set(BUILD_UTILS OFF CACHE BOOL "utilities" FORCE)

# add_subdirectory(thirdparty/glew/build/cmake
#     "${CMAKE_CURRENT_BINARY_DIR}/glew_build")

# include_directories(thirdparty/glew/include)

# set_property(TARGET glew_s  PROPERTY FOLDER GLEW)
# set_property(TARGET glew    PROPERTY FOLDER GLEW)

# target_link_libraries(${PROJECT_NAME}
#     glfw
#     glew_s
# )
# --------------------------------------------------------
