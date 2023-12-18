#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "task.h"
#include "mergeSort.h"
#include "timeSort.h"
#include <string>
#include <vector>

using namespace std;

class taskList {
private:
    int numOfTasks; 
    vector<Task> allTasksList; 
    vector<Task> timeFirst;
    vector<Task> priorityFirst;
public:
        taskList();
        int createTask(string title, string descrip, string dueDate, int hour, char priority); 
        void merge(vector<Task>& vectorToBeSorted, int timeOrPrioritySort);
        int editTaskInList(string title, int choice, string newTitle, string newD, string newDate, int newHour, char newP);
        int removeTaskInList(string title);
        bool duplicateTaskInListCheck(string title);
        int getListSize();
        vector<Task> getAllTasksList() const;
        vector<Task> getTimeVector() const;
        vector<Task> getPriorityVector() const;
};
#endif
