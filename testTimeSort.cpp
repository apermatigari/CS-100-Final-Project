#include "gtest/gtest.h"
#include "task.h"
#include "taskList.h"
#include "timeSort.h"
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(testTimeSort, differentYears1) {
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2024";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2022";
    list.createTask(t, d, date, h, p);
    
    vector<Task> listVector = list.getTimeVector();
    Task first = listVector.at(0);

    EXPECT_EQ(first.getDueDate(), "11, 27, 2022");
}

TEST(testTimeSort, differentYears2) {
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2024";
    char p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2022";
    list.createTask(t, d, date, h, p);
    
    vector<Task> listVector = list.getTimeVector();
    Task second = listVector.at(1);

    EXPECT_EQ(second.getDueDate(), "11, 27, 2023");
}

TEST(testTimeSort, differentYears3) {
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2024";
    char p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2022";
    list.createTask(t, d, date, h, p);
    
    vector<Task> listVector = list.getTimeVector();
    Task third = listVector.at(2);

    EXPECT_EQ(third.getDueDate(), "11, 27, 2024");
}