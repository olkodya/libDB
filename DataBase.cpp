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


}

void DataBase::executeQuery(string query) {
    SQLRETURN ret;
    ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt); // Выделение памяти для statement
    if (ret != SQL_SUCCESS) {
        "Error Alloc";
        return;
    }

    ret = SQLExecDirect(stmt, (SQLCHAR *) query.c_str(), SQL_NTS);

}


