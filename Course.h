//
// Created by westl on 4/22/2020.
//

#ifndef UNTITLED_COURSE_H
#define UNTITLED_COURSE_H

#include <iostream>
#include <vector>

using namespace std;


class Course {
private:
    string name;
    vector<string> assignments;

public:
    string courseCommands[3] = {"add", "remove", "display"};
    string courseCommandsHelp[3] = {
            "Add an assignment to your selected course.",
            "Remove an assignment from your selected course.",
            "Display all assignments in a course."
    };
    Course(string courseName);
    string GetName();
    string GetAssignment(int index);
    void AddAssignment();
    void RemoveAssignment(string toDelete);
    void DisplayAssignments();
    void DisplayHelp();
    void DoCourseCommand(int command);
    void DisplayMenu();
    void SelectedLoop();

};


#endif //UNTITLED_COURSE_H