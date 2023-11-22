#pragma once
#include "../DataBase.h"
#include "../entities/ThemeBook.h"
#include "../mappers/ThemeMapper.h"
#include "../mappers/BookMapper.h"

class ThemeBookMapper {
public:
    ThemeBookMapper(DataBase& db, ThemeMapper& themeMapper, BookMapper& bookMapper);

    void update(ThemeBook& themeBook);

    void save(ThemeBook& themeBook);

    void remove(ThemeBook& themeBook);

    vector<ThemeBook> getAll();

    ThemeBook getByID(string isbn, int id);

private:
    DataBase& db;
    ThemeMapper& themeMapper;
    BookMapper& bookMapper;
};


