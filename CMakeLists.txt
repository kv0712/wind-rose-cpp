# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(wind_rose)

# Основная программа
add_executable(wind_rose 
    src/main.cpp 
    src/sorting.cpp
    src/processing.cpp
)
target_include_directories(wind_rose PUBLIC include)

# Тесты
enable_testing()
find_package(GTest REQUIRED)

add_executable(wind_rose_tests
    tests/test_processing.cpp
    src/processing.cpp
)
target_include_directories(wind_rose_tests PUBLIC include)
target_link_libraries(wind_rose_tests GTest::GTest GTest::Main)

add_test(NAME wind_rose_tests COMMAND wind_rose_tests)