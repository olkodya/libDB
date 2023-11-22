#ifndef LIBRARYAPP_READERMAPPER_H
#define LIBRARYAPP_READERMAPPER_H


#include "../entities/Reader.h"
#include "../DataBase.h"

class ReaderMapper {
public:
    ReaderMapper(DataBase& db);

    void update(Reader& reader);

    void save(Reader& reader);

    void remove(Reader& reader);

    vector<Reader> getAll();

    Reader getByCardNum(int cardNum);

private:
    DataBase& db;

};


#endif //LIBRARYAPP_READERMAPPER_H
