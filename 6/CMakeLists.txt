cmake_minimum_required(VERSION 3.10)
project(sixth_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(lab_06_lib ${SOURCES})

add_executable(main main.cpp)
add_executable(tests tests.cpp)

target_link_libraries(main lab_06_lib)
target_link_libraries(tests lab_06_lib GTest::gtest_main)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)
gtest_discover_tests(tests)