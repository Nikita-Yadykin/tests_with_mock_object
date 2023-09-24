#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ClassThatUsesDB.h"
#include "MockDBConnection.h"

using namespace testing;

TEST(ClassThatUsesDBTest, OpenConnection) {
    // Создаем мок-объект DBConnection
    MockDBConnection dbConnection;

    // Создаем экземпляр ClassThatUsesDB, передавая мок-объект в качестве зависимости
    ClassThatUsesDB classThatUsesDB(dbConnection);

    // Ожидаем вызов метода open с определенными аргументами и возвращаемым значением
    EXPECT_CALL(dbConnection, open())
        .WillOnce(Return(true));

    // Вызываем метод openConnection и проверяем, что он вызывает соответствующий метод мок-объекта
    ASSERT_TRUE(classThatUsesDB.openConnection());
}

TEST(ClassThatUsesDBTest, UseConnection) {
    // Создаем мок-объект DBConnection
    MockDBConnection dbConnection;

    // Создаем экземпляр ClassThatUsesDB, передавая мок-объект в качестве зависимости
    ClassThatUsesDB classThatUsesDB(dbConnection);

    // Ожидаем вызов метода execQuery с определенными аргументами и возвращаемым значением
    EXPECT_CALL(dbConnection, execQuery("SELECT * FROM table"))
        .WillOnce(Return(true));

    // Вызываем метод useConnection и проверяем, что он вызывает соответствующий метод мок-объекта
    ASSERT_TRUE(classThatUsesDB.useConnection("SELECT * FROM table"));
}

TEST(ClassThatUsesDBTest, CloseConnection) {
    // Создаем мок-объект DBConnection
    MockDBConnection dbConnection;

    // Создаем экземпляр ClassThatUsesDB, передавая мок-объект в качестве зависимости
    ClassThatUsesDB classThatUsesDB(dbConnection);

    // Ожидаем вызов метода close с определенными аргументами и возвращаемым значением
    EXPECT_CALL(dbConnection, close())
        .WillOnce(Return(true));

    // Вызываем метод closeConnection и проверяем, что он вызывает соответствующий метод мок-объекта
    ASSERT_TRUE(classThatUsesDB.closeConnection());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
