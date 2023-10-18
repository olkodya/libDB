//
// Created by Eldo on 19.10.2023.
//

#include "BookMapper.h"
#include <iostream>
#include <sstream>
//#include <format>

using namespace std;

BookMapper::BookMapper(DataBase &db) : db(db) {

}


void BookMapper::update(Book &book) {

}

void BookMapper::save(Book &book) {
    stringstream ss;
    if (book.getIsbn() != " ") {
        //Update ....
    }
    ss << "INSERT INTO books (isbn, book_name, author, publisher, publish_year, publish_place, pages, price) VALUES('"
       <<
       book.getIsbn() << "', '" << book.getBookName() << "', '" << book.getAuthor() << "', '" << book.getPublisher()
       << "', " << book.getPublishYear() << ", '" << book.getPublishPlace() << "', " << book.getPages() << ", "
       << book.getPrice() << ");";
    string query = ss.str();
    cout << query << endl;
    db.executeQuery(query);
}

vector<Book> BookMapper::getAll() {
    return vector<Book>();
}

Book BookMapper::getByIsbn(string isbn) {
    return Book();
}
