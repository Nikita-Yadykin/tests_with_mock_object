#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ClassThatUsesDB.h"
#include "MockDBConnection.h"

using namespace testing;

TEST(ClassThatUsesDBTest, OpenConnection) {
    // ������� ���-������ DBConnection
    MockDBConnection dbConnection;

    // ������� ��������� ClassThatUsesDB, ��������� ���-������ � �������� �����������
    ClassThatUsesDB classThatUsesDB(dbConnection);

    // ������� ����� ������ open � ������������� ����������� � ������������ ���������
    EXPECT_CALL(dbConnection, open())
        .WillOnce(Return(true));

    // �������� ����� openConnection � ���������, ��� �� �������� ��������������� ����� ���-�������
    ASSERT_TRUE(classThatUsesDB.openConnection());
}

TEST(ClassThatUsesDBTest, UseConnection) {
    // ������� ���-������ DBConnection
    MockDBConnection dbConnection;

    // ������� ��������� ClassThatUsesDB, ��������� ���-������ � �������� �����������
    ClassThatUsesDB classThatUsesDB(dbConnection);

    // ������� ����� ������ execQuery � ������������� ����������� � ������������ ���������
    EXPECT_CALL(dbConnection, execQuery("SELECT * FROM table"))
        .WillOnce(Return(true));

    // �������� ����� useConnection � ���������, ��� �� �������� ��������������� ����� ���-�������
    ASSERT_TRUE(classThatUsesDB.useConnection("SELECT * FROM table"));
}

TEST(ClassThatUsesDBTest, CloseConnection) {
    // ������� ���-������ DBConnection
    MockDBConnection dbConnection;

    // ������� ��������� ClassThatUsesDB, ��������� ���-������ � �������� �����������
    ClassThatUsesDB classThatUsesDB(dbConnection);

    // ������� ����� ������ close � ������������� ����������� � ������������ ���������
    EXPECT_CALL(dbConnection, close())
        .WillOnce(Return(true));

    // �������� ����� closeConnection � ���������, ��� �� �������� ��������������� ����� ���-�������
    ASSERT_TRUE(classThatUsesDB.closeConnection());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
