#include "task.h"
#include "taskList.h"
#include "timeSort.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void timeSort::differentMergeSorts(vector<Task>& vectorToBeTimeSorted) {
    sortPriority(vectorToBeTimeSorted);    //sorts by priority first
    sortDueDate(vectorToBeTimeSorted);    //sorts by dueDate second
}

void timeSort::sortPriority(vector<Task>& vectorToBeTimeSorted) {
    if (vectorToBeTimeSorted.size() <= 1) {//base case stop when each block is of size = 1
        return; //nothing to be sorted
    }

    int vectSize = vectorToBeTimeSorted.size();
    int middle = vectSize / 2;  //create left middle and right
    vector<Task> left;
    vector<Task> right;

    left.reserve(middle);//make sure there is enough space in the left and right vectors without having to dynamically allocate
    right.reserve(vectSize - middle);

    copy(vectorToBeTimeSorted.begin(), vectorToBeTimeSorted.begin() + middle, back_inserter(left)); //copy into left vector
    copy(vectorToBeTimeSorted.begin() + middle, vectorToBeTimeSorted.end(), back_inserter(right)); //copy into right vector

    sortPriority(left);  //split left + right until only one block
    sortPriority(right); 

    int indexL = 0; //l in the front is hard to read so swapped position
    int indexR = 0;
    int indexOG = 0;

    while (indexL < left.size() && indexR < right.size()) {//sort until one vector is empty
        Task leftObj = left.at(indexL);
        Task rightObj = right.at(indexR);
        //means left = H | left = right | left = M right = L
        if ((leftObj.getPriority() == 'H') || (leftObj.getPriority() == rightObj.getPriority()) || (leftObj.getPriority() == 'M' && rightObj.getPriority() == 'L')) {
            vectorToBeTimeSorted.at(indexOG) = left.at(indexL);
            ++indexL;
        }
        else {  //means right has greater priorty
            vectorToBeTimeSorted.at(indexOG) = right.at(indexR);
            ++indexR;
        }
        ++indexOG;
    }

    while (indexL < left.size()) {  //if left vector not empty finish pushing into OG vector
        vectorToBeTimeSorted.at(indexOG) = left.at(indexL);
        ++indexL;
        ++indexOG;
    }
    while (indexR < right.size()) { //if right vector not empty finish pushing into OG vector
        vectorToBeTimeSorted.at(indexOG) = right.at(indexR);
        ++indexR;
        ++indexOG;
    }
}

void timeSort::sortDueDate(vector<Task>& vectorToBeTimeSorted) {
    if (vectorToBeTimeSorted.size() <= 1) {//base case stop when each block is of size = 1
        return; //nothing to be sorted
    }

    int vectSize = vectorToBeTimeSorted.size();
    int middle = vectSize / 2;  //create left middle and right
    vector<Task> left;
    vector<Task> right;

    left.reserve(middle);//make sure there is enough space in the left and right vectors without having to dynamically allocate
    right.reserve(vectSize - middle);

    copy(vectorToBeTimeSorted.begin(), vectorToBeTimeSorted.begin() + middle, back_inserter(left)); //copy into left vector
    copy(vectorToBeTimeSorted.begin() + middle, vectorToBeTimeSorted.end(), back_inserter(right)); //copy into right vector

    sortDueDate(left);  //split left + right until only one block
    sortDueDate(right);

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
                vectorToBeTimeSorted.at(indexOG) = left.at(indexL);
                ++indexL;
                ++indexOG;
            }
            else if (leftObjDateVect.at(i) > rightObjDateVect.at(i)) {//rightObj's dueDate is closer than leftObj's dueDate
                vectorToBeTimeSorted.at(indexOG) = right.at(indexR);
                ++indexR;
                ++indexOG;
            }
        }
        else if (i <= 0) {
            if (leftObj.getDueDateHour() <= rightObj.getDueDateHour()) {//left and rightObj have the same year/month/day so compare time
                vectorToBeTimeSorted.at(indexOG) = left.at(indexL);
                ++indexL;
            }
            else if (leftObj.getDueDateHour() > rightObj.getDueDateHour()){//rightObj dueDateHour is closer than leftObj dueDateHour
                vectorToBeTimeSorted.at(indexOG) = right.at(indexR);
                ++indexR;
                }
            else if (indexL < left.size() && !(indexR < left.size())) {
                vectorToBeTimeSorted.at(indexOG) = right.at(indexR);
                ++indexR;
            }
            else if (!(indexL < left.size()) && indexR < left.size()) {
                vectorToBeTimeSorted.at(indexOG) = left.at(indexL);
                ++indexL;
            }
            ++indexOG;
            }
            --i;
        }

    while (indexL < left.size()) {  //if left vector not empty finish pushing into OG vector
        vectorToBeTimeSorted.at(indexOG) = left.at(indexL);
        ++indexL;
        ++indexOG;
    }
    while (indexR < right.size()) { //if right vector not empty finish pushing into OG vector
        vectorToBeTimeSorted.at(indexOG) = right.at(indexR);
        ++indexR;
        ++indexOG;
    }
}