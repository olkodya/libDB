//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_BOOK_H
#define LIBRARYAPP_BOOK_H
#include <iostream>
using namespace std;

class Book {
public:
    Book();

    void setIsbn(const string &isbn);

    void setBookName(const string &bookName);

    void setAuthor(const string &author);

    void setPublisher(const string &publisher);

    void setPublishYear(const string &publishYear);

    void setPublishPlace(const string &publishPlace);

    void setPages(const int &pages);

    void setPrice(const double &price);

    ~Book();

    const string &getIsbn() const;

    const string &getBookName() const;

    const string &getAuthor() const;

    const string &getPublisher() const;

    const string &getPublishYear() const;

    const string &getPublishPlace() const;

    const int & getPages() const;

    const double & getPrice() const;

private:
    string isbn;
    string book_name;
    string author;
    string publisher;
    string publishYear;
    string publishPlace;
    int pages;
    double price;
};




#endif //LIBRARYAPP_BOOK_H
