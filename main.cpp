#include <iostream>
#include <string>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include<sqltypes.h>
#include "DataBase.h"

#define NAME_LEN 50
#define PHONE_LEN 50

//SQLCHAR      szName[NAME_LEN], szPhone[PHONE_LEN];


void createTables() {


}



int main()
{
    setlocale(LC_ALL, "Russian");

//    SQLHENV henv;
//    SQLHDBC hdbc;
//    //std::cout<<"hello!";
//    //SQLHSTMT stmt;
//    SQLRETURN ret;
//    //char* retVal[256];
//    SQLINTEGER  cbData;
//
//    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
//    ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
//    ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
//
//    SQLCHAR* dsn = (SQLCHAR*)"PostgreSQL35W"; // Data Source Name (DSN)
//    SQLCHAR* user = (SQLCHAR*)"kodya";
//    SQLCHAR* pass = (SQLCHAR*)"123";
//    //*** Connecting to remote PostgreSQL database
//
//    ret = SQLConnect(hdbc, dsn, SQL_NTS, user, SQL_NTS, pass, SQL_NTS);
//    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
//        // Connection successful
//        printf("Connection successful\n");
//    } else {
//        // Connection failed
//        printf("Connection failed\n");
//    }
//
//    SQLHSTMT hstmt;
//
//    SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

DataBase dataBase ("PostgreSQL35W", "kodya", "123");
dataBase.connect();

}