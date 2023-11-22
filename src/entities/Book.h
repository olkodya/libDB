//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_BOOK_H
#define LIBRARYAPP_BOOK_H

#include <iostream>
#include "Publisher.h"
#include <iomanip>
using namespace std;

class Book {
public:
    Book();

    void setIsbn(const string &isbn);

    void setBookName(const string &bookName);

    void setAuthor(const string &author);

    void setPublisher(Publisher publisher);

    void setPublishYear(const int &publishYear);

    void setPages(const int &pages);

    void setPrice(const double &price);

    void setCopyAmount(const int& copyAmount);


    ~Book();

    const string &getIsbn() const;

    const string &getBookName() const;

    const string &getAuthor() const;

    Publisher* getPublisher() const;

    const int &getPublishYear() const;

    const int &getPages() const;

    const double &getPrice() const;

    const int& getCopyAmount() const;

    void print(int i);


private:
    string isbn;
    string book_name;
    string author;
    Publisher* publisher;
    int publishYear;
    int pages;
    double price;
    int copyAmount;
};


#endif //LIBRARYAPP_BOOK_H
