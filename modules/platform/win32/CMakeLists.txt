
add_library(platform_win32 STATIC context.cpp events.cpp window.cpp)
target_link_libraries(platform_win32 PRIVATE platform_base)

target_include_directories(platform_win32 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
