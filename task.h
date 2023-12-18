#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
    private:  
        string description;
        string taskTitle;
        string dueDateString;
        int dueDateHour;
        char priorityChar;
        vector<int> numsOfDueDateVector;
    public: 
        Task();
        bool setDescription(string d);
        string getDescription() const; 
        string getTaskName() const;
        bool setTitle(string name); 
        bool setDueDate(string date);
        void addDueDateIntoVector(int num);
        string getDueDate() const;
        int getDueDateHour() const;
        vector<int> getNumsOfDueDateVector() const;
        bool setPriority(char priority);
        char getPriority() const;
        bool setTime(const int hour);
        bool errorCheckHour(const int hour); 
        int getTime() const;
        bool checkInputSizeValid(const string userInputString);
        bool checkInputsAreNumbers(const string userInputString);
        bool withinSize(string name);
        bool withinLines(string d);
        bool checkPriorityValid(const char priority);
};
 
#endif