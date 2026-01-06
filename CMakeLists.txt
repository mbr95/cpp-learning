
cmake_minimum_required(VERSION 3.20)

project(
    cpp_learning
    VERSION 0.1.0
    LANGUAGES CXX
)

# -------------------------------------------------
# Global C++ settings
# -------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile_commands.json (for clang-tidy, clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------------------------------------------------
# Warnings (compiler-specific)
# -------------------------------------------------
if (MSVC)
    add_compile_options(
        /W4
        /permissive-
        /EHsc
        /wd4251  # DLL interface warning (ignore for learning)
    )
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wnull-dereference
        -Wdouble-promotion
        -Wformat=2
    )
endif()

# -------------------------------------------------
# Sanitizers (optional, enabled in Debug)
# -------------------------------------------------
option(ENABLE_SANITIZERS "Enable sanitizers in Debug builds" ON)

if (ENABLE_SANITIZERS AND NOT MSVC AND NOT WIN32)
    add_compile_options(
        $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
    )
    add_link_options(
        $<$<CONFIG:Debug>:-fsanitize=address,undefined>
    )
endif()

# -------------------------------------------------
# Subdirectories
# -------------------------------------------------
# TODO:Uncomment when subdirectories added
add_subdirectory(basics)
#add_subdirectory(memory)
#add_subdirectory(stl)
#add_subdirectory(templates)
#add_subdirectory(concurrency)
#add_subdirectory(performance)
#add_subdirectory(projects)
