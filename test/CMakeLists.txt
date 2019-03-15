cmake_minimum_required(VERSION 3.13)

set(This MorseTest)

set(Sources
    morseTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Morse
)

add_test(
    NAME ${This}
    COMMAND ${This} 
)