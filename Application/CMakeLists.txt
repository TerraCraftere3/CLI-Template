add_executable(CLI-App src/main.cpp)

target_include_directories(CLI-App PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(MSVC)
    target_compile_options(CLI-App PRIVATE /W4)
else()
    target_compile_options(CLI-App PRIVATE -Wall -Wextra -Wpedantic)
endif()