cmake_minimum_required(VERSION 3.20)
project(libraryApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(libraryApp src/main.cpp src/entities/Book.cpp src/entities/Book.h src/entities/Themes.cpp src/entities/Themes.h src/entities/Readers.cpp src/entities/Readers.h src/entities/Copies.cpp src/entities/Copies.h src/mappers/BookMapper.cpp src/mappers/BookMapper.h src/DataBase.cpp src/DataBase.h)

target_link_libraries(libraryApp odbc32)