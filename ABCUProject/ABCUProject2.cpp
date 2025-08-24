// Name        : ABCUProject2.cpp
// Author      : Damian Le


// Including standard Libraries
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Initializing global objects and variables
struct Course {
	string courseNumber;
	string courseName;
	vector<string> coursePrereqs;
};
vector<Course> courses;

// Load Data Structure method
void LoadDataStructure() {

	// Define file variable
	string fileName;

	// Get filename
	fileName = "CS 300 ABCU_Advising_Program_Input.csv";

	// Open file
	ifstream infile;
	infile.open(fileName);

	// Insert data into courses
	if (infile.is_open()) {
		string line;

		// Read file line by line using while loop
		while (getline(infile, line)) {
			vector <string> tokens;
			string token;
			stringstream ss(line);

			// Tokenizing ','
			while (getline(ss, token, ',')) {
				tokens.push_back(token);
			}

			// Create new course and add data from file
			Course newCourse = Course();
			newCourse.courseNumber = tokens[0];
			newCourse.courseName = tokens[1];
			
			// If prerequisites exist add to course
			if (tokens.size() > 2) {
				for (int i = 2; i < tokens.size(); i++) {
					newCourse.coursePrereqs.push_back(tokens[i]);
				}
			}

			// Add new course to courses
			courses.push_back(newCourse);
		}

		cout << "Data Structure loaded successfully!" << endl;
	}
	else {
		cout << "Error: File not found. Please check file path." << endl;
	}

	infile.close();
}

// Print Course List
void PrintCourseList() {

	// Validating data loaded from file
	if (courses.size() > 0) {

		// Sorting courses alphanumerically
		for (int i = 0; i < courses.size() - 1; i++) {
			for (int j = 0; j < courses.size() - i - 1; j++) {
				if (courses[j].courseNumber > courses[j + 1].courseNumber) {
					swap(courses[j + 1], courses[j]);
				}
			}
		}

		// Loop to print courses number and name
		
		cout << "Here is a sample schedule:" << endl;
		cout << endl;
		for (int i = 0; i < courses.size(); i++) {
			cout << courses[i].courseNumber << ", ";
			cout << courses[i].courseName << endl;
		}
		cout <<  endl;
	}
	else {
		cout << "Error: Please load course data first." << endl;
		
	}
}

// Print Course method
void PrintCourse() {

	// Validate data loaded from file
	if (courses.size() > 0) {
		string courseInput;
		bool courseFound = false;
		
		cout << "What course do you want to know about? ";
		cin >> courseInput;

		// Converting lowercase input to uppercase
		transform(courseInput.begin(), courseInput.end(), courseInput.begin(), ::toupper);
		
		// Loop through courses to find courseInput match
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i].courseNumber == courseInput) {
				// Changing courseFound to true if input matches the list 
				courseFound = true;

				// Printing the found course 
				cout  << endl;
				cout << "Course Information" << endl;
				cout  << endl;
				cout << courses[i].courseNumber << ", ";
				cout << courses[i].courseName << endl;
				cout << "Prerequisites: ";
				if (courses[i].coursePrereqs.size() > 0) {
					int prereqSize = courses[i].coursePrereqs.size();

					// Loop through course prereqs
					for (int j = 0; j < prereqSize - 1; j++) {
						cout << courses[i].coursePrereqs[j] << ", ";
					}
					// Eliminate comma from last entry
					cout << courses[i].coursePrereqs[prereqSize - 1];
					cout << endl;

					
				}
				else {
					cout << "None" << endl;
				}
								
			}
			
		}

		// Course input validation
		if (courseFound == false) {
			 cout << "Invalid Course. Please try again." << endl;
		}

	}
	else {
		cout << "Error: Please load data structure first." << endl;
		
	}
}

// main
int main() {

	// track exit status
	bool quit = false;

	// Program title
	cout << endl;
	cout << "Welcome to the course planner." << endl;

	do {
		string input;

		// Print Menu
		cout << endl;
		cout << "  1. Load Data Structure" << endl;
		cout << "  2. Print Course List" << endl;
		cout << "  3. Print Course" << endl;
		cout << "  9. Exit" << endl;
		cout << endl;
		cout << "What would you like to do? ";
		cin >> input;
		cout << endl;

		// User input validation
		while ((input != "1") && (input != "2") && (input != "3") && (input != "9")) {
			cout << input << " is not a valid option." << endl;

			cout << endl;
			cout << "  1. Load Data Structure" << endl;
			cout << "  2. Print Course List" << endl;
			cout << "  3. Print Course" << endl;
			cout << "  9. Exit" << endl;
			cout << endl;
			cout << "What would you like to do? ";
			cin >> input;
			cout << endl;
		}

		// Method calls on user selection 
		if (input == "1") {
			LoadDataStructure();
		}
		if (input == "2") {
			PrintCourseList();
		}
		if (input == "3") {
			PrintCourse();
		}
		if (input == "9") {
			cout << endl;
			cout << "Thank you for using the course planner!" << endl;
			exit(quit);
		}
	} while (!quit);

	return 0;
}