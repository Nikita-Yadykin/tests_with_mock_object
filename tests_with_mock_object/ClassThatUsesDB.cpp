#include "ClassThatUsesDB.h"

bool ClassThatUsesDB::openConnection() {
    return dbConnection_.open();
}

bool ClassThatUsesDB::useConnection(const std::string& query) {
    return dbConnection_.execQuery(query);
}

bool ClassThatUsesDB::closeConnection() {
    return dbConnection_.close();
}
