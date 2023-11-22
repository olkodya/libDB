#pragma once
//
// Created by Eldo on 19.10.2023.
//

#include "CopyMapper.h"
#include <iostream>
#include <sstream>
using namespace std;

CopyMapper::CopyMapper(DataBase& db, BookMapper& bookMapper, ReaderMapper& readerMapper) : db(db), readerMapper(readerMapper), bookMapper(bookMapper) {

}


void CopyMapper::update(Copy& copy, bool flag) {
	stringstream ss;
	if (flag) {
		ss << "UPDATE copies SET " << "isbn = '" << copy.getBook()->getIsbn()
			<< "', reader_card_num = " << copy.getReader()->getCardNum()
			<< ", borrow_date = '" << copy.getBorrowDate().getStringTime()
			<< "', return_date = NULL WHERE inventory_num = " << copy.getInventoryNum() << ";";
			
	}
	else {
		ss << "UPDATE copies SET " << "isbn = '" << copy.getBook()->getIsbn()
			<< "', reader_card_num = " << copy.getReader()->getCardNum()
			<< ", borrow_date = '" << copy.getBorrowDate().getStringTime()
			<< "', return_date = '" << copy.getReturnDate().getStringTime() <<  "' WHERE inventory_num = " << copy.getInventoryNum() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}

void CopyMapper::save(Copy& copy) {
	stringstream ss;
	//if (copy.getInventoryNum() == -1) {
		ss << "INSERT INTO copies VALUES(" << copy.getInventoryNum() << ", " << copy.getBook()->getIsbn() << ", NULL, NULL, NULL);";
	/*}
	else {

	}*/
	string query = ss.str();
	db.executeQuery(query);

}

vector<Copy> CopyMapper::getAll() {
	vector<Copy> copies;
	stringstream ss;
	ss << "SELECT*FROM copies;";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER id_;
	SQLCHAR isbn[255];
	SQLINTEGER reader_id;
	SQLCHAR borrow_date[255];
	SQLCHAR return_date[255];
	SQLRETURN ret;
	SQLLEN indicator1, indicator2, indicator3;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &id_, sizeof(id_), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, isbn, sizeof(isbn), NULL);
	ret = SQLBindCol(stmt, 3, SQL_C_LONG, &reader_id, sizeof(reader_id), &indicator1);
	ret = SQLBindCol(stmt, 4, SQL_C_CHAR, borrow_date, sizeof(borrow_date), &indicator2);
	ret = SQLBindCol(stmt, 5, SQL_C_CHAR, return_date, sizeof(return_date), &indicator3);

	ret = SQLFetch(stmt);
	while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		Copy copy;
		copy.setInventoryNum(id_); 
		if (indicator2 == SQL_NULL_DATA) {
			string str = " ";
			Date borrowDate(str);
			copy.setBorrowDate(borrowDate);
		}
		else {
			Date borrowDate((const char*)(borrow_date));
			copy.setBorrowDate(borrowDate);
		}
		if (indicator3 == SQL_NULL_DATA) {
			string str = " ";
			Date returnDate(str);
			returnDate.setStringTime(str);
			copy.setReturnDate(returnDate);
		}
		else {
			Date returnDate((const char*)(return_date));
			copy.setReturnDate(returnDate);

		}
		

		if (indicator1 == SQL_NULL_DATA) {
			copy.setReader(nullptr);
		}
		else {
			Reader reader = readerMapper.getByCardNum(reader_id);
			copy.setReader(&reader);
		}
		Book book = bookMapper.getByIsbn((const char*)isbn);
		copy.setBook(&book);
		copies.push_back(copy);
		ret = SQLFetch(stmt);
	}
	SQLFreeStmt(stmt, SQL_CLOSE);
	return copies;
}



Copy CopyMapper::getByInvNum(int id) {
	Copy copy;
	stringstream ss;
	ss << "SELECT*FROM copies WHERE inventory_num = " << id << ";";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER id_;
	SQLCHAR isbn[255];
	SQLINTEGER reader_id;
	SQLCHAR borrow_date[255];
	SQLCHAR return_date[255];
	SQLRETURN ret;
	SQLLEN indicator1, indicator2, indicator3;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &id_, sizeof(id_), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, isbn, sizeof(isbn), NULL);
	ret = SQLBindCol(stmt, 3, SQL_C_LONG, &reader_id, sizeof(reader_id), &indicator1);
	ret = SQLBindCol(stmt, 4, SQL_C_CHAR, borrow_date, sizeof(borrow_date), &indicator2);
	ret = SQLBindCol(stmt, 5, SQL_C_CHAR, return_date, sizeof(return_date), &indicator3);

	ret = SQLFetch(stmt);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		copy.setInventoryNum(id_);
		if (indicator2 == SQL_NULL_DATA) {
			string str = " ";
			Date borrowDate(str);
			copy.setBorrowDate(borrowDate);
		}
		else {
			Date borrowDate((const char*)(borrow_date));
			copy.setBorrowDate(borrowDate);
		}
		if (indicator3 == SQL_NULL_DATA) {
			string str = " ";
			Date returnDate(str);
			copy.setReturnDate(returnDate);
		}
		else {
			Date returnDate((const char*)(return_date));
			copy.setReturnDate(returnDate);
		}
		if (indicator1 == SQL_NULL_DATA) {
			copy.setReader(nullptr);
		}
		else {
			Reader reader = readerMapper.getByCardNum(reader_id);
			copy.setReader(&reader);
		}
		Book book = bookMapper.getByIsbn((const char*)isbn);
		copy.setBook(&book);
		ret = SQLFetch(stmt); 
		
	}
	SQLFreeStmt(stmt, SQL_CLOSE);
	return copy;
}


void CopyMapper::remove(Copy& copy) {
	stringstream ss;
	if (copy.getInventoryNum() != -1) {
		ss << "DELETE FROM copies WHERE inventory_num = " << copy.getInventoryNum() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}
