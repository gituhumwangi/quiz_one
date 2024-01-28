#include <iostream>
#include <string>

using namespace std;

// Define the course structure
struct Course {
    string course_code;
    string course_name;
};

// Define the grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the student structure
struct Student {
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grades;
};

// Function prototypes
void addStudent(Student students[], int &numStudents);
void editStudent(Student students[], int numStudents);
void addMarksAndCalculateGrades(Student students[], int numStudents);

int main() {
    Student students[40];
    int numStudents = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a student\n";
        cout << "2. Edit a student's details\n";
        cout << "3. Add marks and calculate grades\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                editStudent(students, numStudents);
                break;
            case 3:
                addMarksAndCalculateGrades(students, numStudents);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

void addStudent(Student students[], int &numStudents) {
    if (numStudents < 40) {
        cout << "Enter student details:\n";
        cout << "Registration Number: ";
        cin >> students[numStudents].reg_number;
        cout << "Name: ";
        cin.ignore(); // Ignore the newline character in the buffer
        getline(cin, students[numStudents].name);
        cout << "Age: ";
        cin >> students[numStudents].age;
        cout << "Course Code: ";
        cin >> students[numStudents].course.course_code;
        cout << "Course Name: ";
        cin.ignore();
        getline(cin, students[numStudents].course.course_name);

        numStudents++;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void editStudent(Student students[], int numStudents) {
    if (numStudents > 0) {
        string regNumber;
        cout << "Enter the registration number of the student to edit: ";
        cin >> regNumber;

        for (int i = 0; i < numStudents; i++) {
            if (students[i].reg_number == regNumber) {
                cout << "Enter new details for the student:\n";
                cout << "Registration Number: ";
                cin >> students[i].reg_number;
                cout << "Name: ";
                cin.ignore();
                getline(cin, students[i].name);
                cout << "Age: ";
                cin >> students[i].age;
                cout << "Course Code: ";
                cin >> students[i].course.course_code;
                cout << "Course Name: ";
                cin.ignore();
                getline(cin, students[i].course.course_name);

                cout << "Student details updated successfully.\n";
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found.\n";
    } else {
        cout << "No students to edit.\n";
    }
}

void addMarksAndCalculateGrades(Student students[], int numStudents) {
    if (numStudents > 0) {
        string regNumber;
        cout << "Enter the registration number of the student to add marks: ";
        cin >> regNumber;

        for (int i = 0; i < numStudents; i++) {
            if (students[i].reg_number == regNumber) {
                cout << "Enter marks for the student:\n";
                cout << "Mark: ";
                cin >> students[i].grades.mark;

                // Calculate the grade based on the mark
                if (students[i].grades.mark > 69)
                    students[i].grades.the_grade = 'A';
                else if (students[i].grades.mark > 59)
                    students[i].grades.the_grade = 'B';
                else if (students[i].grades.mark > 49)
                    students[i].grades.the_grade = 'C';
                else if (students[i].grades.mark > 39)
                    students[i].grades.the_grade = 'D';
                else
                    students[i].grades.the_grade = 'E';

                cout << "Marks added and grades calculated successfully.\n";
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found.\n";
    } else {
        cout << "No students to add marks.\n";
    }
}
