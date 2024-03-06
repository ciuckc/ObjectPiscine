cmake_minimum_required(VERSION 3.27)

project(
  graph
  VERSION 1.0
  DESCRIPTION "Plotting graphs to the console"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Werror)

add_subdirectory(src)
