#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Define the Course structure
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Hash table class for storing courses
class CourseHashTable {
private:
    unordered_map<string, Course> courses;

public:
    // Method to load courses from a file
    void loadCoursesFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: File cannot be opened." << endl;
            return;
        }

        string line;
        unordered_map<string, bool> courseNumbers;

        // First pass to collect all course numbers
        while (getline(file, line)) {
            stringstream ss(line);
            string courseNumber;
            getline(ss, courseNumber, ',');
            courseNumbers[courseNumber] = true;
        }

        file.clear();
        file.seekg(0, ios::beg);

        // Second pass to create course objects
        while (getline(file, line)) {
            stringstream ss(line);
            string courseNumber, courseTitle, prerequisite;
            getline(ss, courseNumber, ',');
            getline(ss, courseTitle, ',');

            Course course;
            course.courseNumber = courseNumber;
            course.courseTitle = courseTitle;

            while (getline(ss, prerequisite, ',')) {
                if (courseNumbers.find(prerequisite) == courseNumbers.end()) {
                    cout << "Error: Prerequisite not found for course " << courseNumber << "." << endl;
                }
                course.prerequisites.push_back(prerequisite);
            }
            courses[courseNumber] = course;
        }

        file.close();
    }

    // Method to print all courses in alphanumeric order
    void printAllCourses() const {
        vector<string> courseNumbers;
        for (const auto& pair : courses) {
            courseNumbers.push_back(pair.first);
        }
        sort(courseNumbers.begin(), courseNumbers.end());

        for (const string& courseNumber : courseNumbers) {
            cout << courseNumber << ": " << courses.at(courseNumber).courseTitle << endl;
        }
    }

    // Method to print information of a specific course
    void printCourseInfo(const string& courseNumber) const {
        auto it = courses.find(courseNumber);
        if (it != courses.end()) {
            const Course& course = it->second;
            cout << "Course Number: " << course.courseNumber << endl;
            cout << "Course Title: " << course.courseTitle << endl;
            cout << "Prerequisites: ";
            if (course.prerequisites.empty()) {
                cout << "None" << endl;
            }
            else {
                for (const string& prerequisite : course.prerequisites) {
                    cout << prerequisite << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "Course not found." << endl;
        }
    }
};

// Function to display the menu and handle user input
void displayMenu(CourseHashTable& courseTable) {
    int choice;
    string filename, courseNumber;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the filename: ";
            cin >> filename;
            courseTable.loadCoursesFromFile(filename);
            break;
        case 2:
            courseTable.printAllCourses();
            break;
        case 3:
            cout << "Enter the course number: ";
            cin >> courseNumber;
            courseTable.printCourseInfo(courseNumber);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
}

// Main function
int main() {
    CourseHashTable courseTable;
    displayMenu(courseTable);
    return 0;
}
