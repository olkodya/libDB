#pragma once
#ifndef LIBRARYAPP_PUBLISHER_H
#define LIBRARYAPP_PUBLISHER_H

#include <iostream>
#include <iomanip>


using namespace std;

class Publisher {
public:
    Publisher();

    void setID(const int& id);

    void setPublisherName(const string& publisherName);

    void setPlace(const string& place);

    ~Publisher();

    const int& getID() const;

    const string& getPublisherName() const;

    const string& getPlace() const;

    void print(int i);


private:
    int id;
    string publisherName;
    string place;
};


#endif //LIBRARYAPP_PUBLISHER_H