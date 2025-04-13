cmake_minimum_required(VERSION 3.10)
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)

FetchContent_Declare(
    fakeit
    GIT_REPOSITORY https://github.com/eranpeer/FakeIt.git
    GIT_TAG        2.4.1  # Явно указываем версию
)

FetchContent_MakeAvailable(Catch2 fakeit)

project(Volsu-collage-testiong)

add_executable(Volsu-collage-testiong main.cpp Libs/Operations.H)

add_executable(custom-main-tests tests-main.cpp)

target_include_directories(custom-main-tests PRIVATE
    ${fakeit_SOURCE_DIR}/single_header/catch
    ${fakeit_SOURCE_DIR}/config/catch
)

target_link_libraries(custom-main-tests PRIVATE
    Catch2::Catch2WithMain
)

target_compile_definitions(custom-main-tests PRIVATE
    -DFAKEIT_USE_CATCH
)