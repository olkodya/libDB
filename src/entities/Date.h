#pragma once
#include <iostream>

using namespace std;

class Date {
public:
	Date();
	Date(int year, int day, int month);
	Date(int year, int day, int month, int hour, int min);

	Date(string date);
	~Date();

    void setYear(const int year);
    void setMonth(const int month);
    void setDay(const int day);
	void setStringTime(string &str2);

    const int& getYear() const;

    const int& getMonth() const;

    const int& getDay() const;

	const int& getHour() const;

	const int& getMin() const;

	const string& getString() const;

	const string& getStringTime() const;

	string toString();

	string toStringTime();

	

	
	
	bool isDateValid(const int day, const int  month, const int year);

private:
	string str;
	string str2;
	int year;
	int month;
	int day;
	int hour;
	int min;
};