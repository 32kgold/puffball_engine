project(graphics_module)

add_library(graphics_module INTERFACE)

add_subdirectory(base)
add_subdirectory(buffers)

# src
add_library(glad STATIC glad/glad.c)
# include
target_include_directories(glad PUBLIC glad)

# link modules and glad
target_link_libraries(graphics_module INTERFACE glad graphics_buffers graphics_base)
