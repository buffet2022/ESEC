cmake_minimum_required(VERSION 3.25)
project(ESEC)

set(CMAKE_CXX_STANDARD 11)

add_executable(ESEC main.cpp
        src/1/hgc.cpp src/1/aigc.cpp
        src/2/hgc.cpp src/2/aigc.cpp
        src/3/hgc.cpp src/3/aigc.cpp
        src/4/hgc.cpp src/4/aigc.cpp
        src/5/hgc.cpp src/5/aigc.cpp
        src/6/hgc.cpp src/6/aigc.cpp
        src/7/hgc.cpp src/7/aigc.cpp
        src/8/hgc.cpp src/8/aigc.cpp
        src/9/hgc.cpp src/9/aigc.cpp
        src/10/hgc.cpp src/10/aigc.cpp
        src/11/hgc.cpp src/11/aigc.cpp
        src/12/hgc.cpp src/12/aigc.cpp
        src/13/hgc.cpp src/13/gpt4.cpp
        src/14/hgc.cpp src/14/gemini.cpp src/14/gpt4.cpp
        src/15/hgc.cpp src/15/gemini.cpp src/15/gpt4.cpp
        src/16/hgc.cpp src/16/gpt35.cpp src/16/gpt4.cpp
        src/17/hgc.cpp src/17/gpt35.cpp src/17/gpt4.cpp
        src/18/hgc.cpp src/18/gpt35.cpp src/18/gpt4.cpp src/13/gemini.cpp)
