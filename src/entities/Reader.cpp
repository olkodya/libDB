//
// Created by Eldo on 19.10.2023.
//

#include "Reader.h"


Reader::Reader() {
    cardNum = -1;
    lastName = " ";
    firstName = " ";
    middleName = " ";
    phoneNumber = " ";

};

Reader::~Reader() = default;

const int& Reader::getCardNum() const {
    return cardNum;
}

const string& Reader::getLastName() const {
    return lastName;
}

const string& Reader::getFirstName() const {
    return firstName;
}

const string& Reader::getMiddleName() const {
    return middleName;
}

const Date& Reader::getBirthDate() const {
    return birthDate;
}

const string& Reader::getPhoneNumber() const {
    return phoneNumber;
}


void Reader::setCardNum(const int& cardNum) {
    Reader::cardNum = cardNum;
}

void Reader::setLastName(const string & lastName) {
    Reader::lastName = lastName;
}

void Reader::setFirstName(const string& firstName) {

    Reader::firstName = firstName;
}

void Reader::setMiddleName(const string& middleName) {
    Reader::middleName = middleName;
}

void Reader::setBirthDate(const Date& date) {
    this->birthDate = Date(date.getYear(), date.getDay(), date.getMonth());
}

void Reader::setPhoneNumber(const string& phoneNumber) {
    Reader::phoneNumber = phoneNumber;
}

void Reader::print(int i) {
    std::cout << std::left << std::setw(10) << i + 1 << std::setw(20) << cardNum << std::setw(20) << lastName << std::setw(20) << firstName << std::setw(20) << middleName << std::setw(20) << birthDate.toString() << std::setw(20) << phoneNumber << std::endl;

}