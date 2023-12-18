#include "gtest/gtest.h"
#include "task.h"
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(testingDueDate, testInputSizeValid) { //testing checkInputSizeValid
    Task testInputSize;
    string input = "01, 23, 2139";
    EXPECT_TRUE(testInputSize.checkInputSizeValid(input));
}

TEST(testingDueDate, testInvalidInputSize) {
    Task testInputSize;
    string input = "01, 23, 21392";
    EXPECT_FALSE(testInputSize.checkInputSizeValid(input));
}


TEST(TestTime, testInvalidTime) {
    Task testTime;
    int time = 25;
    EXPECT_FALSE(testTime.setTime(time));
}
  
TEST(TestTime, testValidTime) {
    Task testTime;
    int time = 12;
    EXPECT_TRUE(testTime.setTime(time));
}


TEST(testingDueDate, testInputsAreNumbers) { //testing checkInputsAreNumbers
    Task testInputType;
    string input = "01, 23, 2139";
    EXPECT_TRUE(testInputType.checkInputsAreNumbers(input));
}

TEST(testingDueDate, testMMIsNotNums) {
    Task testInputType;
    string input = "oh, 23, 2139";
    EXPECT_FALSE(testInputType.checkInputsAreNumbers(input));
}

TEST(testingDueDate, testDDIsNotNums) {
    Task testInputType;
    string input = "01, no, 2139";
    EXPECT_FALSE(testInputType.checkInputsAreNumbers(input));
}

TEST(testingDueDate, testYYYYIsNotNums) {
    Task testInputType;
    string input = "01, 23, help";
    EXPECT_FALSE(testInputType.checkInputsAreNumbers(input));
}



TEST(testingDueDate, testSetGetDueDateString) {  
    //less than 7
    Task testSetGet;
    string date = "01, 02, 0003";
    testSetGet.setDueDate(date);
    EXPECT_EQ(testSetGet.getDueDate(), "01, 02, 0003");
}

TEST(testingDueDate, testSetGetDueDateHour) {  
    Task testSetGet;
    int hour = 8;
    testSetGet.setTime(hour);
    EXPECT_EQ(testSetGet.getTime(), 8);
}

TEST(testingDueDate, testSetGetDueDateVecSize) {
    Task testSetGet;
    string date = "01, 02, 0003";
    int hour = 8;
    testSetGet.setDueDate(date);
    testSetGet.setTime(hour);
    vector<int> dueDateVector = testSetGet.getNumsOfDueDateVector();
    EXPECT_EQ(dueDateVector.size(), 8);
}