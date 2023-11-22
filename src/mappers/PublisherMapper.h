#ifndef LIBRARYAPP_PUBLISHERMAPPER_H
#define LIBRARYAPP_PUBLISHERMAPPER_H


#include "../entities/Book.h"
#include "../DataBase.h"

class PublisherMapper {
public:
    PublisherMapper(DataBase& db);

    void update(Publisher& publisher);

    void save(Publisher& publisher);

    void remove(Publisher& publisher);

    vector<Publisher> getAll();

    Publisher getByID(int id);

private:
    DataBase& db;

};


#endif //LIBRARYAPP_BOOKMAPPER_H
