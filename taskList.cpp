#include "task.h"
#include "taskList.h"
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

taskList::taskList() {
    numOfTasks = 0;
}
 
int taskList::createTask(string title, string descrip, string dueDate, int hour, char priority) {
    Task newTask;
    bool duplicate = false;
    bool errorCheckTitle = false;
    bool errorCheckDueDate = false;
    bool errorCheckHour = false;
    bool errorCheckPriority = false;
    bool errorCheckDescrip = false;

    //Set title
    errorCheckTitle = newTask.setTitle(title);
    if (errorCheckTitle == false) {
        return 1;
    }
    
    //Set due date/hour
    errorCheckDueDate = newTask.setDueDate(dueDate);
    if (errorCheckDueDate == false) {
        return 2;
    } 

    errorCheckHour = newTask.setTime(hour);
    if(errorCheckHour == false) {
        return 3;
    }
    
    //Set priority
    errorCheckPriority = newTask.setPriority(priority);
    if (errorCheckPriority == false) {       
        return 4;
    }
    
    //Set description 
    errorCheckDescrip = newTask.setDescription(descrip);
    if (errorCheckDescrip == false) {
        return 5;
    }

    //Store newTask inside a vector of tasks
    allTasksList.push_back(newTask);

    //ADD newTask to the priorty and time vectors
    timeFirst.push_back(newTask);
    priorityFirst.push_back(newTask);
    //Possibly call mergeSort here to sort these two vectors???
    //Call functions timeSort and prioritySort that both inherit from the abstract class of mergeSort that inherits from taskList
    
    //MAKE SURE TO UNCOMMENT LATER, functionality for these two functions need to be double checked 
    // timeSort(timeFirst);
    // prioritySort(priorityFirst);

    ++numOfTasks;
    return 0;       //Always return 0 when created task succesfully, any other number indicated error 
}

int taskList::editTaskInList(string taskTitle, int choice, string newTitle, string newD, string newDate, int newHour, char newP) {
    //First finds the task, specifically edits the task with any feature specified.
    int i;
    int t;
    int p;
    int allTaskLocation = 0;
    int tLocation = 0;
    int pLocation = 0;
    bool errorCheckTitle = false;
    bool errorCheckDescrip = false;
    bool errorCheckDate = false;
    bool errorCheckHour = false;
    bool errorCheckPriority = false;

    for(i = 0; i < allTasksList.size(); ++i) {
        if(allTasksList.at(i).getTaskName() == taskTitle) {
            allTaskLocation = i;
        }
    }

    for(t = 0; t < timeFirst.size(); ++t) {
        if(timeFirst.at(t).getTaskName() == taskTitle) {
            tLocation = t;
        }
    }

    for(p = 0; p < priorityFirst.size(); ++p) {
        if(priorityFirst.at(p).getTaskName() == taskTitle) {
            pLocation = p;
        }
    }

    if(choice == 1) {
        errorCheckTitle = allTasksList.at(allTaskLocation).setTitle(newTitle);
        if(errorCheckTitle == false) {
            return 1;       //Returns 1 for invalid title
        }
        timeFirst.at(tLocation).setTitle(newTitle);
        priorityFirst.at(pLocation).setTitle(newTitle);
    }
    else if(choice == 2) {
        errorCheckDate = allTasksList.at(allTaskLocation).setDueDate(newDate);
        if(errorCheckDate == false) {
            return 2;           //Returns 2 for invlaid date 
        }
        timeFirst.at(tLocation).setDueDate(newDate);
        priorityFirst.at(pLocation).setDueDate(newDate);
    }
    else if(choice == 3) {
        errorCheckHour = allTasksList.at(allTaskLocation).setTime(newHour);
        if(errorCheckHour == false) {
            return 3;            //Returns 3 for invalid time 
        }
        timeFirst.at(tLocation).setTime(newHour);
        priorityFirst.at(pLocation).setTime(newHour);
    }
    else if(choice == 4) {
        errorCheckPriority = allTasksList.at(allTaskLocation).setPriority(newP);
        if(errorCheckPriority == false) {
            return 4;           //Returns 4 for invalid priority
        }
        timeFirst.at(tLocation).setPriority(newP);
        priorityFirst.at(pLocation).setPriority(newP);
    }
    else if(choice == 5) {
        errorCheckDescrip = allTasksList.at(allTaskLocation).setDescription(newD);
        if(errorCheckDescrip == false) {
            return 5;        //Returns 5 for invalid description
        }
        timeFirst.at(tLocation).setDescription(newD);
        priorityFirst.at(pLocation).setDescription(newD);
    }

    return 0;
}

int taskList::removeTaskInList(string title) {
    //First finds the task specified to be deleted, and proceeds to remove said task from allTasksList, priorityFirst, and timeFirst vectors
    int taskLocation;

    if(duplicateTaskInListCheck(title) == false) {
        return -1; //Return's -1 if the task doesn't exist
    } 

    for(int i= 0; i < allTasksList.size(); ++i) {
        if(allTasksList.at(i).getTaskName() == title) {
            taskLocation = i;
        }
    } 
    allTasksList.erase(allTasksList.begin() + taskLocation);

    for(int t = 0; t < timeFirst.size(); ++t) {
        if(timeFirst.at(t).getTaskName() == title) {
            taskLocation = t;
        }
    }
    timeFirst.erase(timeFirst.begin() + taskLocation);

    for(int p = 0; p < priorityFirst.size(); ++p) {
        if(priorityFirst.at(p).getTaskName() == title) {
            taskLocation = p;
        }
    }
    priorityFirst.erase(priorityFirst.begin() + taskLocation);
    
    --numOfTasks;

    return 0; //Return's 0 if task is succesfully removed
}

bool taskList::duplicateTaskInListCheck(string title) {
    //searches through whole allTasks and compares each one with the title given 
    int i;
    for(i= 0; i < allTasksList.size(); ++i) {
        if(allTasksList.at(i).getTaskName() == title) {
            return true;
        }
    }
    return false; 
}

void taskList::merge(vector<Task>& vectorToBeSorted, int timeOrPrioritySort) { //0 = timeSort 1 = prioritySort
    mergeSort* sortByTimePtr = nullptr;
    if(timeOrPrioritySort == 0) {
        timeSort time;
        sortByTimePtr = &time;
    }

    if(timeOrPrioritySort == 1) {
        prioritySort priority;
        sortByTimePtr = &priority;
    }

    sortByTimePtr->differentMergeSorts(vectorToBeSorted);
    return;
}

int taskList::getListSize() {
    return numOfTasks;
}

vector<Task> taskList::getAllTasksList() const {
    return allTasksList;
}

vector<Task> taskList::getTimeVector() const {
    return timeFirst;
}

vector<Task> taskList::getPriorityVector() const{
    return priorityFirst;
}
