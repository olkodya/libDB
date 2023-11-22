cmake_minimum_required(VERSION 3.20)
project(libraryApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(libraryApp src/main.cpp src/entities/Book.cpp src/entities/Book.h src/entities/Theme.cpp src/entities/Theme.h src/entities/Reader.cpp src/entities/Reader.h src/entities/Copy.cpp src/entities/Copy.h src/mappers/BookMapper.cpp src/mappers/BookMapper.h src/mappers/CopyMapper.cpp src/mappers/CopyMapper.h src/mappers/ReaderMapper.cpp src/mappers/ReaderMapper.h src/mappers/PublisherMapper.cpp src/mappers/PublisherMapper.h src/mappers/ThemeMapper.cpp src/mappers/ThemeMapper.h src/DataBase.cpp src/DataBase.h src/entities/Publisher.h src/entities/Publisher.cpp src/entities/Date.h src/entities/Date.cpp src/entities/ThemeBook.cpp src/entities/ThemeBook.h  src/mappers/ThemeBookMapper.h src/mappers/ThemeBookMapper.cpp)

target_link_libraries(libraryApp odbc32)