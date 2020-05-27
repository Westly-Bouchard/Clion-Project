//
// Created by westl on 4/22/2020.
//

#include "Course.h"
#include <iostream>
#include <vector>
#include <locale>

using namespace std;

string toLowerCase(string input) {
    locale loc;
    for (int i = 0; i < input.size(); i++) {
        input[i] = tolower(input[i], loc);
    }
    return input;
}

Course::Course(string courseName) {
    name = courseName;
}


string Course::GetName() {
    return name;
}

string Course::GetAssignment(int index) {
    return assignments[index];
}

void Course::AddAssignment() {
    string nameOf;
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

void Course::DisplayHelp() {
    for (int i = 0; i < sizeof(courseCommands) / sizeof(string); i++) {
        cout << courseCommands[i] << ": " << courseCommandsHelp[i];
    }
}

void Course::DoCourseCommand(int command) {
//    switch (command) {
//        case 0:
//            AddAssignment();
//    }
}

void Course::DisplayMenu() {
    cout << "Commands for the selected course (type 'deselect' deselect the course): " << endl;
    for(int i = 0; i < courseCommands->length(); i++) {
        cout << "        " << courseCommands[i] << endl;
    }
}



void Course::SelectedLoop() {
    string currentCommand;
    while (true) {
        DisplayMenu();
        cout << "Enter a command:" << endl;
        cin >> currentCommand;

        if (toLowerCase(currentCommand) == "deselect") {
            break;
        } else if (toLowerCase(currentCommand) == "help") {
            DisplayHelp();
        }
    }
}