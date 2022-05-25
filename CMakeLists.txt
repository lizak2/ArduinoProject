cmake_minimum_required(VERSION 3.10)

# set the project name
project(ArduinoProject)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options("-Werror")

configure_file(Calculator.hpp Calculator.hpp)
configure_file(InputHandler.hpp Calculator.hpp)
configure_file(InputValidator.hpp InputValidator.hpp)
configure_file(InterfaceWrapper.hpp InterfaceWrapper.hpp)


# add the executable
add_executable(ArduinoProject main.cpp Calculator.cpp InputHandler.cpp InputValidator.cpp InterfaceWrapper.cpp)
