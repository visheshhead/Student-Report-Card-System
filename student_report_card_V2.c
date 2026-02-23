#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 5

typedef struct {
    int id;
    char name[50];
    int attendance;
    int marks[SUBJECTS];
    int extra;
    float percentage;
} Student;

Student students[MAX];
int count = 0;

// Calculate percentage
float calculatePercentage(Student *s) {
    int total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        total += s->marks[i];
    }
    total += s->extra;
    return total / 6.0; // 5 subjects + extra
}

// Add student
void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    Student s;
    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Attendance: ");
    scanf("%d", &s.attendance);

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);
    }

    printf("Enter Extra-Curricular Marks: ");
    scanf("%d", &s.extra);

    s.percentage = calculatePercentage(&s);
    students[count++] = s;

    printf("Student added successfully!\n");
}

// Display report card
void displayStudent(Student s) {
    printf("\nID: %d\nName: %s\nAttendance: %d\n", s.id, s.name, s.attendance);
    printf("Marks: ");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("%d ", s.marks[i]);
    }
    printf("\nExtra: %d", s.extra);
    printf("\nPercentage: %.2f%%\n", s.percentage);
}

// View all students
void viewAllStudents() {
    if (count == 0) {
        printf("No students available!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        displayStudent(students[i]);
    }
}

// Search student by ID
void searchStudent() {
    int id, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            displayStudent(students[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Performance analytics
void performanceAnalytics() {
    if (count == 0) {
        printf("No data available!\n");
        return;
    }

    float sum = 0;
    int topperIndex = 0, lowestIndex = 0;

    for (int i = 0; i < count; i++) {
        sum += students[i].percentage;

        if (students[i].percentage > students[topperIndex].percentage)
            topperIndex = i;

        if (students[i].percentage < students[lowestIndex].percentage)
            lowestIndex = i;
    }

    printf("\n--- Performance Analytics ---\n");
    printf("Class Average: %.2f%%\n", sum / count);

    printf("\nTopper:\n");
    displayStudent(students[topperIndex]);

    printf("\nLowest Performer:\n");
    displayStudent(students[lowestIndex]);
}

int main() {
    int choice;

    do {
        printf("\n===== Student Report Card System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Performance Analytics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: performanceAnalytics(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}