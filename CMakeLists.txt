cmake_minimum_required(VERSION 3.28.1)
project(GitCliContributions)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories for libgit2
include_directories(/opt/homebrew/include)

# Find the libgit2 library
find_library(LIBGIT2_LIBRARY NAMES git2 PATHS /opt/homebrew/lib)

# Ensure the executable name matches the project name or the intended output name
# and the source file is correctly referred to
add_executable(GitCliContributions scan.cpp repo.cpp)

# Link against the libgit2 library, ensure the target name matches the add_executable target
target_link_libraries(GitCliContributions ${LIBGIT2_LIBRARY})