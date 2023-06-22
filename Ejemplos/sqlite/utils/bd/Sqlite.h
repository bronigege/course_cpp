//
// Created by Bruno Gómez García on 20/6/23.
//

#ifndef SQLITE_SQLITE_H
#define SQLITE_SQLITE_H
#include <sqlite3.h>
#include "../logger/Logger.h"


class Sqlite {
private:
    sqlite3* db{};
    Logger::Logger* logger;
    void disconnect();
public:
    explicit Sqlite(Logger::Logger* logger);
    bool connect();
    bool executeQuerie(const char* querie);
    ~Sqlite();
};


#endif //SQLITE_SQLITE_H
