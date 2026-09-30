#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void pop()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    temp = head;
    head = head->next;

    printf("\nPopped element is %d", temp->data);

    free(temp);
}

void printlist()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    printf("\nStack elements are:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, val;
    char ans;

    do
    {
        printf("\n\tMain Menu");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to push: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            printlist();
            break;

        case 4:
            printf("\nExiting program...");
            return 0;

        default:
            printf("\nInvalid choice!");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
