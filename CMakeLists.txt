cmake_minimum_required(VERSION 3.25)
project(VisualizeAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS OFF)

#Fetch content to get sfml source
include(FetchContent)

add_executable(VisualizeAlgorithms main.cpp InsertionSort.cpp InsertionSort.h CountingSort.cpp CountingSort.h MergeSort.cpp MergeSort.h QuickSort.cpp QuickSort.h StaticMembers.cpp StaticMembers.h Engine.cpp Engine.h)

FETCHCONTENT_DECLARE(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c # release-2.6.0
)

FetchContent_MakeAvailable(sfml)

target_link_libraries(VisualizeAlgorithms PRIVATE sfml-graphics)
target_sources(VisualizeAlgorithms PRIVATE
        main.cpp
        )

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
    target_compile_options(VisualizeAlgorithms PRIVATE -Wall -Wextra -Wpedantic)
endif()
