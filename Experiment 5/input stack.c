#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct stack { 
    int s[SIZE];
    int top;
} st;

int stfull() {
    if (st.top >= SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int stempty() {
    if (st.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int item) {
    st.top++;
    st.s[st.top] = item;
}

int pop() {
    int item = st.s[st.top];
    st.top--;
    return item;
}

void display() {
    int i;
    if (stempty()) {
        printf("\n Stack is empty!");
    } else {
        for (i = st.top; i >= 0; i--) {
            printf("\n %d", st.s[i]);
        }
    }
}

int main() {
    int item, choice;
    char ans;
    st.top = -1;

    printf("\n\t\t Implementation of Stack");
    do {
        printf("\n\n Main Menu");
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (stfull()) {
                    printf("\n Stack overflow! Stack is full.");
                } else {
                    printf("\n Enter the item to be pushed: ");
                    scanf("%d", &item);
                    push(item);
                }
                break;

            case 2:
                if (stempty()) {
                    printf("\n Stack underflow! Stack is empty.");
                } else {
                    item = pop();
                    printf("\n The popped element is %d", item);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\n Invalid choice!");
        }

        printf("\n Do you want to continue (Y/N)? ");
        scanf(" %c", &ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
