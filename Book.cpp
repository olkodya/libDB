//
// Created by Eldo on 19.10.2023.
//

#include "Book.h"

Book::Book() = default;

Book::~Book() = default;

const string &Book::getIsbn() const {
    return isbn;
}

const string &Book::getBookName() const {
    return book_name;
}

const string &Book::getAuthor() const {
    return author;
}

const string &Book::getPublisher() const {
    return publisher;
}

const string &Book::getPublishYear() const {
    return publishYear;
}

const string &Book::getPublishPlace() const {
    return publishPlace;
}

const int &Book::getPages() const {
    return pages;
}

const double &Book::getPrice() const {
    return price;
}

void Book::setIsbn(const string &isbn) {
    Book::isbn = isbn;
}

void Book::setBookName(const string &bookName) {
    book_name = bookName;
}

void Book::setAuthor(const string &author) {
    Book::author = author;
}

void Book::setPublisher(const string &publisher) {
    Book::publisher = publisher;
}

void Book::setPublishYear(const string &publishYear) {
    Book::publishYear = publishYear;
}

void Book::setPublishPlace(const string &publishPlace) {
    Book::publishPlace = publishPlace;
}

void Book::setPages(const int &pages) {
    Book::pages = pages;
}

void Book::setPrice(const double &price) {
    Book::price = price;
}
