#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 40
#define MAX_STRING_LENGTH 50

struct Course {
    char course_code[MAX_STRING_LENGTH];
    char course_name[MAX_STRING_LENGTH];
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    char registration_number[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    int age;
    struct Course course;
    struct Grade grades;
    int grades_calculated;
};

// Function prototypes
void addStudent(struct Student students[], int *studentCount);
void editStudentDetails(struct Student students[], int studentCount);
void addMarksAndCalculateGrades(struct Student students[], int studentCount);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add a student\n");
        printf("2. Edit student details\n");
        printf("3. Add marks and calculate grades\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                editStudentDetails(students, studentCount);
                break;
            case 3:
                addMarksAndCalculateGrades(students, studentCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *studentCount) {
    if (*studentCount < MAX_STUDENTS) {
        struct Student newStudent;

        printf("Enter registration number: ");
        scanf("%s", newStudent.registration_number);

        printf("Enter name: ");
        scanf("%s", newStudent.name);

        printf("Enter age: ");
        scanf("%d", &newStudent.age);

        printf("Enter course code: ");
        scanf("%s", newStudent.course.course_code);

        printf("Enter course name: ");
        scanf("%s", newStudent.course.course_name);

        students[(*studentCount)++] = newStudent;
        printf("Student added successfully.\n");
    } else {
        printf("Cannot add more students. Maximum limit reached.\n");
    }
}

void editStudentDetails(struct Student students[], int studentCount) {
    if (studentCount > 0) {
        char regNumber[MAX_STRING_LENGTH];
        printf("Enter registration number of the student to edit: ");
        scanf("%s", regNumber);

        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                printf("Enter new age for the student: ");
                scanf("%d", &students[i].age);

                printf("Student details updated successfully.\n");
                return;
            }
        }

        printf("Student with registration number %s not found.\n", regNumber);
    } else {
        printf("No students to edit. Add students first.\n");
    }
}

void addMarksAndCalculateGrades(struct Student students[], int studentCount) {
    if (studentCount > 0) {
        char regNumber[MAX_STRING_LENGTH];
        printf("Enter registration number of the student: ");
        scanf("%s", regNumber);

        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                if (!students[i].grades_calculated) {
                    printf("Enter marks for the student: ");
                    scanf("%d", &students[i].grades.mark);

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

                    students[i].grades_calculated = 1;

                    printf("Grades calculated and updated successfully.\n");
                } else {
                    printf("Grades already calculated for this student.\n");
                }

                return;
            }
        }

        printf("Student with registration number %s not found.\n", regNumber);
    } else {
        printf("No students to add marks. Add students first.\n");
    }
}
