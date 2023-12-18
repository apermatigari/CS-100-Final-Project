#include "task.h"
#include "taskList.h"
#include "prioritySort.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void prioritySort::differentMergeSorts(vector<Task>& vectorToBePrioritySorted) {
    sortDueDate2(vectorToBePrioritySorted);    //sorts by dueDate first
    sortPriority2(vectorToBePrioritySorted);    //sorts by priority second
}

void prioritySort::sortPriority2(vector<Task>& vectorToBePrioritySorted) {
    int vectSize = vectorToBePrioritySorted.size();
    int middle = vectSize / 2;  //create left middle and right
    vector<Task> left;
    vector<Task> right;

    left.reserve(middle);//make sure there is enough space in the left and right vectors without having to dynamically allocate
    right.reserve(vectSize - middle);

    copy(vectorToBePrioritySorted.begin(), vectorToBePrioritySorted.begin() + middle, back_inserter(left)); //copy into left vector
    copy(vectorToBePrioritySorted.begin() + middle, vectorToBePrioritySorted.end(), back_inserter(right)); //copy into right vector

    sortPriority2(left);  //split left + right until only one block
    sortPriority2(right); 

    int indexL = 0; //l in the front is hard to read so swapped position
    int indexR = 0;
    int indexOG = 0;

    while (indexL < left.size() && indexR < right.size()) {//sort until one vector is empty
        Task leftObj = left.at(indexL);
        Task rightObj = right.at(indexR);
        //means left = H | left = right | left = M right = L
        if ((leftObj.getPriority() == 'H') || (leftObj.getPriority() == rightObj.getPriority()) || (leftObj.getPriority() == 'M' && rightObj.getPriority() == 'L')) {
            vectorToBePrioritySorted.at(indexOG) = left.at(indexL);
            ++indexL;
        }
        else {  //means right has greater priorty
            vectorToBePrioritySorted.at(indexOG) = right.at(indexR);
            ++indexR;
        }
        ++indexOG;
    }

    while (indexL < left.size()) {  //if left vector not empty finish pushing into OG vector
        vectorToBePrioritySorted.at(indexOG) = left.at(indexL);
        ++indexL;
        ++indexOG;
    }
    while (indexR < right.size()) { //if right vector not empty finish pushing into OG vector
        vectorToBePrioritySorted.at(indexOG) = right.at(indexR);
        ++indexR;
        ++indexOG;
    }
}

void prioritySort::sortDueDate2(vector<Task>& vectorToBePrioritySorted) {
    if (vectorToBePrioritySorted.size() <= 1) {//base case stop when each block is of size = 1
        return; //nothing to be sorted
    }

    int vectSize = vectorToBePrioritySorted.size();
    int middle = vectSize / 2;  //create left middle and right
    vector<Task> left;
    vector<Task> right;

    left.reserve(middle);//make sure there is enough space in the left and right vectors without having to dynamically allocate
    right.reserve(vectSize - middle);

    copy(vectorToBePrioritySorted.begin(), vectorToBePrioritySorted.begin() + middle, back_inserter(left)); //copy into left vector
    copy(vectorToBePrioritySorted.begin() + middle, vectorToBePrioritySorted.end(), back_inserter(right)); //copy into right vector

    sortDueDate2(left);  //split left + right until only one block
    sortDueDate2(right);

    int indexL = 0; //l in the front is hard to read so swapped position
    int indexR = 0;
    int indexOG = 0;
    int i = 2;

    while (indexL < left.size() && indexR < right.size()) {//sort until one vector is empty
        Task leftObj = left.at(indexL);
        Task rightObj = right.at(indexR);

        leftObj.compactDueDateVector();
        rightObj.compactDueDateVector();

        vector<int> leftObjDateVect = leftObj.getNumsOfDueDateVector();
        vector<int> rightObjDateVect = rightObj.getNumsOfDueDateVector();

        if (i >= 0) {
            if (leftObjDateVect.at(i) < rightObjDateVect.at(i)) {//leftObj's dueDate is closer than rightObj's dueDate
                vectorToBePrioritySorted.at(indexOG) = left.at(indexL);
                ++indexL;
                ++indexOG;
            }
            else if (leftObjDateVect.at(i) > rightObjDateVect.at(i)) {//rightObj's dueDate is closer than leftObj's dueDate
                vectorToBePrioritySorted.at(indexOG) = right.at(indexR);
                ++indexR;
                ++indexOG;
            }
        }
        else if (i <= 0) {
            if (leftObj.getDueDateHour() < rightObj.getDueDateHour()) {//left and rightObj have the same year/month/day so compare time
                vectorToBePrioritySorted.at(indexOG) = left.at(indexL);
                ++indexL;
            }
            else if (leftObj.getDueDateHour() > rightObj.getDueDateHour()){//rightObj dueDateHour is closer than leftObj dueDateHour
                vectorToBePrioritySorted.at(indexOG) = right.at(indexR);
                ++indexR;
                }
            else if (indexL < left.size() && !(indexR < left.size())) {
                vectorToBePrioritySorted.at(indexOG) = right.at(indexR);
                ++indexR;
            }
            else if (!(indexL < left.size()) && indexR < left.size()) {
                vectorToBePrioritySorted.at(indexOG) = left.at(indexL);
                ++indexL;
            }
            ++indexOG;
            }
            --i;
        }

    while (indexL < left.size()) {  //if left vector not empty finish pushing into OG vector
        vectorToBePrioritySorted.at(indexOG) = left.at(indexL);
        ++indexL;
        ++indexOG;
    }
    while (indexR < right.size()) { //if right vector not empty finish pushing into OG vector
        vectorToBePrioritySorted.at(indexOG) = right.at(indexR);
        ++indexR;
        ++indexOG;
    }
}