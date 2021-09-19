# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# All modules use at least c++17
set(CMAKE_CXX_STANDARD 17)

project ("SimulationModule")

# Include sub-projects.
add_subdirectory ("SimulationModule")
