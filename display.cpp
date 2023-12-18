#include <iostream>
#include "getInput.h"
#include "taskList.h"
#include "task.h"
#include "display.h"

using namespace std;
#include <string>
#include <string>
#include <vector>

// whole calendar and table view are in terminal
int display::Display() {
    // other variables also need to be put in here, I just put the Title getter for the time being

    getInput user;
    string name;
    char currentInput;

    //Beginnning prompt 

    cout << "WELCOME TO TIMEPULSE (TP)" << endl;
    cout << "PURPOSE: Create tasks and place them into a calender or table view for the user to see!" << endl;
    cout << "STEP 1: Create a task" << endl;
    cout << "STEP 2: Assign a title, description, due date, and priority to the task" << endl;
    cout << "STEP 3: View all your tasks in a calender view or table format" << endl;
    cout << "From here, you can either create more tasks, edit current tasks, remove tasks that are finished/uneeded, or switch between view modes" << endl; 
    cout << "to visualize your tasks!" << endl;
    cout << "ENJOY TP!" << endl << endl;

    cout << "c: create a task" << endl;
    cout << "e: edit a task" << endl;
    cout << "r: to remove a task" << endl;
    cout << "v: view a task" << endl;
    cout << "q: to end program" << endl << endl;
    
    currentInput = user.getInputTask();
    
    //In getInput class, have a function that returns the stored input for currentView(1 or 2), then return and based on that value go to which view
    
    while(currentInput != 'q') {
        if(currentInput == 'a' || currentInput == 'p' || currentInput == 'w' || currentInput == 'A' || currentInput == 'P' || currentInput == 'W') {
            chooseRoute(currentInput, user);
        }

        cout << endl;
        cout << "c: create a task" << endl;
        cout << "e: edit a task" << endl;
        cout << "r: to remove a task" << endl;
        cout << "v: view a task" << endl;
        cout << "q: to end program" << endl << endl;
        
        currentInput = user.getInputTask();
    }

    return 0;
}

void display::chooseRoute(char route, getInput user) {
    if(route == 'a') {
        cout << "MOVING TO TABLE VIEW" << endl;
        cout << endl;
        goToTableView(user);
    }
    else if(route == 'A') {
        cout << "MOVING TO WEEKLY CALENDAR VIEW" << endl;
        cout << endl;
        goToCalendarView(user);
    }
    else if(route == 'p') {
        cout << "MOVING TO TABLE VIEW (PRIORITY)" << endl;
        cout << endl;
        goToTableViewPriority(user);
    }
    else if(route == 'P') {
        cout << "MOVING TO WEEKLY CALENDAR VIEW (PRIORITY)" << endl;
        cout << endl;
        goToCalendarViewPriority(user);
    }
    else if(route == 'w') {
        cout << "MOVING TO TABLE VIEW (TIME)" << endl;
        cout << endl;
        goToTableViewTime(user);
    }
    else if(route == 'W') {
        cout << "MOVING TO WEEKLY CALENDAR VIEW (TIME))" << endl;
        cout << endl;
        goToCalendarViewTime(user);
    }
}

void display::goToCalendarView(getInput user) {
    //Display
    return;
}


void display::goToCalendarViewPriority(getInput user) {
    //Display
    return;
}


void display::goToCalendarViewTime(getInput user) {
    //Display 
    return; 
}


void display::goToTableView(getInput user) {
    int i;
    string title;
    string description;
    string dueDate;
    int hour; 
    char priority;

    if(user.myTasks.getAllTasksList().size() == 0) {
        cout << "NO TASKS IN LIST" << endl;
        return;
    }
    
    //Printing out all tasks(No order)
    cout << "ALL TASKS TO BE DONE (STANDARD): " << endl << endl;
    for(i = 0; i < user.myTasks.getListSize(); ++i) {
        
        title = user.myTasks.getAllTasksList().at(i).getTaskName();
        description = user.myTasks.getAllTasksList().at(i).getDescription();
        dueDate = user.myTasks.getAllTasksList().at(i).getDueDate();
        hour = user.myTasks.getAllTasksList().at(i).getDueDateHour();
        priority = user.myTasks.getAllTasksList().at(i).getPriority();
        
        cout << "Task: " << i+1 << endl << endl;
        cout << "Title: " << title << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Time: " << hour << endl;
        cout << "Priority: " << priority << endl;
        cout << "Description: " << description << endl; 
        cout << endl << endl;
    }
    return;
}
 
void display::goToTableViewPriority(getInput user) {
    int i;
    string title;
    string description;
    string dueDate;
    int hour; 
    char priority;

    if(user.myTasks.getAllTasksList().size() == 0) {
        cout << "NO TASKS IN LIST" << endl;
        return;
    }

    //Printing out all tasks(Order by priority)
    cout << "ALL TASKS TO BE DONE (SORTED BY PRIORITY): " << endl << endl;
    for(i = 0; i < user.myTasks.getListSize(); ++i) {
        
        title = user.myTasks.getPriorityVector().at(i).getTaskName();
        description = user.myTasks.getPriorityVector().at(i).getDescription();
        dueDate = user.myTasks.getPriorityVector().at(i).getDueDate();
        hour = user.myTasks.getPriorityVector().at(i).getDueDateHour();
        priority = user.myTasks.getPriorityVector().at(i).getPriority();
        
        cout << "Task: " << i+1 << endl << endl;
        cout << "Title: " << title << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Time: " << hour << endl;
        cout << "Priority: " << priority << endl;
        cout << "Description: " << description << endl; 
        cout << endl << endl;
    }
    return;
}

void display::goToTableViewTime(getInput user) {
    int i;
    string title;
    string description;
    string dueDate;
    int hour; 
    char priority;

    if(user.myTasks.getAllTasksList().size() == 0) {
        cout << "NO TASKS IN LIST" << endl;
        return;
    }

    //Printing out all tasks(Order by time)
    cout << "ALL TASKS TO BE DONE (SORTED BY TIME): " << endl << endl;
    for(i = 0; i < user.myTasks.getListSize(); ++i) {
        
        title = user.myTasks.getTimeVector().at(i).getTaskName();
        description = user.myTasks.getTimeVector().at(i).getDescription();
        dueDate = user.myTasks.getTimeVector().at(i).getDueDate();
        hour = user.myTasks.getTimeVector().at(i).getDueDateHour();
        priority = user.myTasks.getTimeVector().at(i).getPriority();
        
        cout << "Task: " << i+1 << endl << endl;
        cout << "Title: " << title << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Time: " << hour << endl;
        cout << "Priority: " << priority << endl;
        cout << "Description: " << description << endl; 
        cout << endl << endl;
    }
    return;
}