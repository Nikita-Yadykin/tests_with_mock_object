#pragma once
#include <string>
#include "DBConnection.h"

class ClassThatUsesDB {
public:
    ClassThatUsesDB(DBConnection& dbConnection) : dbConnection_(dbConnection) {}

    bool openConnection();
    bool useConnection(const std::string& query);
    bool closeConnection();

private:
    DBConnection& dbConnection_;
};
