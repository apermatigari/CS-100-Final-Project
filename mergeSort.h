#ifndef MERGESORT_H
#define MERGESORT_H

#include "task.h"
#include "taskList.h"

class mergeSort {
    public:
        virtual void differentMergeSorts(vector<Task>& vectorToBeSorted) = 0;
};

#endif