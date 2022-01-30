cmake_minimum_required(VERSION 3.2)

project("Simple File Manager" VERSION 1.0)

add_executable(core "src/main.cpp")
set_target_properties(core PROPERTIES OUTPUT_NAME "Simple File Manager")