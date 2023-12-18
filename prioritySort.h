#ifndef PRIORITYSORT_H
#define PRIORITYSORT_H

#include "task.h"
#include "taskList.h"
#include "mergeSort.h"

class prioritySort : public mergeSort {
    public:
    void differentMergeSorts(vector<Task>& vectorToBePrioritySorted);
    void sortPriority2(vector<Task>& vectorToBePrioritySorted);
    void sortDueDate2(vector<Task>& vectorToBePrioritySorted);
};

#endif