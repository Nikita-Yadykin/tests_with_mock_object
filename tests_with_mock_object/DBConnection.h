#pragma once
#include <string>

class DBConnection {
public:
    virtual ~DBConnection() {}
    virtual bool open() = 0;
    virtual bool close() = 0;
    virtual bool execQuery(const std::string& query) = 0;
};
