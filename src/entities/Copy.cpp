//
// Created by Eldo on 19.10.2023.
//

#include "Copy.h"
#include <sstream>
using namespace std;


Copy::Copy() {
    inventoryNum = -1;
};

Copy::~Copy() = default;

const int& Copy::getInventoryNum() const {
    return inventoryNum;
}

Book* Copy::getBook() const {
    return book;
}

Reader* Copy::getReader() const {
    return reader;
}

Date Copy::getBorrowDate() const {
    return borrowDate;
}

const Date& Copy::getReturnDate() const {
    return returnDate;
}


void Copy::setInventoryNum(const int & inventoryNum) {
    Copy::inventoryNum = inventoryNum;
}


void Copy::setBook(Book* book) {
    this->book = new Book();
    this->book->setIsbn(book->getIsbn());
    this->book->setAuthor(book->getAuthor());
    this->book->setBookName(book->getBookName());
    this->book->setCopyAmount(book->getCopyAmount());
    this->book->setPages(book->getPages());
    this->book->setPrice(book->getPrice());
    this->book->setPublishYear(book->getPublishYear());
    this->book->setPublisher(*book->getPublisher());
}

void Copy::setReader(Reader* reader) {
    if (reader != nullptr) {
        this->reader = new Reader();
        this->reader->setCardNum(reader->getCardNum());
        this->reader->setBirthDate(reader->getBirthDate());
        this->reader->setFirstName(reader->getFirstName());
        this->reader->setLastName(reader->getLastName());
        this->reader->setMiddleName(reader->getMiddleName());
        this->reader->setPhoneNumber(reader->getPhoneNumber());
    }
    else {
        this->reader = reader;
    }
}

void Copy::setBorrowDate(const Date& borrowDate) {
    string str = " ";
    this->borrowDate = Date(borrowDate.getYear(), borrowDate.getDay(), borrowDate.getMonth(), borrowDate.getHour(), borrowDate.getMin());
    if (borrowDate.getStringTime() == " ")
        this->borrowDate.setStringTime(str);
}

void Copy::setReturnDate(const Date& returnDate) {
    string str = " ";
    this->returnDate = Date(returnDate.getYear(), returnDate.getDay(), returnDate.getMonth(), returnDate.getHour(), returnDate.getMin());
    if (returnDate.getStringTime() == " ")
        this->returnDate.setStringTime(str);
}

void Copy::print(int i) {
    stringstream ss;
    if (reader != nullptr)
        ss << reader->getCardNum();
    else ss << " ";

    string read = ss.str();
        std::cout << std::left << std::setw(10) << i + 1 << std::setw(20) << inventoryNum << std::setw(20)
            << book->getIsbn() << std::setw(20) << read << std::setw(20) << borrowDate.getStringTime() << std::setw(20) << returnDate.getStringTime() << std::endl;
    
}


