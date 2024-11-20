
add_library(graphics_buffers STATIC vertex_buffer.cpp)
target_link_libraries(graphics_buffers PRIVATE graphics_module)
target_include_directories(graphics_buffers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

#target_precompile_headers(graphics_buffers INTERFACE headers.h)
