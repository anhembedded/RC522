cmake_minimum_required(VERSION 3.21)
project(RC522)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RC522
        Arduino.cpp
        Arduino.hpp
        Binary.hpp
        HardwareSerial.cpp
        HardwareSerial.hpp
        Platform.cpp
        Platform.hpp
        Platform_HardwareSerial.cpp
        Platform_HardwareSerial.h
        Platform_HardwareSPI.cpp
        Platform_HardwareSPI.h
        Print.cpp
        Print.hpp
        RC522.cpp
        SPI.cpp
        SPI.hpp)
