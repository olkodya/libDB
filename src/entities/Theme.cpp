//
// Created by Eldo on 19.10.2023.
//

#include "Theme.h"

Theme::Theme() {
    id = -1;
    themeName = " ";
};

Theme::~Theme() = default;

const int& Theme::getID() const {
    return id;  
}

const string& Theme::getThemeName() const {
    return themeName;
}



void Theme::setID(const int& id) {
    Theme::id = id;
}

void Theme::setThemeName(const string & themeName) {
    Theme::themeName = themeName;
}

void Theme::print(int i) {
    std::cout << std::left << std::setw(10) << i + 1 << std::setw(20) << themeName << std::endl;

}



