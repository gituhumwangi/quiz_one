#include <stdio.h>
#include <string.h>

// Define the course structure
struct Course {
    char code[10];
    char name[50];
};

// Define the grade structure
struct Grade {
    int score;
    char letter_grade;
};

// Define the student structure
struct Student {
    char registration_number[20];
    char full_name[50];
    int student_age;
    struct Course enrolled_course;
    struct Grade student_grades;
};

// Function prototypes
void addNewStudent(struct Student students[], int *total_students);
void updateStudentDetails(struct Student students[], int total_students);
void addScoresAndCalculateGrades(struct Student students[], int total_students);

int main() {
    struct Student students[40];
    int total_students = 0;
    int user_choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add a new student\n");
        printf("2. Update a student's details\n");
        printf("3. Add scores and calculate grades\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                addNewStudent(students, &total_students);
                break;
            case 2:
                updateStudentDetails(students, total_students);
                break;
            case 3:
                addScoresAndCalculateGrades(students, total_students);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (user_choice != 4);

    return 0;
}

void addNewStudent(struct Student students[], int *total_students) {
    if (*total_students < 40) {
        printf("Enter student details:\n");
        printf("Registration Number: ");
        scanf("%s", students[*total_students].registration_number);
        printf("Full Name: ");
        scanf("%s", students[*total_students].full_name);
        printf("Age: ");
        scanf("%d", &students[*total_students].student_age);
        printf("Course Code: ");
        scanf("%s", students[*total_students].enrolled_course.code);
        printf("Course Name: ");
        scanf("%s", students[*total_students].enrolled_course.name);

        (*total_students)++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void updateStudentDetails(struct Student students[], int total_students) {
    if (total_students > 0) {
        char regNumber[20];
        printf("Enter the registration number of the student to update details: ");
        scanf("%s", regNumber);

        for (int i = 0; i < total_students; i++) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                printf("Enter new details for the student:\n");
                printf("Registration Number: ");
                scanf("%s", students[i].registration_number);
                printf("Full Name: ");
                scanf("%s", students[i].full_name);
                printf("Age: ");
                scanf("%d", &students[i].student_age);
                printf("Course Code: ");
                scanf("%s", students[i].enrolled_course.code);
                printf("Course Name: ");
                scanf("%s", students[i].enrolled_course.name);

                printf("Student details updated successfully.\n");
                return;
            }
        }

        printf("Student with registration number %s not found.\n", regNumber);
    } else {
        printf("No students to update.\n");
    }
}

void addScoresAndCalculateGrades(struct Student students[], int total_students) {
    if (total_students > 0) {
        char regNumber[20];
        printf("Enter the registration number of the student to add scores: ");
        scanf("%s", regNumber);

        for (int i = 0; i < total_students; i++) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                printf("Enter scores for the student:\n");
                printf("Score: ");
                scanf("%d", &students[i].student_grades.score);

                // Calculate the grade based on the score
                if (students[i].student_grades.score > 69)
                    students[i].student_grades.letter_grade = 'A';
                else if (students[i].student_grades.score > 59)
                    students[i].student_grades.letter_grade = 'B';
                else if (students[i].student_grades.score > 49)
                    students[i].student_grades.letter_grade = 'C';
                else if (students[i].student_grades.score > 39)
                    students[i].student_grades.letter_grade = 'D';
                else
                    students[i].student_grades.letter_grade = 'E';

                printf("Scores added and grades calculated successfully.\n");
                return;
            }
        }

        printf("Student with registration number %s not found.\n", regNumber);
    } else {
        printf("No students to add scores.\n");
    }
}
