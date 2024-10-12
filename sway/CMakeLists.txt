cmake_minimum_required(VERSION 3.5)
project(sway C)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MD")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")

set(SRC_DIR "{your_own_src_code_directory_path}")

include_directories(
    "{your_own_path}/freetype/include"
    "{your_own_path}/freetype/include/freetype"
)

file(GLOB_RECURSE SOURCE_FILES "${SRC_DIR}/*.c")
add_executable(sway ${SOURCE_FILES})

set(GLEW_INCLUDE_DIRS "{your_own_path}/glew-2.1.0/include")
set(GLEW_LIBRARIES "{your_own_path}/lib/Release/x64/glew32.lib")

set(SDL2_INCLUDE_DIRS "{your_own_path}/SDL2 visual studio/include")
set(SDL2_LIBRARIES "{your_own_path}/lib/x64/SDL2.lib"
                    "{your_own_path}/lib/x64/SDL2main.lib")

if (NOT FREETYPE_FOUND)
    set(FREETYPE_INCLUDE_DIRS "{your_own_path}/freetype/include")
    set(FREETYPE_LIBRARIES "{your_own_path}/freetype/build/Release/freetype.lib")
endif()

set(OPENGL_LIBRARIES "{your_own_path}/SDK/lib/opengl32.lib")
set(MINIRENT_INCLUDE_DIR "{your_own_path}/sway/src")
set(SHADER_DIR "{your_own_path}/sway/shaders")
set(FONT_DIR "{your_own_path}/sway/fonts")

include_directories(${GLEW_INCLUDE_DIRS})
target_include_directories(sway PRIVATE
    ${SRC_DIR}
    ${MINIRENT_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${FREETYPE_INCLUDE_DIRS}
)

target_compile_definitions(sway PRIVATE GLEW_STATIC)

target_link_libraries(sway PRIVATE
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${FREETYPE_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

set_target_properties(sway PROPERTIES LINK_FLAGS "/NODEFAULTLIB:LIBCMT")

add_custom_command(TARGET sway POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SHADER_DIR}
    $<TARGET_FILE_DIR:sway>/shaders
)

add_custom_command(TARGET sway POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${FONT_DIR}
    $<TARGET_FILE_DIR:sway>/fonts
)
