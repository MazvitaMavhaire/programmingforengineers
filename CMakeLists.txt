cmake_minimum_required(VERSION 3.21)
project(programmingforengineers_final)

set(CMAKE_C_STANDARD 99)

add_executable(Clion main.c io.h io.c waveform.c waveform.h)

if(UNIX)
    target_link_libraries(programmingforengineers_final)
    endif()
