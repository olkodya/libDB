#pragma once
#include "../entities/Theme.h"
#include "../DataBase.h"

class ThemeMapper {
public:
    ThemeMapper(DataBase& db);

    void update(Theme& theme);

    void save(Theme& theme);

    void remove(Theme& theme);

    vector<Theme> getAll();

    Theme getByID(int id);

private:
    DataBase& db;

};