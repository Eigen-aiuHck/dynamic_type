cmake_minimum_required(VERSION 3.15...3.26)


project(
  Dynamic_Type
  VERSION 1.0
  DESCRIPTION "non static type system for C++."
  LANGUAGES CXX)

add_subdirectory(src)

set(DYNAMIC_TYPE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)