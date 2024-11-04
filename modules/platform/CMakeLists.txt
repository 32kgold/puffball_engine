project(platform_module)

add_library(platform_module STATIC window_manager.cpp)

add_subdirectory(base)
add_subdirectory(win32)

target_link_libraries(platform_module PRIVATE platform_base platform_win32 user32 opengl32)
target_include_directories(platform_module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})