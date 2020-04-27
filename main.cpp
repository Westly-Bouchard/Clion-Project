#include <iostream>
#include <vector>
#include <locale>
#include "Course.h"

using namespace std;

//List of all possible commnands:
string commands[5] = {"add", "delete", "display", "select", "help"};
string helpMessages[5] = {
        "Allows you to add a course to your list of courses.",
        "Allows you to delete a course from your list of courses.",
        "Display all courses in your course list.",
        "Select a specific course to add or remove assignmnets",
        "Displays the help menu."
};
string courseCommands[3] = {"add", "remove", "display"};
string courseCommandsHelp[3] = {
        "Add an assignment to your selected course.",
        "Remove an assignment from your selected course.",
        "Display all assignments in a course."};
vector<Course> courses;

//General function for making strings all lower case.
string toLowerCase(string input) {
    locale loc;
    for (int i = 0; i < input.size(); i++) {
        input[i] = tolower(input[i], loc);
    }
    return input;
}

void DisplayMenu() {
    cout << "Menu (enter 'exit' to stop the program)"<< endl;
    cout << "Commands: " << endl;
    for (int i = 0; i < sizeof(commands) / sizeof(string); i++) {
        cout << "       " << commands[i] << endl;
    }
    cout << endl << endl;
}

void DisplayHelp() {
    for (int i = 0; i < sizeof(commands) / sizeof(string); i++) {
        cout << commands[i] << ": " << helpMessages[i] << endl;
    }
    cout << endl;
}

void AddCourse() {
    string courseName;
    cout << "What is the name of the course you want to add? ";
    cin >> courseName;
    Course newCourse(courseName);
    courses.push_back(newCourse);
    cout << "Course added" << endl;
}

void PrintCourses() {
    if (!courses.empty()) {
        for (int i = 0; i < courses.size(); i++) {
            cout << courses[i].GetName() << endl;
        }
    } else {
        cout << "You dont have any courses yet silly! Add courses using the 'add' command." << endl;
    }
}


void RemoveCourse() {
    string course;
    int indexOfCourse;
    cout << "What is the course that you want to remove? " << endl;
    cin >> course;
    for (int i = 0; i < courses.size(); i++) {
        if (toLowerCase(courses[i].GetName()) == toLowerCase(course)) {
            courses.erase(courses.begin() + i);
            return;
        }
    }
    cout << "That it not a valid command." << endl;
}


bool checkSelectedCourse(string selectedCourse) {
    for (int i = 0; i < courses.size(); i++) {
        if (toLowerCase(courses[i].GetName()) == toLowerCase(selectedCourse)) {
            return true;
        }
    }
    return false;
}


void SelectCourse() {
    string selectedCourse;
    cout << "Which course would you like to select?";
    while (!checkSelectedCourse(selectedCourse)) {
        cin >> selectedCourse;
    }
    cout << "The selected course is: " + selectedCourse << endl;


}

void DoCommand(int command) {
    switch(command) {
        case 0:
            AddCourse();
            break;
        case 1:
            RemoveCourse();
            break;
        case 2:
            PrintCourses();
            break;
        case 3:
            if (!courses.empty()) {
                SelectCourse();
            } else {
                cout << "You don't have any courses yet.";
            }
        default:
            return;
    }
}


void ParseInput(const string input) {
    for (int i = 0; i < sizeof(commands) / sizeof(string); i++) {
        if (toLowerCase(input) == commands[i]) {
            DoCommand(i);
            return;
        }
    }
    cout << "That is not a valid command" << endl;
}


int main() {
    bool exit = false;
    string currentCommand;

    while (!exit) {
        DisplayMenu();
        cout << "Enter a command: " << endl;
        cin >> currentCommand;

        if (toLowerCase(currentCommand) == "exit") {
            exit = true;
            break;
        } else if (toLowerCase(currentCommand) == "help") {
            DisplayHelp();
        }

        ParseInput(currentCommand);
    }

    return 0;
}