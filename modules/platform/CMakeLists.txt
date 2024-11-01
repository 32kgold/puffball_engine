project(platform_module)

add_library(platform_module INTERFACE)

add_subdirectory(base)
add_subdirectory(win32)

# Link base and win32 to platform_module
target_link_libraries(platform_module INTERFACE platform_base platform_win32)