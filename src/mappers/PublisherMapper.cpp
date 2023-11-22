#pragma once
//
// Created by Eldo on 19.10.2023.
//

#include "PublisherMapper.h"
#include <iostream>
#include <sstream>
using namespace std;

PublisherMapper::PublisherMapper(DataBase& db) : db(db) {

}


void PublisherMapper::update(Publisher& publisher) {
	stringstream ss;
	if (publisher.getID() != -1) {
		ss << "UPDATE publishers SET " << "publisher_name = '" << publisher.getPublisherName()
			<< "', publish_place='"
			<< publisher.getPlace() << "'"
			<< " WHERE publisher_id=" << publisher.getID() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}

void PublisherMapper::save(Publisher& publisher) {
	stringstream ss;
	if (publisher.getID() == -1) {
		ss << "INSERT INTO publishers VALUES(" << "DEFAULT, " << "'" << publisher.getPublisherName() << "', '" << publisher.getPlace() << "');";

	}
	else {

	}
	string query = ss.str();
	db.executeQuery(query);

}

vector<Publisher> PublisherMapper::getAll() {
	vector<Publisher> publishers;
	stringstream ss;
	ss << "SELECT*FROM publishers;";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER id_;
	SQLCHAR name[255];
	SQLCHAR place[255];
	SQLRETURN ret;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &id_, sizeof(id_), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, name, sizeof(name), NULL);
	ret = SQLBindCol(stmt, 3, SQL_C_CHAR, place, sizeof(place), NULL);
	ret = SQLFetch(stmt);
	while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		Publisher publisher;
		publisher.setID(id_);
		publisher.setPublisherName((const char*)(name));
		publisher.setPlace((const char*)(place));
		publishers.push_back(publisher);
		ret = SQLFetch(stmt);
	}
	SQLFreeStmt(stmt, SQL_CLOSE);

	return publishers;
}

Publisher PublisherMapper::getByID(int id) {
	Publisher publisher;
	stringstream ss;
	ss << "SELECT*FROM publishers WHERE publisher_id = " << id << ";";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER id_;
	SQLCHAR name[255];
	SQLCHAR place[255];
	SQLRETURN ret;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &id_, sizeof(id_), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, name, sizeof(name), NULL);
	ret = SQLBindCol(stmt, 3, SQL_C_CHAR, place, sizeof(place), NULL);
	ret = SQLFetch(stmt);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		publisher.setID(id_);
		publisher.setPublisherName((const char*)(name));
		publisher.setPlace((const char*)(place));
	}
	SQLFreeStmt(stmt, SQL_CLOSE);
	return publisher;
}

void PublisherMapper::remove(Publisher& publisher) {
	stringstream ss;
	if (publisher.getID() != -1) {
		ss << "DELETE FROM publishers WHERE publisher_id = " << publisher.getID() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}
