
#include "../entities/Copy.h"
#include "../DataBase.h"
#include "BookMapper.h"
#include "ReaderMapper.h"

class CopyMapper {
public:
    CopyMapper(DataBase& db, BookMapper& bookMapper, ReaderMapper& readerMapper);

    void update(Copy& copy, bool flag);

    void save(Copy& copy);

    void remove(Copy& copy);

    vector<Copy> getAll();

    Copy getByInvNum(int id);

private:
    DataBase& db;
    BookMapper& bookMapper;
    ReaderMapper& readerMapper;

};


