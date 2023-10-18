//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_DATABASE_H
#define LIBRARYAPP_DATABASE_H
#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include<sqltypes.h>
#include <vector>

using namespace std;

class DataBase {
public:
    DataBase(const string &dsn, const string &user, const string &password);
    void connect();
    vector<vector<string>> getResults();
    void createTables();
    SQLHSTMT executeQuery(string query);

private:
    string dsn;
    string user;
    string password;
    SQLHENV env;
    SQLHDBC dbc;
    SQLHSTMT stmt;




};


#endif //LIBRARYAPP_DATABASE_H
