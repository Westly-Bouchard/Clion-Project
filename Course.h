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
    Course(string courseName);
    string GetName();
    string GetAssignment(int index);
    void AddAssignment(string nameOf);
    void RemoveAssignment(string toDelete);
    void DisplayAssignments();

};


#endif //UNTITLED_COURSE_H