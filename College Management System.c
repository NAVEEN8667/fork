#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 50

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
} Student;

typedef struct {
    int id;
    char name[50];
    int credits;
} Course;

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];

int studentCount = 0;
int courseCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    Student s;
    s.id = studentCount + 1;

    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student age: ");
    scanf("%d", &s.age);
    printf("Enter student gender: ");
    scanf("%s", s.gender);

    students[studentCount++] = s;
    printf("Student added successfully with ID: %d\n", s.id);
}

void addCourse() {
    if (courseCount >= MAX_COURSES) {
        printf("Course limit reached.\n");
        return;
    }

    Course c;
    c.id = courseCount + 1;

    printf("Enter course name: ");
    scanf("%s", c.name);
    printf("Enter course credits: ");
    scanf("%d", &c.credits);

    courses[courseCount++] = c;
    printf("Course added successfully with ID: %d\n", c.id);
}

void displayStudents() {
    printf("\nList of Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].gender);
    }
}

void displayCourses() {
    printf("\nList of Courses:\n");
    for (int i = 0; i < courseCount; i++) {
        printf("ID: %d, Name: %s, Credits: %d\n",
               courses[i].id, courses[i].name, courses[i].credits);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Display Students\n");
        printf("4. Display Courses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addCourse();
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                displayCourses();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
