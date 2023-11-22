//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_READERS_H
#define LIBRARYAPP_READERS_H
#include <iostream>
#include <iomanip>
#include "Date.h"


using namespace std;

class Reader {
public:
    Reader();

    void setCardNum(const int& cardNum);

    void setLastName(const string& lastName);

    void setFirstName(const string& firstName);

    void setMiddleName(const string& middleName);

    void setBirthDate(const Date& birthDate);


    void setPhoneNumber(const string& phoneNumber);

    void print(int i);



    ~Reader();

    const int& getCardNum() const;

    const string& getLastName() const;

    const string& getFirstName() const;

    const string& getMiddleName() const;

    const Date& getBirthDate() const;


    const string& getPhoneNumber() const;


private:
    int cardNum;
    string lastName;
    string firstName;
    string middleName;
    Date birthDate;
    string phoneNumber;
};


#endif //LIBRARYAPP_READERS_H
