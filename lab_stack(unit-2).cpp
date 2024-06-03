
/*
//1. WAP to implement stack using array.

#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

int isempty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if (top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void peek() {
    if (isempty())
        printf("Stack is empty.\n");
    else
        printf("Element at top: %d\n", stack[top]);
}

void pop() {
    int data;
    if (isempty())
        printf("Stack is empty.\n");
    else {
        data = stack[top];
        top = top - 1;
        printf("Popped element: %d\n", data);
    }
}

void push(int data) {
    if (isfull())
        printf("Stack is full.\n");
    else {
        top = top + 1;
        stack[top] = data;
    }
}

void display() {
    if (isempty())
        printf("Stack is empty.\n");
    else {
        int i;
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    peek();
    pop();
    pop();
    peek();
    display();

    return 0;
}

*/

//2. WAP to implement stack using array with switch case. (Operations should continue
//until user press exit.)

#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

int isempty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if (top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void peek() {
    if (isempty())
        printf("Stack is empty.\n");
    else
        printf("Element at top: %d\n", stack[top]);
}

void pop() {
    int data;
    if (isempty())
        printf("Stack is empty.\n");
    else {
        data = stack[top];
        top = top - 1;
        printf("Popped element: %d\n", data);
    }
}

void push(int data) {
    if (isfull())
        printf("Stack is full.\n");
    else {
        top = top + 1;
        stack[top] = data;
    }
}

void display() {
    if (isempty())
        printf("Stack is empty.\n");
    else {
        printf("Stack elements:\n");
        int i;
        for ( i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
