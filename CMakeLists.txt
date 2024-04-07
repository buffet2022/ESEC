cmake_minimum_required(VERSION 3.25)
project(ESEC)

set(CMAKE_CXX_STANDARD 11)

add_executable(ESEC main.cpp
        src/1/hgc.cpp src/1/copilot.cpp src/1/gemini.cpp src/1/gpt4.cpp
        src/2/hgc.cpp src/2/copilot.cpp src/2/gemini.cpp src/2/gpt4.cpp
        src/3/hgc.cpp src/3/copilot.cpp src/3/gemini.cpp src/3/gpt4.cpp
        src/4/hgc.cpp src/4/copilot.cpp src/4/gemini.cpp src/4/gpt4.cpp
        src/5/hgc.cpp src/5/copilot.cpp src/5/gemini.cpp src/5/gpt4.cpp
        src/6/hgc.cpp src/6/copilot.cpp src/6/gemini.cpp src/6/gpt4.cpp
        src/7/hgc.cpp src/7/copilot.cpp src/7/gemini.cpp src/7/gpt4.cpp
        src/8/hgc.cpp src/8/copilot.cpp src/8/gemini.cpp src/8/gpt4.cpp
        src/9/hgc.cpp src/9/copilot.cpp src/9/gemini.cpp src/9/gpt4.cpp
        src/10/hgc.cpp src/10/copilot.cpp src/10/gemini.cpp src/10/gpt4.cpp
        src/11/hgc.cpp src/11/copilot.cpp src/11/gemini.cpp src/11/gpt4.cpp
        src/12/hgc.cpp src/12/copilot.cpp src/12/gemini.cpp src/12/gpt4.cpp
        src/13/hgc.cpp src/13/copilot.cpp src/13/gemini.cpp src/13/gpt4.cpp
        src/14/hgc.cpp src/14/copilot.cpp src/14/gemini.cpp src/14/gpt4.cpp
        src/15/hgc.cpp src/15/copilot.cpp src/15/gemini.cpp src/15/gpt4.cpp
        src/16/hgc.cpp src/16/copilot.cpp src/16/gemini.cpp src/16/gpt4.cpp
        src/17/hgc.cpp src/17/copilot.cpp src/17/gemini.cpp src/17/gpt4.cpp
        src/18/hgc.cpp src/18/copilot.cpp src/18/gemini.cpp src/18/gpt4.cpp )
