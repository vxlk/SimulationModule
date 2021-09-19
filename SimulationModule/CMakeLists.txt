# CMakeList.txt : CMake project for SimulationModule, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# All modules use at least c++17
set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (SimulationModule 
"SimulationModule.hpp"
"IController.hpp"
"IState.hpp"
"Event.hpp"
"Updater.hpp"
"Controller.hpp"

"main.cpp"
"Controller.cpp"
)

# TODO: Add tests and install targets if needed.
