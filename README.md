# TimePulse
 > Authors: Andrew Permatigari (https://github.com/apermatigari)
            Denny Ly (https://github.com/PiggyTech1)
            Austin Le (https://github.com/ALE00111)
            Dev Mistry (https://github.com/devmistryy)
>
>
> You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.
>## Phase I
> ## Project Description 
> ## Our Project and Why
> As a group, we collectively decided to create a task scheduler app for our CS100 Final Project. The reason that we all chose to do this 
> specific application is because as being busy college students, we often have trouble with time management and forgetting about deadlines and due dates. So, in response,  we decided that a task scheduler program would be an answer to our time management, school, and work issues while still being a useful post graduation program to utilize. 
> ## The Programming Language
> For programming languages, we’ll be primarily using C++ and utilizing VS code for our preferred IDE. 
> ## The Input
> Overall, the input of the project is going to be a user creating certain tasks, assignments, etc. and they would include specific dates, time preferences, and descriptions. 
> ## The Output
> Then the output would include a possible visualization of the task’s based on time frame (i.e. the closest date would be at the top and the farthest date would be last) or based on priority. A couple of features that the project would provide include the titling of tasks, creating descriptions, choosing deadlines, creating priority, and possibly more. In all, we’re excited to begin and see through with the possible completion of this project.  
 > ## Phase II
## User Interface Specification
![user interface diagram(NEW)](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/8a2a4198-25e4-4b0f-ba41-1d41cc7efddf)

>  Our navigation diagram represents the basics of our app and the total functionality of it. As seen at the top, when launching the app, the user will be prompted with a standard welcome screen and they will be given the options to create, edit, view, or remove tasks. The view switches to the form of a table and this table will act as the central part of our scheduler app. From here, the user has a couple options they could do in our app and that includes scheduling tasks, editing tasks, removing tasks, or moving to a calender view of the user's tasks. The connections between these sections are done through buttons and eventually they will all lead back to the original table screen.

### Screen Layouts
![Home page screen layout](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/c302a94f-7f19-46b7-9d9c-73c22ba76f81)

> For this first layout, at the top of the screen, we have the title of our project and the whole screen represents the home page. It visualizes all the tasks in a table format and shows the main identifiers for a task (i.e. task, priority, and due date). In this layout, there are four main inputs to use which are the create a task button, edit, remove, and view. The user can select any of these four inputs by typing a letter linked to a certain command. This first layout will be the default home screen that you will see when you first enter the application and the buttons send you to the other layouts below. 
> 

![Create task page ](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/1baee435-e440-4c4b-9bea-b2c58fbec66c)

> This page has the option to set a title, description, due date, hour, and priority in the boxes to the left of each section. The priority box has three options to choose from (low, medium, or high). A description is capped at 100 characters per description. After creating the task you'll be automatically redirected to the table layout each time you create a task.

![edit task page](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/4de099dd-a9d9-4b22-ae61-c8a1900be01d)
> This page acts very similar to the "create a task" page, but the difference here is that you are editing an existing task. To arrive at this page, you needed to select a task from the table page and when arriving here, the layout is the same as the "create a task" but choices indicating that you can edit the title, due date, priority, and description for the selected task. After finishing your edits, you can type the number linked to the saving changes, which is 6, and will confirm your edit. Then you'll be redirected to your original table page. 

![remove task page](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/4daf4703-e624-4aa4-9d42-4542840b0996)
> This page basically only has one option and that's just to remove a task that is either completed or deemed unnecessary by the user by just inputting the task name. Once the task name is inputted, the task will be deleted from the task list and from the display.

![table view (standard)](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/0555d32a-794f-4de5-b36e-607657982d4e)
> This is the general view of the task list before priority or time sort. The list is only sorted by which tasks were inputted first. The information given is the task's title, description, priority, due date, and hour. 

![table view (priority)](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/2c40543a-8d03-4750-b7a7-d44d873bf196)
> This page displays the table view for all the tasks inputted and sorts it by priority. It will display all tasks from highest priority to lowest in the table.

![table view (time)](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/116854067/bd6ccbca-241f-4c32-9089-eeffb530b309)
> This page is very similar to the Table View for priority except it sorts the time instead. It will display all tasks in the format of the closest due date by time to the farthest due date by time in the table. 


## Class Diagram
![BRAND NEW UML DIAGRAM](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/4a63eaa6-9a6f-46a3-9b1f-c5eb05757414)


> Class Home is the main class, it displays table view by default and should have a button to display calendar view. Class Home should also be able to go to displayDescriptionAndTask which has the ability to display, edit, and remove a chosen task. Class displayDescriptionAndTask should also have a createTask function which leads to the Classes taskList and task. Class task creates an empty class object and has setters to set each of the needed private member variables. Class taskList creates 2 empty vectors that are going to be made up of task objects and sorted into Priority as the most significant ordering or the closest due date time as the most significant ordering. There should also be functions to input tasks, check for duplicate tasks, and remove specific tasks.

 
 > ## Phase III
>New SOLID principle class diagram
![BRAND NEW UML DIAGRAM](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/c8d3f126-6f14-4121-9b76-dd267531963c)



>For our first update to the class diagram, we moved merge to a separate class and the reason for this change is because merge originally was apart of taskList and the functions in that class mainly had creating, editing, and removing certain tasks, and so leaving merge there would violate the single responsibility principle (SRP). Our solution to this was to separate merge into its own class and subclasses to make sure it didn’t violate SRP. On top of that, we also used SRP in splitting our getInput away from our display class because we wanted to separate the functionality of displaying prompts and receiving inputs to not violate SRP. This made us write better code because it separated a lot of our functions up and allowed for less clutter in our already huge taskList class. 

>Since we moved the merge functions to their own class to satisfy SRP,  Liskov’s substitution principle (LSP) is broken due to the specifications of the different merge sorts are no longer correct. To comply with LSP, we created a virtual mergeSort function in the mergeSort class to allow for the different implementations of the mergeSorts to be called for the correct filter for priority, be it priority or time first.

>Another violation would be interface segregation principle (ISP). This occurs in the mergeSort class in which we separated the specific merges that only apply to priority or time, into different classes called prioritySort and timeSort. ISP states that a client shouldn’t have to implement a function that it doesn’t use, and so we changed our mergeSort function to not have both sorts, but to actually separate the two based on if the client would want to use one or the other. This helps us code better for our project because it allows us to separate some of our functions up into different classes so we can split our work force easily for different jobs.


 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
![SCREENSHOT 1](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/c9f6f880-295e-4630-a66d-7a561f0ed337)
> Begins the program and ask for input.
![SCREENSHOT 2](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/bdb3f06c-1fe6-4f05-87e0-5df4f438e359)
> Prompts user to create a task.
![SCREENSHOT 3](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/bb4f8956-19b1-422e-a3b8-d4804e1507a7)
> Prints the task with all information.
![SCREENSHOT 4](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/4a687000-140e-45b5-8ae2-4d87efc5599e)
> Prompts user to edit anything about the task.
![SCREENSHOT 5](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/1962e85d-ccde-421a-a6cf-40b40dbd9247)
> Prints all the tasks out with updated changes.
![SCREENSHOT 6](https://github.com/cs100/final-project-aperm003-dmist004-dly047-ale193/assets/117538724/923895ae-c481-400f-a1f1-71b24114a15a)
> Removes a task from the list.



 ## Installation/Usage
 > Instructions on installing and running your application
>
> Since our project is run in terminal, clone master into your IDE of choice (for VS code use git clone). To run the application, go to the terminal and use the command g++ main.cpp display.cpp getInput.cpp prioritySort.cpp task.cpp taskList.cpp taskListSort.cpp timeSort.cpp and hit enter to compile. Then, enter ./a.out followed by enter to run the program. This will result in displaying the menu screen of our application in which the user can enter their input.
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 >
 > We tested the files we worked on individually first using unit tests before doing a integration test by testing everything as a whole. Additionally, we tested specific outputs for table and week views to ensure that the display was correct and there are no formatting errors in our code. 
