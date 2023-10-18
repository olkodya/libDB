//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_BOOKMAPPER_H
#define LIBRARYAPP_BOOKMAPPER_H


#include "Book.h"
#include "DataBase.h"

class BookMapper {
public:
    BookMapper(DataBase &db);

    void update(Book &book);

    void save(Book &book);

    vector<Book> getAll();

    Book getByIsbn(string isbn);

private:
    DataBase &db;

};


#endif //LIBRARYAPP_BOOKMAPPER_H
