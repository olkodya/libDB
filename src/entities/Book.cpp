//
// Created by Eldo on 19.10.2023.
//

#include "Book.h"

Book::Book() {
    isbn = " ";
    book_name = " ";
    author = " ";
    publishYear = 0;
    pages = 0;
    price = 0;
};

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

 Publisher *Book::getPublisher() const {
    return publisher;
}



const int &Book::getPublishYear() const {
    return publishYear;
}


const int &Book::getPages() const {
    return pages;
}

const double &Book::getPrice() const {
    return price;
}

const int& Book::getCopyAmount() const {
    return copyAmount;
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

void Book::setPublisher(Publisher publisher) {
    this->publisher = new Publisher();
    this->publisher->setID(publisher.getID());
    this->publisher->setPlace(publisher.getPlace());
    this->publisher->setPublisherName(publisher.getPublisherName());
}



void Book::setPublishYear(const int &publishYear) {
    Book::publishYear = publishYear;
}



void Book::setPages(const int &pages) {
    Book::pages = pages;
}

void Book::setPrice(const double &price) {
    Book::price = price;
}

void Book::setCopyAmount(const int& copyAmount) {
    Book::copyAmount = copyAmount;
}

void Book::print(int i) {
    std::cout << std::left << std::setw(5) << i + 1 << std::setw(20) << isbn << std::setw(40)
        << book_name << std::setw(20) << author << std::setw(20) << publisher->getPublisherName() << std::setw(20) << publisher->getPlace() << std::setw(10) << publishYear << std::setw(10) << pages << std::setw(10) << copyAmount << std::endl;
}