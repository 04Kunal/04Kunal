//1. WAP to implement linear queue using array.

#include<stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE];
int front = 0, rear = -1;
int isempty()
{
if(rear == -1)
return 1;
else
return 0;
}
int isfull()
{
if(rear == MAXSIZE - 1)
return 1;
else
return 0;
}
void enqueue(int data)
{
if(isfull())
printf("Queue is full.\n");
else
{
rear++;
queue[rear] = data;
}
}
void dequeue()
{
int data;
if(isempty())
printf("Queue is empty.\n");
else {
data = queue[front];
front ++;
if (front > rear) {
front = 0;
rear = -1;
}
printf("Dequeued element: %d\n", data);
}
} void peek()
{
if(isempty())
printf("Queue is empty.\n");
else
printf("Element at front:%d\n" , queue[front]);
}
void display()
{
if(isempty())
printf("Queue is empty.\n");
else
{
	int i;
for (i = front; i <= rear; i++)
printf("%d\n" , queue[i]);
}
}int main()
{
enqueue(3);
enqueue(5);
enqueue(9);
enqueue(1);
enqueue(12);
peek();
dequeue();
return 0;
}


//2. WAP to implement linear queue using array with switch case. 

#include<stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front = 0, rear = -1;

int isempty() {
    if (rear == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if (rear == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isfull())
        printf("Queue is full.\n");
    else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    int data;
    if (isempty())
        printf("Queue is empty.\n");
    else {
        data = queue[front];
        front++;
        if (front > rear) {
            front = 0;
            rear = -1;
        }
        printf("Dequeued element: %d\n", data);
    }
}

void peek() {
    if (isempty())
        printf("Queue is empty.\n");
    else
        printf("Element at front: %d\n", queue[front]);
}

void display() {
    if (isempty())
        printf("Queue is empty.\n");
    else {
        printf("Queue elements:\n");
        int i;
        for ( i = front; i <= rear; i++)
            printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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



//3. WAP to implement circular queue using array

#include <stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE];
int rear = - 1;
int front = -1;
int isempty()
{
if(rear == -1)
return 1;
else
return 0;
}
int isfull()
{
if(front == (rear + 1) % MAXSIZE )
return 1;
else
return 0;
}void enqueue(int data)
{
if(isfull())
printf("Queue is full.\n");
else
{
if(isempty())
{
rear = front = 0;
queue[rear] = data;
printf("Data Enqueued");
}
else {
rear = (rear + 1)%MAXSIZE;
queue[rear] = data;
printf("Data Enqueued\n");
}
}
}void dequeue()
{
int data;
if(isempty())
printf("Queue is empty.\n");
else
{
data = queue[front];
if(front == rear)
front = rear = - 1;
else
front = (front + 1) % MAXSIZE;
}
printf("Dequeued element:%d\n" , data);
}
void peek()
{
if(isempty())
printf("Queue is empty.\n");
else
printf("Front element: %d\n" , queue[front]);
}void display()
{
if(isempty())
printf("Queue is empty.\nù");
else
{
while(front != (rear +1)%MAXSIZE)
{
printf("%d\t", queue[front]);
front = (front+1)%MAXSIZE;
}
}
}
void main()
{
enqueue(4);
enqueue(5);
enqueue(9);
enqueue(1);
enqueue(12);
peek();
dequeue();
enqueue(15);
display();
}


//4. WAP to implement priority queue using array.


#include<stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE];
int front = 0, rear = -1;
int isempty()
{
if(rear == -1)
return 1;
else
return 0;
}
int isfull()
{
if(rear == MAXSIZE - 1)
return 1;
else
return 0;
}
void enqueue(int data)
{
if(isfull())
printf("Queue is full.\n");
else
{
rear++;
queue[rear] = data;
}
}void dequeue()
{
int data, i, temp = 0;
data = queue[front];
if(isempty())
printf("Queue is empty.\n");
else {
for(i=front+1;i<=rear;i++)
{
if(data > queue[i])
{
temp = i;
data = queue[i];
}
}
for(i=temp; i<rear; i++)
{
queue[i] = queue[i+1];
}
rear--;
printf("Dequeued elements:%d\n",data);
}
}
void peek()
{
if(isempty())
printf("Queue is empty.\n");
else
printf("Element at front:%d\n", queue[front]);
}
void display()
{
if(isempty())
printf("Queue is empty.\n");
else
{
	int i;
for ( i = front; i <= rear; i++)
printf("%d\t", queue[i]);
}
}
int main()
{
enqueue(3);
enqueue(5);
enqueue(9);
enqueue(12);
enqueue(1);
peek();
dequeue();
dequeue();
display();
return 0;
}


