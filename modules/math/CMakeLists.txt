project(math_module)

add_library(math_module INTERFACE)

add_subdirectory(base)

# link parent module with children
target_link_libraries(math_module INTERFACE math_base)
