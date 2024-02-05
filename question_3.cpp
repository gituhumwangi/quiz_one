#include <iostream>
#include <string>

using namespace std;

// Define the course structure
struct Course {
    string code;
    string name;
};

struct Grade {
    int score;
    char letter_grade;
};

// Define the student structure
struct Student {
    string registration_number;
    string full_name;
    int student_age;
    Course enrolled_course;
    Grade student_grades;
};

// Function prototypes
void addNewStudent(Student all_students[], int &total_students);
void updateStudentDetails(Student all_students[], int total_students);
void addScoresAndCalculateGrades(Student all_students[], int total_students);

int main() {
    Student all_students[40];
    int total_students = 0;
    int user_choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new student\n";
        cout << "2. Update a student's details\n";
        cout << "3. Add scores and calculate grades\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> user_choice;

        switch (user_choice) {
            case 1:
                addNewStudent(all_students, total_students);
                break;
            case 2:
                updateStudentDetails(all_students, total_students);
                break;
            case 3:
                addScoresAndCalculateGrades(all_students, total_students);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (user_choice != 4);

    return 0;
}

void addNewStudent(Student all_students[], int &total_students) {
    if (total_students < 40) {
        cout << "Enter student details:\n";
        cout << "Registration Number: ";
        cin >> all_students[total_students].registration_number;
        cout << "Full Name: ";
        cin.ignore(); 
        getline(cin, all_students[total_students].full_name);
        cout << "Age: ";
        cin >> all_students[total_students].student_age;
        cout << "Course Code: ";
        cin >> all_students[total_students].enrolled_course.code;
        cout << "Course Name: ";
        cin.ignore();
        getline(cin, all_students[total_students].enrolled_course.name);

        total_students++;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void updateStudentDetails(Student all_students[], int total_students) {
    if (total_students > 0) {
        string regNumber;
        cout << "Enter the registration number of the student to update details: ";
        cin >> regNumber;

        for (int i = 0; i < total_students; i++) {
            if (all_students[i].registration_number == regNumber) {
                cout << "Enter new details for the student:\n";
                cout << "Registration Number: ";
                cin >> all_students[i].registration_number;
                cout << "Full Name: ";
                cin.ignore();
                getline(cin, all_students[i].full_name);
                cout << "Age: ";
                cin >> all_students[i].student_age;
                cout << "Course Code: ";
                cin >> all_students[i].enrolled_course.code;
                cout << "Course Name: ";
                cin.ignore();
                getline(cin, all_students[i].enrolled_course.name);

                cout << "Student details updated successfully.\n";
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found.\n";
    } else {
        cout << "No students to update.\n";
    }
}

void addScoresAndCalculateGrades(Student all_students[], int total_students) {
    if (total_students > 0) {
        string regNumber;
        cout << "Enter the registration number of the student to add scores: ";
        cin >> regNumber;

        for (int i = 0; i < total_students; i++) {
            if (all_students[i].registration_number == regNumber) {
                cout << "Enter scores for the student:\n";
                cout << "Score: ";
                cin >> all_students[i].student_grades.score;

                // Calculate the grade based on the score
                if (all_students[i].student_grades.score > 69)
                    all_students[i].student_grades.letter_grade = 'A';
                else if (all_students[i].student_grades.score > 59)
                    all_students[i].student_grades.letter_grade = 'B';
                else if (all_students[i].student_grades.score > 49)
                    all_students[i].student_grades.letter_grade = 'C';
                else if (all_students[i].student_grades.score > 39)
                    all_students[i].student_grades.letter_grade = 'D';
                else
                    all_students[i].student_grades.letter_grade = 'E';

                cout << "Scores added and grades calculated successfully.\n";
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found.\n";
    } else {
        cout << "No students to add scores.\n";
    }
}
