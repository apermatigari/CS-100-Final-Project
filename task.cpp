#include "task.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Task::Task() {
    description = " "; 
    taskTitle = " "; 
    dueDateString = " ";
    dueDateHour = 0;
    priorityChar = 'Z';
} 
  
bool Task::setDescription(string d) {           //Always call this function change to set a description 
    //Check if string size is set at 100 characters
    bool r = withinLines(d);
    if(r == false) {
        return false;
    }
    else {
        description = d; 
        return true;
    }
}

bool Task::setTitle(string name) {           
    bool within = withinSize(name);
    if(within == false) {
        return false;
    }
    else {
        taskTitle = name; 
        return true; 
    }
}

bool Task::withinLines(string d) {  //Every time we type in a description, run this function first, and then set it. 
    bool sizeLessThan100;
    if(d.size() <= 100) {
        sizeLessThan100 = true; 
    }
    else {
        sizeLessThan100 = false;
    }
    
    if(sizeLessThan100 == false) {
        cout << "ERROR: Description must be less than 100 characters." << endl;
        return false;  //Continues to prompt the user until they type a description less than 100 characters. 
    }
    else {
        return sizeLessThan100;
    }
}

bool Task::withinSize(string name) {  
    bool sizeForty;
    if(name.size() <= 40) {
        sizeForty = true; 
    }
    else {
        sizeForty = false;
    }
    
    if(sizeForty == false) {
        cout << "Keep title 40 characters or less" << endl;
        return false;  
    }
    else {
        return true;
    }
}


string Task::getDescription() const {
    return description; 
}

string Task::getTaskName() const {
    return taskTitle;
}
    
   
bool Task::setDueDate(const string date) {
    if (!(checkInputSizeValid(date))) {
        return false;
    }

    if (!(checkInputsAreNumbers(date))) {
        return false;   
    }

    char splitToBeStored;
    int intFromStringToBeStored;

    char comma = ',';
    char space = ' ';
  
    for (int i = 0; i < date.size(); ++i) {
        if ((date.at(i) != comma) && (date.at(i) != space)) {
            splitToBeStored = date.at(i);
            intFromStringToBeStored = splitToBeStored;
            intFromStringToBeStored -= 48;
            addDueDateIntoVector(intFromStringToBeStored);
        }
    }
    dueDateString = date;
    return true;
}

void Task::addDueDateIntoVector(int num) {
    numsOfDueDateVector.push_back(num);
}

string Task::getDueDate() const {
    return dueDateString;
}

int Task::getDueDateHour() const {
    return dueDateHour;
}

vector<int> Task::getNumsOfDueDateVector() const {
    return numsOfDueDateVector;
}

bool Task::checkInputSizeValid(const string userInputString) {
    return (userInputString.size() == 12);
}

bool Task::checkInputsAreNumbers(string userInputString) {
    //should turn characters into ascii value then check between range of 48 to 57
    int i;              // for (char c : userInputString) {
    char c;             //     if 
    int charToAscii;    // }


    for (i = 0; i < 2; ++i)
    { // check for MM
        c = userInputString.at(i);
        charToAscii = (int)c;
        if (!(charToAscii <= 57) || !(charToAscii >= 48)) {
            return false;
        }
    }

    for (i = 4; i < 6; ++i)
    { // check for DD
        c = userInputString.at(i);
        charToAscii = (int)c;
        if (!(charToAscii <= 57) || !(charToAscii >= 48)) {
            return false;
        }
    }

    for (i = 8; i < 12; ++i)
    { // check for YYYY
        c = userInputString.at(i);
        charToAscii = (int)c;
        if (!(charToAscii <= 57) || !(charToAscii >= 48)) {
            return false;
        }
    }

    return true;
}
 
bool Task::setPriority(const char priority) {
    bool checkPriority = checkPriorityValid(priority);
    if(checkPriority == false) {
        return false;
    }
    priorityChar = priority;
    return true; 
}

bool Task::checkPriorityValid(const char priority) {
    if(priority != 'H' && priority != 'M' && priority != 'L' && priority != 'N') {
        return false;
    }
    return true;
}

char Task::getPriority() const {
    return priorityChar;
}

bool Task::setTime(const int hour) {
    if(errorCheckHour(hour) == false) {
        return false;
    }
    dueDateHour = hour;
    return true;
}

bool Task::errorCheckHour(const int hour) {
    if(hour < 0 || hour > 24) {
        return false;
    }
    return true;
}

int Task::getTime() const {
    return dueDateHour;
} 
