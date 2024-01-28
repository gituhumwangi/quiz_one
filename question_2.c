#include <stdio.h>
#include <string.h>

// Define the course structure
struct Course {
    char course_code[10];
    char course_name[50];
};

// Define the grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the student structure
struct Student {
    char reg_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grades;
};

// Function prototypes
void addStudent(struct Student students[], int *numStudents);
void editStudent(struct Student students[], int numStudents);
void addMarksAndCalculateGrades(struct Student students[], int numStudents);

int main() {
    struct Student students[40];
    int numStudents = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add a student\n");
        printf("2. Edit a student's details\n");
        printf("3. Add marks and calculate grades\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                editStudent(students, numStudents);
                break;
            case 3:
                addMarksAndCalculateGrades(students, numStudents);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents < 40) {
        printf("Enter student details:\n");
        printf("Registration Number: ");
        scanf("%s", students[*numStudents].reg_number);
        printf("Name: ");
        scanf("%s", students[*numStudents].name);
        printf("Age: ");
        scanf("%d", &students[*numStudents].age);
        printf("Course Code: ");
        scanf("%s", students[*numStudents].course.course_code);
        printf("Course Name: ");
        scanf("%s", students[*numStudents].course.course_name);

        (*numStudents)++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void editStudent(struct Student students[], int numStudents) {
    if (numStudents > 0) {
        char regNumber[20];
        printf("Enter the registration number of the student to edit: ");
        scanf("%s", regNumber);

        for (int i = 0; i < numStudents; i++) {
            if (strcmp(students[i].reg_number, regNumber) == 0) {
                printf("Enter new details for the student:\n");
                printf("Registration Number: ");
                scanf("%s", students[i].reg_number);
                printf("Name: ");
                scanf("%s", students[i].name);
                printf("Age: ");
                scanf("%d", &students[i].age);
                printf("Course Code: ");
                scanf("%s", students[i].course.course_code);
                printf("Course Name: ");
                scanf("%s", students[i].course.course_name);

                printf("Student details updated successfully.\n");
                return;
            }
        }

        printf("Student with registration number %s not found.\n", regNumber);
    } else {
        printf("No students to edit.\n");
    }
}

void addMarksAndCalculateGrades(struct Student students[], int numStudents) {
    if (numStudents > 0) {
        char regNumber[20];
        printf("Enter the registration number of the student to add marks: ");
        scanf("%s", regNumber);

        for (int i = 0; i < numStudents; i++) {
            if (strcmp(students[i].reg_number, regNumber) == 0) {
                printf("Enter marks for the student:\n");
                printf("Mark: ");
                scanf("%d", &students[i].grades.mark);

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

                printf("Marks added and grades calculated successfully.\n");
                return;
            }
        }

        printf("Student with registration number %s not found.\n", regNumber);
    } else {
        printf("No students to add marks.\n");
    }
}
