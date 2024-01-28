#include <iostream>
#include <cstring>
using namespace std;
const int MAX_STUDENTS = 40;

class Course {
public:
    char course_code[5];
    char course_name[20];
};

class Grade {
public:
    int mark;
    char grade;

    void calculateGrade() {
        if (mark > 69)
            grade = 'A';
        else if (mark > 59)
            grade = 'B';
        else if (mark > 49)
            grade = 'C';
        else if (mark > 39)
            grade = 'D';
        else
            grade = 'E';
    }
};

class Student {
public:
    char registration_number[20];
    char name[50];
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;

    // Member function to edit student details
    void editDetails() {
        cout << "Edit student's  new age: ";
        cin >> age;
        cout << "Edit student's name: ";
        cin>> name;
        cout << "Student details updated successfully.\n";
    }
};

// Function prototypes
void addStudent(Student students[], int& studentCount);
void editStudentDetails(Student students[], int studentCount);
void addMarksAndCalculateGrades(Student students[], int studentCount);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    cout<<"WELCOME TO THE STUDENT'S MANAGEMENT SYTEM"<<endl;
    cout<< "........................................"<<endl;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a student\n";
        cout << "2. Edit student details\n";
        cout << "3. Add marks and calculate grades\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                editStudentDetails(students, studentCount);
                break;
            case 3:
                addMarksAndCalculateGrades(students, studentCount);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}

// Member function to add a new student
void addStudent(Student students[], int& studentCount) {
    if (studentCount < MAX_STUDENTS) {
        Student newStudent;

        cout << "Enter registration number: ";
        cin >> newStudent.registration_number;

        cout << "Enter name: ";
        cin >> newStudent.name;

        cout << "Enter age: ";
        cin >> newStudent.age;

        cout << "Enter course code: ";
        cin >> newStudent.course.course_code;

        cout << "Enter course name: ";
        cin >> newStudent.course.course_name;

        students[studentCount++] = newStudent;
        cout << "Student added successfully.\n";
    } else {
        cout << "Cannot add more students. Maximum limit reached.\n";
    }
}

// Member function to edit student details
void editStudentDetails(Student students[], int studentCount) {
    if (studentCount > 0) {
        char regNumber[20];
        cout << "Enter registration number of the student to edit: ";
        cin >> regNumber;

        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                students[i].editDetails();
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found.\n";
    } else {
        cout << "No students to edit. Add students first.\n";
    }
}

// Member function to add marks and calculate grades
void addMarksAndCalculateGrades(Student students[], int studentCount) {
    if (studentCount > 0) {
        char regNumber[20];
        cout << "Enter registration number of the student: ";
        cin >> regNumber;

        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].registration_number, regNumber) == 0) {
                if (!students[i].grades_calculated) {
                    cout << "Enter marks for the student: ";
                    cin >> students[i].grades.mark;

                    students[i].grades.calculateGrade();
                    students[i].grades_calculated = true;

                    cout << "Grades calculated and updated successfully.\n";
                } else {
                    cout << "Grades already calculated for this student.\n";
                }

                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found.\n";
    } else {
        cout << "No students to add marks. Add students first.\n";
    }
}
