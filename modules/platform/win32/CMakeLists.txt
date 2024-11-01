
add_library(platform_win32 STATIC window.cpp)

target_link_libraries(platform_win32 PRIVATE user32)

target_include_directories(platform_win32 PUBLIC ..)