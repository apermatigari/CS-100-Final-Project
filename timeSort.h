#ifndef TIMESORT_H
#define TIMESORT_H

#include "task.h"
#include "taskList.h"
#include "mergeSort.h"

class timeSort : public mergeSort {
    public:
    void differentMergeSorts(vector<Task>& vectorToBeTimeSorted);
    void sortPriority(vector<Task>& vectorToBeTimeSorted);
    void sortDueDate(vector<Task>& vectorToBeTimeSorted);
};

#endif