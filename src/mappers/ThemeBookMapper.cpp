//
// Created by Eldo on 19.10.2023.
//
#include "ThemeBookMapper.h"
#include <iostream>
#include <sstream>
//#include <format>

using namespace std;

ThemeBookMapper::ThemeBookMapper(DataBase& db, ThemeMapper& themeMapper, BookMapper& bookMapper) : db(db), themeMapper(themeMapper), bookMapper(bookMapper) {

}



//
//void ThemeBookMapper::update(ThemeBook& themeBook) {
//    stringstream ss;
//    //if (book.getIsbn() != " ") {
//        ss << "UPDATE books SET isbn='" << themeBook.getBook()->getIsbn() << "', theme_id=" << themeBook.getBook()->getIsbn() << ";"
//    /*}*/
//    string query = ss.str();
//    cout << query << endl;
//    db.executeQuery(query);
//}
//
void ThemeBookMapper::save(ThemeBook& themeBook) {
    stringstream ss;
    ss << "INSERT INTO books_themes VALUES(" << themeBook.getBook()->getIsbn() << ", " << themeBook.getTheme()->getID() << ");";
    string query = ss.str();
    db.executeQuery(query);

}

vector<ThemeBook> ThemeBookMapper::getAll() {

    vector<ThemeBook> themeBooks;
    stringstream ss;
    ss << "SELECT*FROM books_themes;";
    string query = ss.str();
    SQLHSTMT stmt = db.executeQuery(query);
    SQLCHAR isbn[255];
    SQLINTEGER theme_id;
    SQLRETURN ret;
   
    ret = SQLBindCol(stmt, 1, SQL_C_CHAR, isbn, sizeof(isbn), NULL);
    ret = SQLBindCol(stmt, 2, SQL_C_LONG, &theme_id, sizeof(theme_id), NULL);
    ret = SQLFetch(stmt);
    while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        Book book;
        Theme theme;
        ThemeBook themeBook;
        book = bookMapper.getByIsbn((const char*)isbn);
        theme = themeMapper.getByID(theme_id);
        themeBook.setBook(&book);
        themeBook.setTheme(&theme);
        themeBooks.push_back(themeBook);
        ret = SQLFetch(stmt);
    }
    SQLFreeStmt(stmt, SQL_CLOSE);
    return themeBooks;
}

ThemeBook ThemeBookMapper::getByID(string isbn, int id) {
    ThemeBook themeBook;
    stringstream ss;
    ss << "SELECT*FROM books_themes WHERE isbn = '" << isbn << "' AND theme_id=" << id <<";";
    string query = ss.str();
    SQLHSTMT stmt = db.executeQuery(query);
    SQLCHAR isbn_[255];
    SQLINTEGER theme_id;
    SQLRETURN ret;

    ret = SQLBindCol(stmt, 1, SQL_C_CHAR, isbn_, sizeof(isbn_), NULL);
    ret = SQLBindCol(stmt, 2, SQL_C_LONG, &theme_id, sizeof(theme_id), NULL);
    ret = SQLFetch(stmt);
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        Book book;
        Theme theme;
        book = bookMapper.getByIsbn((const char*)isbn_);
        theme = themeMapper.getByID(theme_id);
        themeBook.setBook(&book);
        themeBook.setTheme(&theme);
    }
    SQLFreeStmt(stmt, SQL_CLOSE);
    return themeBook;

}
//
void ThemeBookMapper::remove(ThemeBook& ThemeBook) {
    stringstream ss;
    ss << "DELETE FROM books_themes WHERE isbn='" << ThemeBook.getBook()->getIsbn() << "' AND theme_id= "<<ThemeBook.getTheme()->getID() << ";";
    string query = ss.str();
    db.executeQuery(query);
}
