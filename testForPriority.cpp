#include "gtest/gtest.h"
#include "task.h"
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
TEST(testingPriority, testInputSizeValid) { //testing checkInputSizeValid
    Task testInputSize;
    string input = "01, 23, 2139";
    EXPECT_TRUE(testInputSize.checkInputSizeValid(input));
}

/*