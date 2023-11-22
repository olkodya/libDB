#pragma once
#include <iostream>
#include "Book.h"
#include "Theme.h"

using namespace std;



class ThemeBook {
public:
    ThemeBook();

    void setBook(Book* book);

    void setTheme(Theme* theme);
    void print(int i);

    ~ThemeBook();

    Book* getBook() const;

    Theme* getTheme() const;


private:
    Book *book;
    Theme *theme;


};



