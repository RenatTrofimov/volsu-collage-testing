cmake_minimum_required(VERSION 3.10)
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

project(Volsu-collage-testiong)
add_executable(Volsu-collage-testiong main.cpp "Libs/Operations.H")

add_executable(custom-main-tests  tests-main.cpp)
target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2WithMain)