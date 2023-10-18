//
// Created by Eldo on 19.10.2023.
//

#include "DataBase.h"

DataBase::DataBase(const string &dsn, const string &user, const string &password) : dsn(dsn), user(user),
                                                                                    password(password) {
    connect();
    createTables();


}

void DataBase::connect() {
    SQLRETURN ret;
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    ret = SQLConnect(dbc, (SQLCHAR *) dsn.c_str(), SQL_NTS, (SQLCHAR *) user.c_str(), SQL_NTS,
                     (SQLCHAR *) password.c_str(), SQL_NTS);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        printf("Connection successful\n");
    } else {
        printf("Connection failed\n");
    }

    ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        printf("Alloc successful\n");
    } else {
        printf("Alloc failed\n");
    }
}

void DataBase::createTables() {
    SQLRETURN ret;
    executeQuery("CREATE TABLE IF NOT EXISTS books (\n"
                 "    isbn varchar NOT NULL PRIMARY KEY,\n"
                 "    book_name varchar NOT NULL,\n"
                 "    author varchar NOT NULL,\n"
                 "    publisher varchar,\n"
                 "    publish_year integer,\n"
                 "    publish_place varchar,\n"
                 "    pages integer NOT NULL,\n"
                 "    price numeric NOT NULL\n"
                 ");");

    executeQuery("CREATE TABLE IF NOT EXISTS readers (\n"
                 "    reader_card_num serial NOT NULL PRIMARY KEY,\n"
                 "    last_name varchar NOT NULL,\n"
                 "    first_name varchar NOT NULL,\n"
                 "    middle_name varchar,\n"
                 "    birth_date date,\n"
                 "    phone_number varchar\n"
                 ");");
    executeQuery("CREATE TABLE IF NOT EXISTS copies (\n"
                 "    inventory_num integer NOT NULL PRIMARY KEY,\n"
                 "    isbn varchar NOT NULL,\n"
                 "    reader_card_num integer,\n"
                 "    borrow_date date,\n"
                 "    return_date date,\n"
                 "    FOREIGN KEY (isbn) REFERENCES books (isbn),\n"
                 "    FOREIGN KEY (reader_card_num) REFERENCES readers (reader_card_num)\n"
                 ");");
    executeQuery("CREATE TABLE IF NOT EXISTS themes (\n"
                 "  theme_id serial NOT NULL PRIMARY KEY,\n"
                 "  theme_name varchar\n"
                 ");");
    executeQuery("\n"
                 "CREATE TABLE IF NOT EXISTS books_themes(\n"
                 "    isbn varchar NOT NULL,\n"
                 "    theme_id integer NOT NULL,\n"
                 "    FOREIGN KEY (isbn) REFERENCES books (isbn),\n"
                 "    FOREIGN KEY (theme_id) REFERENCES themes (theme_id)\n"
                 ");");
}

SQLHSTMT DataBase::executeQuery(string query) {
    SQLRETURN ret;
    ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt); // Выделение памяти для statement
    if (ret != SQL_SUCCESS) {
        cout << "Error Alloc \n";
        return nullptr;
    }
    ret = SQLExecDirect(stmt, (SQLCHAR *) query.c_str(), SQL_NTS);
    if(ret == SQL_SUCCESS) {
        return stmt;
    }else {
        return nullptr;
    }
}

vector<vector<string>> DataBase::getResults() {


    return vector<vector<string>>();
}


