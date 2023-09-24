#pragma once
#include "gmock/gmock.h"
#include "DBConnection.h"

class MockDBConnection : public DBConnection {
public:
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(bool, close, (), (override));
    MOCK_METHOD(bool, execQuery, (const std::string& query), (override));
};
