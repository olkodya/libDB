cmake_minimum_required(VERSION 3.20)
project(libraryApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(libraryApp main.cpp Book.cpp Book.h Themes.cpp Themes.h Readers.cpp Readers.h Copies.cpp Copies.h BookMapper.cpp BookMapper.h DataBase.cpp DataBase.h)

target_link_libraries(libraryApp odbc32)