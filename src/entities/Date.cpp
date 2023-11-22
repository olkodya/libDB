#include "Date.h"
#include <ctime>
#include <sstream>
#include <string>


Date::Date() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    year = 1900 + ltm->tm_year; 
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    min = ltm->tm_min;
    str = Date::toString();
    str2 = Date::toStringTime();
};



bool Date::isDateValid(const int day, const int  month, const int year) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    if (year < 1900 || year > 1900 + ltm->tm_year)
        return false;
    if (month > 12 || month < 1)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
        return false; //30 days in Apr, Jun, Sen, Nov
    if (month == 2) {
        if (day > 29)
            return false;
        if (day == 29 && ((year % 100) % 4 != 0))
            return false;
    } //Feb    
    return true;
}


Date::Date(int year, int day, int month) {
    if (isDateValid(day, month, year)) {
        Date::year = year;
        Date::day = day;
        Date::month = month;
        hour = 0;
        min = 0;
        
    }
    else {
        cout << "invalid date\n";
        time_t now = time(0);
        tm* ltm = localtime(&now);
        Date::year = 1900 + ltm->tm_year;
        Date::month = 1 + ltm->tm_mon;
        Date::day = ltm->tm_mday;
        hour = ltm->tm_hour;
        min = ltm->tm_min;
    }
    str = toString();
    str2 = toStringTime();
}

Date::Date(int year, int day, int month, int hour, int min) {
        Date::year = year;
        Date::day = day;
        Date::month = month;
        Date::hour = hour;
        Date::min = min;
        str = toString();
        str2 = toStringTime();
}

Date::Date(string date) {
    if (date == " ") {
        str2 = " ";
        str = " ";
        return;
    }        
    const char* cstr = date.c_str();
    year = stoi(date.substr(0, 4));
    month = stoi(date.substr(5, 2));
    day = stoi(date.substr(8, 2));
    hour = 0;
    min = 0;
    str = Date::toString();
    if (date.length() > 10) {
        hour  = stoi(date.substr(11, 2));
        min = stoi(date.substr(14, 2));
	}
    str2 = Date::toStringTime();
}

Date::~Date() = default;

const int& Date::getYear() const {
    return year;
}

const int& Date::getMonth() const {
    return month;
}

const int& Date::getDay() const {
    return day;
}

const int& Date::getHour() const {
    return hour;
}

const int& Date::getMin() const {
    return min;
}


const string& Date::getString() const {
    return str;
}

const string& Date::getStringTime() const {
    return str2;
}


void Date::setYear(const int year) {
   if(isDateValid(Date::day, Date::month, year))
        Date::year = year;
   else
        cout << "Ivalid date";
}

void Date::setMonth(const int month) {
    if(isDateValid(Date::day, month, Date::year))
        Date::month = month;
    else
        cout << "Ivalid date";
}

void Date::setDay(const int day) {
    if (isDateValid(day, Date::month, Date::year))
        Date::day = day;
    else
        cout << "Ivalid date";
}

string Date::toString() {
    stringstream ss;
    stringstream ds;
    stringstream ms;
    if (day < 10)
        ds << 0 << day;
    else
        ds << day;
    if(month < 10)
        ms << 0 << month;
    else
        ms << month;
    ss << year << "-" << ms.str() << "-" << ds.str();
    return ss.str();
}

string Date::toStringTime() {
    stringstream ss;
    ss << str << " ";
    if (hour < 10)
        ss << 0 << hour;
    else
        ss << hour;
    ss << ":";
    if (min < 10)
        ss << 0 << min;
    else
        ss << min;
    return ss.str();
}

void Date::setStringTime(string& str2) {
    this->str2 = str2;
}
