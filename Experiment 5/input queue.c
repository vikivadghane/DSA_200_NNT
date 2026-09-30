#include <stdio.h>
#include <stdlib.h>

#define size 5

struct Queue
{
    int que[size];
    int front, rear;
} Q;

int Qfull()
{
    if (Q.rear >= size - 1)
        return 1;
    else
        return 0;
}

int insert(int item)
{
    if (Q.front == -1)
        Q.front = 0;

    Q.rear++;
    Q.que[Q.rear] = item;

    return Q.rear;
}

int Qempty()

{
    if (Q.front == -1 || Q.front > Q.rear)
        return 1;
    else
        return 0;
}

int delet()
{
    int item;

    item = Q.que[Q.front];
    Q.front++;

    printf("\nDeleted item is %d", item);

    return item;
}

void display()
{
    int i;

    printf("\nThe elements are:\n");

    for (i = Q.front; i <= Q.rear; i++)
    {
        printf("%d ", Q.que[i]);
    }
}

int main()
{
    int choice, item;
    char ans;

    Q.front = -1;
    Q.rear = -1;

    do
    {
        printf("\n\tMain menu");
        printf("\n1. Insert\n2. Delete\n3. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (Qfull())
            {
                printf("\nQueue is full");
            }
            else
            {
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(item);
            }
            break;

        case 2:
            if (Qempty())
            {
                printf("\nQueue is empty");
            }
            else
            {
                delet();
            }
            break;

        case 3:
            if (Qempty())
            {
                printf("\nQueue is empty");
            }
            else
            {
                display();
            }
            break;

        default:
            printf("\nWrong choice");
            break;
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
