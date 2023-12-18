#include "gtest/gtest.h"
#include "task.h"
#include "taskList.h"
#include "mergeSort.h"
#include "prioritySort.h"
#include <string>
#include <vector>
#include <iostream>

// 3 Tests for a tasklist that has a difference in years between the dates and priorities
TEST(testPrioritySort, differentYearsDifferentPriorities1) {// Tests if the first value is High
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
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2022";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task first = listVector.at(0);

    EXPECT_EQ(first.getPriority(), 'H');
}
TEST(testPrioritySort, differentYearsDifferentPriorities2) {// Tests if the second value is Medium
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
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2022";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task second = listVector.at(1);

    EXPECT_EQ(second.getPriority(), 'M');
}
TEST(testPrioritySort, differentYearsDifferentPriorities3) {// Testing if the third value is Low
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
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2022";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task third = listVector.at(2);

    EXPECT_EQ(third.getPriority(), 'L');
}

//3 Tests for a tasklist that has a difference in months between the dates and priorities
TEST(testPrioritySort, differentMonthsDifferentPriorities1) {// Tests if the first value is High
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "12, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "10, 27, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task first = listVector.at(0);

    EXPECT_EQ(first.getPriority(), 'H');
}

TEST(testPrioritySort, differentMonthsDifferentPriorities2) {// Tests if the second value is Medium
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "12, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "10, 27, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task second = listVector.at(1);

    EXPECT_EQ(second.getPriority(), 'M');
}
TEST(testPrioritySort, differentMonthsDifferentPriorities3) {// Tests if the second value is Low
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "12, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "10, 27, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task third = listVector.at(2);

    EXPECT_EQ(third.getPriority(), 'L');
}

// 3 Tests for a tasklist that has a difference in days between the dates and priorities
TEST(testPrioritySort, differentDaysDifferentPriorities1) // Tests if the first value is High
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 28, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 26, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task first = listVector.at(0);

    EXPECT_EQ(first.getPriority(), 'H');
}
TEST(testPrioritySort, differentDaysDifferentPriorities2) // Tests if the first value is Medium
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 28, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 26, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task second = listVector.at(1);

    EXPECT_EQ(second.getPriority(), 'M');
}
TEST(testPrioritySort, differentDaysDifferentPriorities3) // Tests if the first value is Low 
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 28, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 26, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task third = listVector.at(2);

    EXPECT_EQ(third.getPriority(), 'L');
}

// 3 Tests for a tasklist that has a difference in hours between the dates and priorities
TEST(testPrioritySort, differentHoursDifferentPriorities1) // Tests if the first value is High 
{ 
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 22;
    string date = "11, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    h = 15;
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2023";
    p = 'H';
    h = 10;
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task first = listVector.at(0);

    EXPECT_EQ(first.getPriority(), 'H');
}

TEST(testPrioritySort, differentHoursDifferentPriorities2) // Tests if the first value is Medium 
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 22;
    string date = "11, 28, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    h = 15;
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 26, 2023";
    p = 'H';
    h = 10;
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task second = listVector.at(1);

    EXPECT_EQ(second.getPriority(), 'M');
}

TEST(testPrioritySort, differentHoursDifferentPriorities3) // Tests if the first value is Low 
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 22;
    string date = "11, 28, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    h = 15;
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 26, 2023";
    p = 'H';
    h = 10;
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task third = listVector.at(2);

    EXPECT_EQ(third.getPriority(), 'L');
}

// 3 Tests for a tasklist that has a difference in years between the dates but same priorities
// TEST(testPrioritySort, differentYearsSamePriority1) // Tests if the first value is the earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "11, 27, 2024";
//     char p = 'H';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 27, 2022";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task first = listVector.at(0);
//     for (int i = 0; i < listVector.size(); ++i) {
//         cout << (listVector.at(i)).getDueDate() << endl;
//         cout << (listVector.at(i)).getPriority() << endl;
//     }

//     EXPECT_EQ(first.getDueDate(), "11, 27, 2022");
// }
// TEST(testPrioritySort, differentYearsSamePriority2) // Tests if the second value is the second earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "11, 27, 2024";
//     char p = 'H';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 27, 2022";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task second = listVector.at(1);

//     EXPECT_EQ(second.getDueDate(), "11, 27, 2023");
// }
// TEST(testPrioritySort, differentYearsSamePriority3) // Tests if the third value is the third earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "11, 27, 2024";
//     char p = 'H';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 27, 2022";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task third = listVector.at(2);

//     EXPECT_EQ(third.getDueDate(), "11, 27, 2024");
// // }

//  // 3 Tests for a tasklist that has a difference in months between the dates but same priorities
// TEST(testPrioritySort, differentMonthsSamePriority1) // Tests if the first value is the earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "12, 27, 2023";
//     char p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "10, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task first = listVector.at(0);

//     EXPECT_EQ(first.getDueDate(), "10, 27, 2023");
// }
// TEST(testPrioritySort, differentMonthsSamePriority2) // Tests if the second value is the second earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "12, 27, 2023";
//     char p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "10, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task second = listVector.at(1);

//     EXPECT_EQ(second.getDueDate(), "11, 27, 2023");
// }
// TEST(testPrioritySort, differentMonthsSamePriority3) // Tests if the third value is the third earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "12, 27, 2023";
//     char p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "10, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task third = listVector.at(2);

//     EXPECT_EQ(third.getDueDate(), "12, 27, 2023");
// }

// // 3 Tests for a tasklist that has a difference in days between the dates but same priorities
// TEST(testPrioritySort, differentDaysSamePriorities1) // Tests if the first value is the earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "11, 28, 2023";
//     char p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 26, 2023";
//     p = 'L';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task first = listVector.at(0);

//     EXPECT_EQ(first.getDueDate(), "11, 26, 2023");
// }
// TEST(testPrioritySort, differentDaysSamePriorities2) // Tests if the second value is the second earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "11, 28, 2023";
//     char p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 26, 2023";
//     p = 'L';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task second = listVector.at(1);

//     EXPECT_EQ(second.getDueDate(), "11, 27, 2023");
// }
// TEST(testPrioritySort, differentDaysSamePriorities3) // Tests if the third value is the third earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 11;
//     string date = "11, 28, 2023";
//     char p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'M';
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 26, 2023";
//     p = 'H';
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task third = listVector.at(2);

//     EXPECT_EQ(third.getDueDate(), "11, 28, 2023");
// }

// 3 Tests for a tasklist that has a difference in hours between the dates but the same priorities
// TEST(testPrioritySort, differentHoursSamePriorities1) // Tests if the first value is the earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 22;
//     string date = "11, 27, 2023";
//     char p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'L';
//     h = 15;
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 27, 2023";
//     p = 'L';
//     h = 10;
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task first = listVector.at(0);

//     EXPECT_EQ(first.getDueDateHour(), 22);
// }
// TEST(testPrioritySort, differentHoursSamePriorities2) // Tests if the second value is the second earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 22;
//     string date = "11, 27, 2023";
//     char p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'L';
//     h = 15;
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 27, 2023";
//     p = 'L';
//     h = 10;
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task second = listVector.at(1);

//     EXPECT_EQ(second.getDueDateHour(), 15);
// }
// TEST(testPrioritySort, differentHoursSamePriorities3) // Tests if the third value is the third earliest date 
// {
//     taskList list;
//     string t = "Task 1";
//     string d = "Finish LAB";
//     int h = 22;
//     string date = "11, 27, 2023";
//     char p = 'L';
//     list.createTask(t, d, date, h, p);

//     t = "Task 2";
//     d = "Finish hw";
//     date = "11, 27, 2023";
//     p = 'M';
//     h = 15;
//     list.createTask(t, d, date, h, p);

//     t = "Task 3";
//     d = "Sleep";
//     date = "11, 27, 2023";
//     p = 'H';
//     h = 10;
//     list.createTask(t, d, date, h, p);

//     vector<Task> listVector = list.getPriorityVector();
//     Task third = listVector.at(2);

//     EXPECT_EQ(third.getDueDateHour(), 10);
// }

// 3 Tests for a tasklist that has the same dates but a difference in priorities
TEST(testPrioritySort, sameDateDifferentPriorities1) // Tests if the first value is High
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2023";
    p = 'L';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task first = listVector.at(0);

    EXPECT_EQ(first.getPriority(), 'H');
}
TEST(testPrioritySort, sameDateDifferentPriorities2) // Tests if the second value is Medium
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2023";
    p = 'L';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task second = listVector.at(1);

    EXPECT_EQ(second.getPriority(), 'M');
}
TEST(testPrioritySort, sameDateDifferentPriorities3) // Tests if the third value is Low
{
    taskList list;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2023";
    char p = 'L';
    list.createTask(t, d, date, h, p);

    t = "Task 2";
    d = "Finish hw";
    date = "11, 27, 2023";
    p = 'M';
    list.createTask(t, d, date, h, p);

    t = "Task 3";
    d = "Sleep";
    date = "11, 27, 2023";
    p = 'H';
    list.createTask(t, d, date, h, p);

    vector<Task> listVector = list.getPriorityVector();
    Task third = listVector.at(2);

    EXPECT_EQ(third.getPriority(), 'L');
}