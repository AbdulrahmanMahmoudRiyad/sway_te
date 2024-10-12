cmake_minimum_required(VERSION 3.5)
project(sway C)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MD")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")

set(SRC_DIR "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/sway/src")

include_directories(
    "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/freetype/freetype/include"
    "F:/P/You/Locker/ME/WorkS/WE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/freetype/freetype/include/freetype"
)

file(GLOB_RECURSE SOURCE_FILES "${SRC_DIR}/*.c")
add_executable(sway ${SOURCE_FILES})

set(GLEW_INCLUDE_DIRS "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/glew-2.1.0/include")
set(GLEW_LIBRARIES "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/glew-2.1.0/lib/Release/x64/glew32.lib")

set(SDL2_INCLUDE_DIRS "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/SDL2/SDL2 visual studio/include")
set(SDL2_LIBRARIES "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/SDL2/SDL2 visual studio/lib/x64/SDL2.lib"
                    "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/SDL2/SDL2 visual studio/lib/x64/SDL2main.lib")

if (NOT FREETYPE_FOUND)
    set(FREETYPE_INCLUDE_DIRS "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/freetype/freetype/include")
    set(FREETYPE_LIBRARIES "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/dependencies installations/freetype/freetype/build/Release/freetype.lib")
endif()

set(OPENGL_LIBRARIES "E:/Work Softwares/visual studio/SDK/ScopeCppSDK/vc15/SDK/lib/opengl32.lib")
set(MINIRENT_INCLUDE_DIR "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/sway/src")
set(SHADER_DIR "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/sway/shaders")
set(FONT_DIR "F:/P/You/Locker/ME/Work/SWE projects/Text Editor/rainbow_candy/te_code 3.0/sway/fonts")

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
