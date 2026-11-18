#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN   50
#define CITY_LEN   30
#define DREAM_LEN  60

/* Structure that groups the details of one student */
struct Student {
    int   rollNumber;
    char  name[NAME_LEN];
    float cutoffMark;
    char  city[CITY_LEN];
    char  dream[DREAM_LEN];
};

/* Remove the trailing newline left by fgets */
void trimNewline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

/* Module 1: read the number of students (must be positive) */
int getStudentCount(void) {
    int n;
    while (1) {
        printf("Enter the total number of students: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');      /* clear bad input */
            continue;
        }
        if (n > 0)
            return n;
        printf("Count must be positive. Try again.\n");
    }
}

/* Module 2: collect the details of every student */
void readStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details of Student %d ---\n", i + 1);

        printf("Roll Number : ");
        scanf("%d", &s[i].rollNumber);
        getchar();                           /* consume newline */

        printf("Name        : ");
        fgets(s[i].name, NAME_LEN, stdin);
        trimNewline(s[i].name);

        printf("Cut-off Mark: ");
        scanf("%f", &s[i].cutoffMark);
        getchar();

        printf("City        : ");
        fgets(s[i].city, CITY_LEN, stdin);
        trimNewline(s[i].city);

        printf("Dream       : ");
        fgets(s[i].dream, DREAM_LEN, stdin);
        trimNewline(s[i].dream);
    }
}

/* Module 3: display the details of every student */
void displayStudents(struct Student s[], int n) {
    printf("\n========== STUDENT DETAILS ==========\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("  Roll Number : %d\n", s[i].rollNumber);
        printf("  Name        : %s\n", s[i].name);
        printf("  Cut-off Mark: %.2f\n", s[i].cutoffMark);
        printf("  City        : %s\n", s[i].city);
        printf("  Dream       : %s\n", s[i].dream);
    }
    printf("\n=====================================\n");
}

int main(void) {
    int n = getStudentCount();

    struct Student *students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    readStudents(students, n);
    displayStudents(students, n);

    free(students);
    return 0;
}
