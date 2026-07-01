cmake_minimum_required(VERSION 3.6)
project(Contact_Manager)

set(CMAKE_CXX_STANDARD 23)

add_executable(Contact_Manager main.cpp
        include/Contact.h
        include/ContactManager.h
        source/ContactManager.cpp)
