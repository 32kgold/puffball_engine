
add_library(platform_base INTERFACE)
target_include_directories(platform_base INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_precompile_headers(platform_base INTERFACE headers.h)
