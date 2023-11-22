//
// Created by Eldo on 19.10.2023.
//

#include "BookMapper.h"
#include <iostream>
#include <sstream>
//#include <format>

using namespace std;

BookMapper::BookMapper(DataBase &db, PublisherMapper &publisherMapper) : db(db), publisherMapper(publisherMapper){
    
}




void BookMapper::update(Book &book) {
    stringstream ss;
    if (book.getIsbn() != " ") {
        ss << "UPDATE books SET book_name='" << book.getBookName() << "', author='" << book.getAuthor()
           << "', publisher_id="
           << book.getPublisher()->getID() << " , publish_year=" << book.getPublishYear() << ", pages=" << book.getPages() << ", price=" << book.getPrice() << ", copies_amount=" << book.getCopyAmount()
           << " WHERE isbn='" << book.getIsbn() << "';";
    }
    string query = ss.str();
    db.executeQuery(query);
}

void BookMapper::save(Book &book) {
    stringstream ss;
    if (book.getIsbn() == " ") {
        ss << " ";
    } else {
        ss << "INSERT INTO books(isbn, book_name, author, publisher_id, publish_year, pages, price, copies_amount) VALUES('"
                <<
                book.getIsbn() << "', '" << book.getBookName() << "', '" << book.getAuthor() << "', "
                << book.getPublisher()->getID()
                << ", " << book.getPublishYear()  << ", " << book.getPages() << ", "
                << book.getPrice() << ", "<< book.getCopyAmount() << ");";
    }
    string query = ss.str();
    db.executeQuery(query);

}

vector<Book> BookMapper::getAll() {
    vector<Book> books;
    stringstream ss;
    ss << "SELECT*FROM books ORDER BY author;";
    string query = ss.str();
    SQLHSTMT stmt = db.executeQuery(query);
    SQLCHAR id_[255];
    SQLCHAR name[255];
    SQLCHAR author[255];
    SQLINTEGER publisher_id;
    SQLINTEGER publish_year;
    SQLINTEGER pages;
    SQLDOUBLE price;
    SQLINTEGER copy_amount;
    SQLRETURN ret;
    ret = SQLBindCol(stmt, 1, SQL_C_CHAR, &id_, sizeof(id_), NULL);
    ret = SQLBindCol(stmt, 2, SQL_C_CHAR, name, sizeof(name), NULL);
    ret = SQLBindCol(stmt, 3, SQL_C_CHAR, author, sizeof(author), NULL);
    ret = SQLBindCol(stmt, 4, SQL_C_LONG, &publisher_id, sizeof(publisher_id), NULL);
    ret = SQLBindCol(stmt, 5, SQL_C_LONG, &publish_year, sizeof(publish_year), NULL);
    ret = SQLBindCol(stmt, 6, SQL_C_LONG, &pages, sizeof(pages), NULL);
    ret = SQLBindCol(stmt, 7, SQL_C_DOUBLE, &price, sizeof(price), NULL);
    ret = SQLBindCol(stmt, 8, SQL_C_LONG, &copy_amount, sizeof(copy_amount), NULL);

    ret = SQLFetch(stmt);
    while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        Book book;
        Publisher publisher;
        publisher = publisherMapper.getByID(publisher_id);
        book.setIsbn((const char*)id_);
        book.setBookName((const char*)name);
        book.setAuthor((const char*)author);
        book.setPublishYear(publish_year);
        book.setPublisher(publisher);
        book.setPages(pages);
        book.setPrice(price);
        book.setCopyAmount(copy_amount);
        books.push_back(book);
        ret = SQLFetch(stmt);
    }
    SQLFreeStmt(stmt, SQL_CLOSE);
    return books;
}

Book BookMapper::getByIsbn(string isbn) {
    Book book;
    stringstream ss;
    ss << "SELECT*FROM books WHERE isbn = '" << isbn << "';";
    string query = ss.str();
    SQLHSTMT stmt = db.executeQuery(query);
    SQLCHAR id_[255];
    SQLCHAR name[255];
    SQLCHAR author[255];
    SQLINTEGER publisher_id;
    SQLINTEGER publish_year;
    SQLINTEGER pages;
    SQLDOUBLE price;
    SQLINTEGER copy_amount;
    SQLRETURN ret;
    ret = SQLBindCol(stmt, 1, SQL_C_CHAR, &id_, sizeof(id_), NULL);
    ret = SQLBindCol(stmt, 2, SQL_C_CHAR, name, sizeof(name), NULL);
    ret = SQLBindCol(stmt, 3, SQL_C_CHAR, author, sizeof(author), NULL);
    ret = SQLBindCol(stmt, 4, SQL_C_LONG, &publisher_id, sizeof(publisher_id), NULL);
    ret = SQLBindCol(stmt, 5, SQL_C_LONG, &publish_year, sizeof(publish_year), NULL);
    ret = SQLBindCol(stmt, 6, SQL_C_LONG, &pages, sizeof(pages), NULL);
    ret = SQLBindCol(stmt, 7, SQL_C_DOUBLE, &price, sizeof(price), NULL);
    ret = SQLBindCol(stmt, 8, SQL_C_LONG, &copy_amount, sizeof(copy_amount), NULL);

    ret = SQLFetch(stmt);
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        Publisher publisher;
        publisher = publisherMapper.getByID(publisher_id);
        book.setIsbn((const char*)id_);
        book.setBookName((const char*)name);
        book.setAuthor((const char*)author);
        book.setPublishYear(publish_year);
        book.setPublisher(publisher);
        book.setPages(pages);
        book.setPrice(price);
        book.setCopyAmount(copy_amount);
    }
    SQLFreeStmt(stmt, SQL_CLOSE);
    return book;


}

void BookMapper::remove(Book &book) {
    stringstream ss;
    if (book.getIsbn() != " ") {
        ss << "DELETE FROM books WHERE isbn = '" << book.getIsbn() << "';";
    }
    string query = ss.str();
    db.executeQuery(query);
}
