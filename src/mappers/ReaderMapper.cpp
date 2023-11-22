#pragma once
//
// Created by Eldo on 19.10.2023.
//

#include "ReaderMapper.h"
#include <iostream>
#include <sstream>
using namespace std;

ReaderMapper::ReaderMapper(DataBase& db) : db(db) {

}


void ReaderMapper::update(Reader& reader) {
	stringstream ss;
	//if (reader.getCardNum() != -1) {
		ss << "UPDATE readers SET " << "last_name = '" << reader.getLastName() << "', first_name = '" << reader.getFirstName() << "', middle_name = '" << reader.getMiddleName() << "', birth_date = '" << reader.getBirthDate().getString() << "', phone_number = '" << reader.getPhoneNumber() << "' WHERE reader_card_num = " << reader.getCardNum() << ";";
	//}
	string query = ss.str();
	db.executeQuery(query);
}

void ReaderMapper::save(Reader& reader) {
	stringstream ss;
	//if (reader.getCardNum() == -1) {
		ss << "INSERT INTO readers VALUES(" << "DEFAULT, '" << reader.getLastName() << "', '" << reader.getFirstName() << "', '" << reader.getMiddleName() << "', '" << reader.getBirthDate().getString() << "', '" << reader.getPhoneNumber() <<"');";
	//}
	//else {

	//}
	string query = ss.str();
	db.executeQuery(query);

}

vector<Reader> ReaderMapper::getAll() {
	vector<Reader> readers;
	stringstream ss;
	ss << "SELECT*FROM readers;";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER card_num;
	SQLCHAR first_name[255];
	SQLCHAR last_name[255];
	SQLCHAR middle_name[255];
	SQLCHAR birth_date[255];
	SQLCHAR phone_number[255];
	SQLRETURN ret;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &card_num, sizeof(card_num), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, last_name , sizeof(first_name), NULL);
	ret = SQLBindCol(stmt, 3, SQL_C_CHAR, first_name, sizeof(last_name), NULL);
	ret = SQLBindCol(stmt, 4, SQL_C_CHAR, middle_name, sizeof(middle_name), NULL);
	ret = SQLBindCol(stmt, 5, SQL_C_CHAR, birth_date, sizeof(birth_date), NULL);
	ret = SQLBindCol(stmt, 6, SQL_C_CHAR, phone_number, sizeof(phone_number), NULL);

	ret = SQLFetch(stmt);
	while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		Reader reader;
		reader.setCardNum(card_num);
		reader.setFirstName((const char*)(first_name));
		reader.setLastName((const char*)(last_name));
		reader.setMiddleName((const char*)(middle_name));
		Date date((const char*)(birth_date));
		reader.setBirthDate(date);
		reader.setPhoneNumber((const char*)(phone_number));
		readers.push_back(reader);
		ret = SQLFetch(stmt);
	}
	SQLFreeStmt(stmt, SQL_CLOSE);

	return readers;
}

Reader ReaderMapper::getByCardNum(int cardNum) {
	Reader reader;
	stringstream ss;
	ss << "SELECT*FROM readers WHERE reader_card_num = " << cardNum << ";";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER card_num;
	SQLCHAR first_name[255];
	SQLCHAR last_name[255];
	SQLCHAR middle_name[255];
	SQLCHAR birth_date[255];
	SQLCHAR phone_number[255];
	SQLRETURN ret;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &card_num, sizeof(card_num), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, first_name, sizeof(first_name), NULL);
	ret = SQLBindCol(stmt, 3, SQL_C_CHAR, last_name, sizeof(last_name), NULL);
	ret = SQLBindCol(stmt, 4, SQL_C_CHAR, middle_name, sizeof(middle_name), NULL);
	ret = SQLBindCol(stmt, 5, SQL_C_CHAR, birth_date, sizeof(birth_date), NULL);
	ret = SQLBindCol(stmt, 6, SQL_C_CHAR, phone_number, sizeof(phone_number), NULL);

	ret = SQLFetch(stmt);
	
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		reader.setCardNum(card_num);
		reader.setFirstName((const char*)(first_name));
		reader.setLastName((const char*)(last_name));
		reader.setMiddleName((const char*)(middle_name));
		Date date((const char*)(birth_date));
		reader.setBirthDate(date);
		reader.setPhoneNumber((const char*)(phone_number));
		ret = SQLFetch(stmt);
	}
	SQLFreeStmt(stmt, SQL_CLOSE);
	return reader;
}



void ReaderMapper::remove(Reader& reader) {
	stringstream ss;
	if (reader.getCardNum() != -1) {
		ss << "DELETE FROM readers WHERE reader_card_num = " << reader.getCardNum() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}
