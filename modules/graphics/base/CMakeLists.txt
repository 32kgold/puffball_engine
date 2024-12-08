
add_library(graphics_base INTERFACE)
target_include_directories(graphics_base INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_precompile_headers(graphics_base INTERFACE headers.h)