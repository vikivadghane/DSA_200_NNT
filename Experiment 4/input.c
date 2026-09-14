// input for tutorial 4
#include <stdio.h>

struct student
{
    int rollNo;
    char name[50];
    float marks;
};

void create(struct student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d", i + 1);

        printf("\nEnter Roll No: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct student s[], int n)
{
    int i;

    printf("\n--- Student Details ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d", i + 1);
        printf("\nRoll No: %d", s[i].rollNo);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void linearSearch(struct student s[], int n)
{
    int roll, i, found = 0;

    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].rollNo == roll)
        {
            printf("\nStudent Found!");
            printf("\nRoll No: %d", s[i].rollNo);
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

void sort(struct student s[], int n)
{
    int i, j;
    struct student temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].marks > s[j + 1].marks)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents are sorted according to their marks\n");
}

int main()
{
    struct student s[5];
    int choice;

    do
    {
        printf("\n\n====== STUDENT MENU ======");
        printf("\n1. Create Student Details");
        printf("\n2. Display Student Details");
        printf("\n3. Linear Search");
        printf("\n4. Sort by Marks");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create(s, 5);
                break;

            case 2:
                display(s, 5);
                break;

            case 3:
                linearSearch(s, 5);
                break;

            case 4:
                sort(s, 5);
                break;

            case 5:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while(choice != 5);

    return 0;
}
