#include "taskList.h"
#include "getInput.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char getInput::getInputTask() {
    char currentView;
    char userInput;
    cin >> userInput;
    cout << endl;

    if(userInput == 'c') {
        getInputCreateTask();
    }
    else if(userInput == 'e') {
        getInputEditTask();
    }
    else if(userInput == 'r') {
        getInputRemoveTask();
    }
    else if(userInput == 'v') {
        cout << "Choose a view:" << endl;
        cout << "T: Table view" << endl;
        cout << "L: Calender view" << endl;
        cin >> currentView;
        cout << endl;

        if(currentView == 'T' || currentView == 't') {
            cout << "Display table as..." << endl;
            cout << "a: Standard Display" << endl;
            cout << "p: Priority" << endl;
            cout << "w: Time" << endl;
            cin >> currentView;
            cout << endl;
        }
        else if(currentView == 'L' || currentView == 'l') {
            cout << "Display calendar as..." << endl;
            cout << "A: Standard Display" << endl;
            cout << "P: Priority" << endl;
            cout << "W: TIme" << endl;
            cin >> currentView;
            cout << endl;
        }

        return currentView;
    }
    return userInput;
}


void getInput::getInputEditTask() {
    string title;
    string newTitle;
    int choice;
    string newD;
    string newDate;
    int newHour;
    char newP;
    bool done = false;
    int result;

    if(myTasks.getListSize() <= 0) {
        cout << endl;
        cout << "NO TASKS TO EDIT" << endl;
        return;
    }
    
    cin.ignore();
    cin.clear();
    cout << "What task do you want to edit? (ENTER FULL TITLE): " ; 
    getline(cin, title);
    cout <<endl;

    while(myTasks.duplicateTaskInListCheck(title) != true) {
        cout << "TASK DOES NOT EXIST REINPUT TASK NAME" << endl;
        cout << "What task do you want to edit? (ENTER FULL TITLE): " ; 
        getline(cin, title);
        cout <<endl;
    }
    
    while (done == false) {
        cout << "Enter 1 for new title, 2 for new date, 3 for new hour, 4 to change priority, 5 for new description, and 6 to save changes: ";
        cin >> choice;
        cout <<endl;
        
        if (choice == 1) {
            cout << "Enter a new title for the task (REQUIRED, must be less than 40 characters): ";
            cin.ignore();
            cin.clear();
            getline(cin, newTitle);
            cout << endl;
            result = myTasks.editTaskInList(title, choice, newTitle, newD, newDate, newHour, newP);
        }
        else if (choice == 2) {
            cout << "Enter a new Due date (FORMAT -> MM, DD, YYYY  EX: 04, 22, 2023): ";
            cin.ignore();
            cin.clear();
            getline(cin, newDate);
            cout << endl;
            result = myTasks.editTaskInList(title, choice, newTitle, newD, newDate, newHour, newP);
        }
        else if (choice == 3) {
            cout << "Enter a new time for the task to be due (0 to 24 HOURS): ";
            cin >> newHour;
            while(cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "INVALID INPUT: REENTER TIME" << endl;
                cout << "Enter a time for the task to be due (0 to 24 HOURS): ";
                cin >> newHour;
            }     
            cout << endl;
            result = myTasks.editTaskInList(title, choice, newTitle, newD, newDate, newHour, newP);
        }
        else if (choice == 4) {
            cout << "Enter a new priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
            cin >> newP;
            while(cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "INVALID INPUT: REENTER PRIORITY" << endl;
                cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
                cin >> newP;
            }    
            cout << endl;
            result = myTasks.editTaskInList(title, choice, newTitle, newD, newDate, newHour, newP);
        }
        else if (choice == 5) {
            cout << "Enter a description for the task (REQUIRED: Must be less than 100 characters): ";
            cin.clear();
            cin.ignore();
            getline(cin, newD);
            cout << endl;
            result = myTasks.editTaskInList(title, choice, newTitle, newD, newDate, newHour, newP);
        }
        else if (choice == 6) {
            done = true;
            result = 0;
        }
        else {
            cout << "Not a valid input, try again" << endl;
            done = false;
            cout << endl;
            result = 0;
        }

        while (result != 0) {
            if (result == 1) {
                cout << "ERROR: TITLE MUST BE LESS THAN 40 CHARACTERS" << endl;
                cout << "Enter a title for the task (REQUIRED, must be less than 40 characters): ";
                cin.clear();
                getline(cin, newTitle);
                cout << endl;
            }
            else if (result == 2) {
                cout << "ERROR: MUST BE A VALID DATE" << endl;
                cout << "Enter new Due date (FORMAT -> MM, DD, YYYY  EX: 04, 22, 2023): ";
                cin.clear();
                getline(cin, newDate);           
                cout << endl;
            }
            else if (result == 3) {
                cout << "ERROR: MUST ENTER VALID TIME" << endl;
                cout << "Enter a time for the task to be due (0 to 24 HOURS): ";
                cin >> newHour;
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "INVALID INPUT: REENTER TIME" << endl;
                    cout << "Enter a time for the task to be due (0 to 24 HOURS): ";
                    cin >> newHour;
                }            
                cout << endl;
            }
            else if (result == 4) {
                cout << "ERROR: MUST BE VALID PRIORIRTY" << endl;
                cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
                cin >> newP;
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "INVALID INPUT: REENTER PRIORITY" << endl;
                    cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
                    cin >> newP;
                }         
                cout <<endl;
            }
            else if (result == 5) {
                cout << "ERROR: MUST BE VALID DESCRIPTION" << endl;
                cout << "Enter a description for the task (REQUIRED: Must be less than 100 characters): ";
                cin.clear();
                getline(cin, newD);
                cout <<endl;
            }
            result = myTasks.editTaskInList(title, choice, newTitle, newD, newDate, newHour, newP);
        }
    }
    cout << "TASK EDITED" << endl;
}

void getInput::getInputRemoveTask() {
    string title;
    int result = 0;
    cout << "What task do you want to remove? (ENTER FULL TITLE): ";
    cin.ignore();
    cin.clear();
    getline(cin, title);
    cout <<endl;

    result = myTasks.removeTaskInList(title); //correct way remove function should remove tasks
    if(result == -1) {
        cout << "TASK DOES NOT EXIST" << endl << endl;
        return;
    }
    cout << "TASK REMOVED" << endl << endl;
}

void getInput::getInputCreateTask() {
    string title;
    string description;
    string dueDate;
    int hour;
    char priority; 
    int result;


    //Getting title    
    cout << "Enter a title for the task (REQUIRED, must be less than 40 characters): ";
    cin.ignore();
    cin.clear();
    getline(cin, title);
    cout << endl;

    //Checking duplicate
    while(myTasks.duplicateTaskInListCheck(title) == true) {
        cout << "TASK ALREADY EXISTS" << endl;
        cout << "Enter a title for the task (REQUIRED, must be less than 40 characters): ";
        cin.clear();
        cin.ignore();
        getline(cin, title);
        cout << endl;
    }


    //Getting due date
    cout << "Enter new Due date (FORMAT -> MM, DD, YYYY  EX: 04, 22, 2023):";
    getline(cin, dueDate);           
    cout << endl;
    
    //Getting hour
    cout << "Enter a time for the task to be due(0 to 24 HOURS): ";
    cin >> hour;            //Also have error checking for time
    while(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "INVALID INPUT: REENTER TIME" << endl;
        cout << "Enter a time for the task to be due (0 to 24 HOURS): ";
        cin >> hour;
    }   
    cout <<endl;

    //Getting priority
    cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
    cin >> priority;
    while(cin.fail()) {
        cout << "INVALID INPUT: REENTER PRIORITY" << endl;
        cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
        cin >> priority;
    }    
    cout <<endl;

    //Getting description 
    cout << "Enter a description for the task (REQUIRED: Must be less than 100 characters): ";
    cin.clear();
    cin.ignore();
    getline(cin, description);
    cout <<endl;

    result = myTasks.createTask(title, description, dueDate, hour, priority); 

    //returns a value, and based on the value, it indicates the violation for the rules to create a task and promprts user to input it again
    while(result != 0) {
        if(result == 1) {
            cout << "ERROR: TITLE MUST BE LESS THAN 40 CHARACTERS" << endl;
            cout << "Enter a title for the task (REQUIRED, must be less than 40 characters): ";
            cin.clear();
            getline(cin, title);
            cout << endl;
        }
        else if(result == 2) {
            cout << "ERROR: MUST BE A VALID DATE" << endl;
            cout << "Enter new Due date (FORMAT -> MM, DD, YYYY  EX: 04, 22, 2023): ";
            cin.clear();
            getline(cin, dueDate);           
            cout << endl;
        }
        else if(result == 3) {
            cout << "ERROR: MUST ENTER VALID TIME" << endl;
            cout << "Enter a time for the task to be due (0 to 24 HOURS): ";
            cin >> hour;
            while(cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "INVALID INPUT: REENTER TIME" << endl;
                cout << "Enter a time for the task to be due (0 to 24 HOURS): ";
                cin >> hour;
            }            
            cout <<endl;
        }
        else if(result == 4) {
            cout << "ERROR: MUST BE VALID PRIORIRTY" << endl;
            cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
            cin >> priority;
            while(cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "INVALID INPUT: REENTER PRIORITY" << endl;
                cout << "Enter a priority (H = HIGH, M = MEDIUM, L = LOW, N = NO PRIORITY): ";
                cin >> priority;
            }     
            cout <<endl;
        }
        else if(result == 5) {
            cout << "ERROR: MUST BE VALID DESCRIPTION" << endl;
            cout << "Enter a description for the task (REQUIRED: Must be less than 100 characters): ";
            cin.clear();
            cin.ignore();
            getline(cin, description);
            cout <<endl;
        }
        else if(result == -1) {
            cout << "TASK ALREADY EXISTS IN LIST" << endl;
            cout << "Enter a title for the task (REQUIRED, must be less than 40 characters): ";
            cin.clear();
            cin.ignore();
            getline(cin, title);
            cout << endl;
        }
        result = myTasks.createTask(title, description, dueDate, hour, priority);
    }
    cout << "TASK CREATED" << endl;
}