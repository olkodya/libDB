#include <iostream>
#include <sstream>
#include "ThemeMapper.h"

using namespace std;

ThemeMapper::ThemeMapper(DataBase& db) : db(db) {

}


void ThemeMapper::update(Theme& theme) {
	stringstream ss;
	if (theme.getID() != -1) {
		ss << "UPDATE themes SET " << "theme_name = '" << theme.getThemeName() << "' WHERE theme_id = " << theme.getID() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}

void ThemeMapper::save(Theme& theme) {
	stringstream ss;
	if (theme.getID() != 0) {
		ss << "INSERT INTO themes VALUES(" << "DEFAULT, '" << theme.getThemeName() << "'" << ");";
	}
	else {

	}
	string query = ss.str();
	db.executeQuery(query);

}

vector<Theme> ThemeMapper::getAll() {
	vector<Theme> themes;
	stringstream ss;
	ss << "SELECT*FROM themes;";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER theme_id;
	SQLCHAR theme_name[255];
	SQLRETURN ret;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &theme_id, sizeof(theme_id), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, theme_name, sizeof(theme_name), NULL);
	
	ret = SQLFetch(stmt);
	while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		Theme theme;
		theme.setID(theme_id);
		theme.setThemeName((const char*)(theme_name));
		themes.push_back(theme);
		ret = SQLFetch(stmt);
	}
	SQLFreeStmt(stmt, SQL_CLOSE);

	return themes;
}

Theme ThemeMapper::getByID(int id) {
	Theme theme;
	stringstream ss;
	ss << "SELECT*FROM themes WHERE theme_id = " << id << ";";
	string query = ss.str();
	SQLHSTMT stmt = db.executeQuery(query);
	SQLINTEGER theme_id;
	SQLCHAR theme_name[255];
	SQLRETURN ret;
	ret = SQLBindCol(stmt, 1, SQL_C_LONG, &theme_id, sizeof(theme_id), NULL);
	ret = SQLBindCol(stmt, 2, SQL_C_CHAR, theme_name, sizeof(theme_name), NULL);

	ret = SQLFetch(stmt);

	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		theme.setID(theme_id);
		theme.setThemeName((const char*)theme_name);
		ret = SQLFetch(stmt);
	}
	SQLFreeStmt(stmt, SQL_CLOSE);
	return theme;
}



void ThemeMapper::remove(Theme& theme) {
	stringstream ss;
	if (theme.getID() != -1) {
		ss << "DELETE FROM themes WHERE theme_id = " << theme.getID() << ";";
	}
	string query = ss.str();
	db.executeQuery(query);
}
