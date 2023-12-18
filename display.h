#ifndef DiSPLAY_H
#define DISPLAY_H

#include "getInput.h"
#include "taskList.h"
#include "task.h"
#include <iostream>
using namespace std;

class display {
    private:    
        void chooseRoute(char route, getInput user);

        //Display functions for the Calendar like view
        void goToCalendarView(getInput user);
        void goToCalendarViewPriority(getInput user);
        void goToCalendarViewTime(getInput user);

        //Display functions for the table view 
        void goToTableView(getInput user);
        void goToTableViewPriority(getInput user);
        void goToTableViewTime(getInput user); 
    public:
        int Display();
}; 

#endif