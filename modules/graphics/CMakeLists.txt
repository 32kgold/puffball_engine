project(graphics_module)

add_library(graphics_module INTERFACE)

# src
add_library(glad STATIC glad/glad.c)

# include
target_include_directories(glad PUBLIC glad)
# link module with glad
target_link_libraries(graphics_module INTERFACE glad)
