
# define platform_base library
add_library(platform_base STATIC
        headers.h
        definitions.h
        window.h
        factory.h
        context.h
        window_manager.h
        window_manager.cpp
)

target_include_directories(platform_base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# precompile headers to reduce compile times for large libraries
target_precompile_headers(platform_base PRIVATE headers.h)
