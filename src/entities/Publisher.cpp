//
// Created by Eldo on 19.10.2023.
//

#include "Publisher.h"

Publisher::Publisher() {
    id = -1;
    publisherName = " ";
    place = " ";
};

Publisher::~Publisher() = default;

const int& Publisher::getID() const {
    return id;
}

const string& Publisher::getPublisherName() const {
    return publisherName;
}

const string& Publisher::getPlace() const {
    return place;
}



void Publisher::setID(const int & id) {
    Publisher::id = id;
}

void Publisher::setPublisherName(const string & publisherName) {
    Publisher::publisherName = publisherName;
}

void Publisher::setPlace(const string & place) {
    Publisher::place = place;
}

void Publisher::print(int i) {
    std::cout << std::left << std::setw(10) << i + 1 << std::setw(20) << publisherName << std::setw(20) << place << std::endl;

}