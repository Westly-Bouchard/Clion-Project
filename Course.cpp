//
// Created by westl on 4/22/2020.
//

#include "Course.h"
#include <iostream>
#include <vector>

using namespace std;

Course::Course(string courseName) {
    name = courseName;
}


string Course::GetName() {
    return name;
}

string Course::GetAssignment(int index) {
    return assignments[index];
}

void Course::AddAssignment(string nameOf) {
    assignments.push_back(nameOf);
}

void Course::DisplayAssignments() {
    for (int i = 0; i < assignments.size(); i++) {
        cout << i + 1 << assignments[i];
    }
}

void Course::RemoveAssignment(string toDelete) {
//    for
}
