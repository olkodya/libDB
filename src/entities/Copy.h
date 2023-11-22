//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_COPY_H
#define LIBRARYAPP_COPY_H
#include "Book.h"
#include "Date.h"
#include "Reader.h"
#include <iomanip>
class Copy {
public:
    Copy();

    void setInventoryNum(const int& inventoryNum);

    void setBook(Book* book);

    void setReader(Reader* reader);

    void setBorrowDate(const Date& borrowDate);

    void setReturnDate(const Date& returnDate);

    ~Copy();

    const int& getInventoryNum() const;

    Book* getBook() const;

    Reader* getReader() const;

    Date getBorrowDate() const;

    const Date& getReturnDate() const;
    void print(int i);

    private:
    int inventoryNum;
    Book *book;
    Reader *reader;
    Date borrowDate;
    Date returnDate;
 };



#endif //LIBRARYAPP_COPY_H
