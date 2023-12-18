#ifndef GETINPUT_H
#define GETINPUT_H

#include "taskList.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class getInput { 
    public: 
        taskList myTasks; 
    public:  
        char getInputTask(); 
        void getInputCreateTask();
        void getInputRemoveTask();
        void getInputEditTask();
};

#endif