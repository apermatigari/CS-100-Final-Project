#include "gtest/gtest.h"
#include "taskList.h"
#include <string>
 
//TESTS FOR taskList class 

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


//Creating tasks tests
TEST(creatingTaskTest, standardCreateTask) {
    taskList newTask;
    string t = "Task 1";
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2023";
    char p = 'M';
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 0); //Always return 0 when created task succesfully 
}

TEST(creatingTaskTest, errorCreateTaskWithTitle) {
    taskList newTask;
    string t = "AFjas;lkdgaljsdghalshg;klsfhgjshdfgj;shdfgajsgh;skhg; "; //random title with more than 40 characters
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2023";
    char p = 'M';
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 1); //Should return 1 to indicate incorrect title 
}

TEST(creatingTaskTest, errorCreateTaskWithdueDateHour) {
    taskList newTask;
    string t = "Task 1 "; 
    string d = "Finish LAB";
    int h = 25;                    //Incorrect time
    string date = "NOO, 11, 2023"; //Incorrect date
    char p = 'M';
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 2); //Should return 2 to indicate incorrect title 
}

TEST(creatingTaskTest, errorCreateTaskWithdueDateHour2) {
    taskList newTask;
    string t = "Task 1 "; 
    string d = "Finish LAB";
    int h = 25;                    //Incorrect time
    string date = "11, NO, 2023"; //Incorrect date
    char p = 'M';
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 2); //Should return 2 to indicate incorrect title 
}

TEST(creatingTaskTest, errorCreateTaskWithdueDateHour3) {
    taskList newTask;
    string t = "Task 1 "; 
    string d = "Finish LAB";
    int h = 25;                    //Incorrect time
    string date = "11, 10, 20oP"; //Incorrect date
    char p = 'M';
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 2); //Should return 2 to indicate incorrect title 
}

TEST(creatingTaskTest, errorCreateTaskWithDescription) {
    taskList newTask;
    string t = "Task 1 "; 
    string d = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"; //Description with longer than 100 characters
    int h = 11;
    string date = "11, 27, 2023";
    char p = 'M';
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 5); //Should return 2 to indicate incorrect description 
}

TEST(creatingTaskTest, errorCreateTaskWithPriority) {
    taskList newTask;
    string t = "Task 1"; 
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 24, 2024";
    char p = 'F';               //Not correct priority
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), 4); //Should return 1 to indicate incorrect title 
}

TEST(creatingTaskTest, errorCreateTaskWithDuplicate) {
    taskList newTask;
    string t = "Task 1"; 
    string d = "Finish LAB";
    int h = 11;
    string date = "11, 27, 2021";
    char p = 'N';
    int spare = newTask.createTask(t, d, date, h, p);
    EXPECT_EQ(newTask.createTask(t, d, date, h, p), -1); //Should return 1 to indicate incorrect title 
}




//Removing tasks tests
TEST(removingTaskTest, removingTask) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "11, 27, 2023", 11, 'N');
    newTask.createTask("Task 2", "Take out trash", "12, 27, 2023", 10, 'H');
    newTask.removeTaskInList("Task 1");
    EXPECT_FALSE(newTask.duplicateTaskInListCheck("Task 1")); //Indicates that "Task 1" does not exist inside list anymore
}

TEST(removingTaskTest, removingTaskInMiddleList) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "11, 27, 2023", 11, 'N');
    newTask.createTask("Task 2", "Take out trash", "02, 27, 2023", 10, 'H');
    newTask.createTask("Task 3", "Cook", "01, 19, 2024", 9, 'M');
    newTask.removeTaskInList("Task 2");
    EXPECT_FALSE(newTask.duplicateTaskInListCheck("Task 2")); //Indicates that "Task 2" does not exist inside list anymore
}

TEST(removingTaskTest, removingTaskCheckingNumberOfTasks) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "01, 19, 2024", 11, 'N');
    newTask.createTask("Task 2", "Take out trash", "01, 19, 0001", 10, 'H');
    newTask.createTask("Task 3", "Cook", "01, 19, 0005", 9, 'M');
    newTask.removeTaskInList("Task 2");
    EXPECT_EQ(newTask.getListSize(), 2); //Indicates that "Task 2" does not exist inside list anymore
} 

TEST(removingTaskTest, removingTaskCheckingForZeroTasks) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "01, 19, 0005", 11, 'N');
    newTask.removeTaskInList("Task 1");
    EXPECT_EQ(newTask.getListSize(), 0); //Indicates that "Task 2" does not exist inside list anymore and the number of tasks should be zero
}

TEST(removingTaskTest, removingTaskThatDoesntExist) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "05, 05, 2025", 11, 'N');
    EXPECT_EQ(newTask.removeTaskInList("Task 4"), -1); // - 1 Indicates that "Task 4" does not exist inside list
}




//Editing tasks tests
TEST(editTaskTest, editingTitle) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "11, 22, 2022", 11, 'N');
    newTask.editTaskInList("Task 1", 1, "Task 5", "FILLER ", "FILLER", 0, 'N'); //Replacing old title "Task 1" with new title "Task 5"
    EXPECT_TRUE(newTask.duplicateTaskInListCheck("Task 5"));    //There should now exist a task called "Task 5" so should be true 
}

TEST(editTaskTest, editingdescription) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "01, 11, 2019", 11, 'N');
    newTask.editTaskInList("Task 1", 2, "FILLER", "FINISH LAB AND DO DISHES", "FILLER", 0, 'N'); //Replacing old description "Finsih Lab" to "FINSIH LAB AND DO DISHES"
    EXPECT_EQ(newTask.allTasksList.at(0).getDescription(), "FINISH LAB AND DO DISHES");
}

TEST(editTaskTest, editingDueDate) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "11, 23, 2024", 11, 'N');
    newTask.editTaskInList("Task 1", 3, "FILLER", "FILLER", "12, 12, 2055", 0, 'N'); //Replacing old duDate of 11/23/24 to 12/12/55
    EXPECT_EQ(newTask.allTasksList.at(0).getDueDate(), "12, 12, 2055");
}

TEST(editTaskTest, editingHour) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "01, 23, 2023", 11, 'N');
    newTask.editTaskInList("Task 1", 3, "FILLER", "FILLER", "01, 23, 2023", 10, 'N'); //Replacing old hour of 11 to 10, must change due Date as well
    EXPECT_EQ(newTask.allTasksList.at(0).getDueDateHour(), 10);
}

TEST(editTaskTest, editingPriority) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "11, 24, 2023", 11, 'N');
    newTask.editTaskInList("Task 1", 4, "FILLER", "FILLER", "FILLER", 0, 'H'); //Replacing old title priority 'N' to 'H'
    EXPECT_EQ(newTask.allTasksList.at(0).getPriority(), 'H');
}

TEST(editTaskTest, editingTaskThatDoesntExist) {
    taskList newTask;
    newTask.createTask("Task 1", "Finish LAB", "11, 23, 2023", 11, 'N');
    EXPECT_EQ(newTask.editTaskInList("Task 2", 4, "FILLER", "FILLER", "FILLER", 0, 'H'), -1); //Returns -1 when trying to edit a task that doesn't exist
}  