//
// Created by Eldo on 19.10.2023.
//
#pragma once
#ifndef LIBRARYAPP_BOOKMAPPER_H
#define LIBRARYAPP_BOOKMAPPER_H

#include "../entities/Book.h"
#include "../DataBase.h"
#include "../entities/Publisher.h"
#include "PublisherMapper.h"

class BookMapper {
public:
    BookMapper(DataBase& db, PublisherMapper& publisherMapper);

    void update(Book &book);

    void save(Book &book);

    void remove(Book &book);

    vector<Book> getAll();

    Book getByIsbn(string isbn);

private:
    DataBase &db;
    PublisherMapper& publisherMapper;

};


#endif //LIBRARYAPP_BOOKMAPPER_H
