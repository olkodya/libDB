//
// Created by Eldo on 19.10.2023.
//

#ifndef LIBRARYAPP_THEME_H
#define LIBRARYAPP_THEME_H
#include <iostream>
#include <iomanip>
using namespace std;



class Theme {
public:
    Theme();

    void setID(const int& id);

    void setThemeName(const string& themeName);
   
    void print(int i);

    ~Theme();

    const int& getID() const;

    const string& getThemeName() const;


private:
    int id;
    string themeName;
};



#endif //LIBRARYAPP_THEME_H
