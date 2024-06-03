/*

//1. WAP to implement a single linked list and show all of its operations.

#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node* next;
};
struct node* list = NULL;
void insertnode(struct node* pred, int val)
{
struct node* ins = (struct node*) malloc(sizeof(struct node));
ins->info = val;
ins->next = NULL;
if(pred == NULL)
{
ins->next = list;
list = ins;
}
else
{
ins->next = pred->next;
pred->next = ins;
}
}
void deletenode(struct node* del)
{
if(del == list)
{
	list = del->next;
}
else
{
struct node* pred = list;
while (pred->next != del)
{
pred = pred->next;
}
pred->next = del->next;
}
free(del);
}
void display()
{
struct node* temp = list;
while(temp != NULL)
{
printf("%d\t", temp->info);
temp = temp->next;
}
}
int main()
{
insertnode(NULL, 7);
insertnode(list, 10);
insertnode(list, 16);
deletenode(list->next);
display();
}

*/


//2. WAP to implement a single linked list and show operations for insertion and
//deletion in kth position


#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global variable to keep track of the head of the linked list
struct Node* head = NULL;

// Function to insert a new node with value 'value' at position 'pos' in the list
void insertAtPosition(int value, int pos) {
	int i;
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d\n", value, pos);
        return;
    }
    struct Node* temp = head;
    for ( i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, pos);
}

// Function to delete the node at position 'pos' from the list
void deleteAtPosition(int pos) {
	int i;
    if (head == NULL || pos < 1) {
        printf("List is empty or invalid position\n");
        return;
    }
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted %d from position %d\n", temp->data, pos);
        free(temp);
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for ( i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}

// Function to display all elements in the linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated to the linked list
void freeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Demonstration of single linked list operations
    insertAtPosition(5, 1); // Insert 5 at position 1
    insertAtPosition(10, 2); // Insert 10 at position 2
    insertAtPosition(15, 1); // Insert 15 at position 1
    displayList(); // Display the list
    deleteAtPosition(2); // Delete node at position 2
    displayList(); // Display the list after deletion
    deleteAtPosition(1); // Delete node at position 1
    displayList(); // Display the list after deletion
    deleteAtPosition(3); // Attempt to delete from an invalid position
    displayList(); // Display the list

    // Free memory allocated to the list before terminating the program
    freeList();

    return 0;
}

/*
//3. WAP to implement a double linked list and show all of its operations.


#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *left, *right;
};
struct node* list = NULL;
void insertnode(struct node* pred, int val)
{
struct node* ins = (struct node*) malloc(sizeof(struct node));
ins->info = val;
ins->left = NULL;
ins->right = NULL;
if(pred == NULL)
{
ins->right = list;
list = ins;
struct node *succ = ins->right;
if(succ != NULL)
succ->left = ins;
}
else
{
ins->right = pred->right;
pred->right = ins;
struct node *succ = ins->right;
if(succ != NULL)
succ->left = ins;
ins->left = pred;
}
}
void deletenode(struct node* del)
{
if(del == list)
{
struct node *succ = del->right;
list = succ;
if(succ != NULL)
succ->left = NULL;
}
else
{
struct node *pred = del->left;
pred->right = del->right;
struct node *succ = del->right;
if(succ != NULL)
succ->left = pred;
}
free(del);
}
void display()
{
struct node* temp = list;
while(temp != NULL)
{
printf("%d\t", temp->info);
temp = temp->right;
}
}
int main()
{
insertnode(NULL, 7);
insertnode(list, 10);
insertnode(list, 16);
deletenode(list->right);
display();
}



//4. WAP to implement a double linked list and show operations for insertion and
//deletion in kth position.

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global variable to keep track of the head of the doubly linked list
struct Node* head = NULL;

// Function to create a new node with the given data
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node with value 'value' at the beginning of the list
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning\n", value);
}

// Function to insert a new node with value 'value' at the end of the list
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end\n", value);
}

// Function to delete the first occurrence of 'value' from the list
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }
    if (temp->prev == NULL) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Deleted %d from the list\n", value);
    free(temp);
}

// Function to display all elements in the doubly linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated to the doubly linked list
void freeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Demonstration of doubly linked list operations
    insertAtBeginning(5);
    insertAtBeginning(10);
    insertAtEnd(15);
    displayList();
    deleteNode(10);
    displayList();
    deleteNode(15);
    displayList();
    deleteNode(20); // Value not in list
    displayList();

    // Free memory allocated to the list before terminating the program
    freeList();

    return 0;
}



//5. WAP to implement a stack using linked list


#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *next;
};
struct node *top = NULL;
int isempty()
{
if(top == NULL)
return 1;
else
return 0;
}
void push(int val)
{
struct node* ins = (struct node*)
malloc(sizeof(struct node));
ins->info = val;
ins->next = NULL;
ins->next = top;
top = ins;
}
int peek()
{
if(isempty())
printf("Stack is empty.\n");
else
return top->info;
}
int pop()
{
if(isempty())
printf("Stack is empty.\n");
else
{
struct node *temp = top;
int data = top->info;
top = top->next;
free(temp);
return data;
}
}
int main()
{
push(1);
push(12);
push(15);
push(20);
printf("Element at top of the stack:%d\n", peek());
printf("Popped element: %d\n",
pop());
printf("Popped element: %d\n",
pop());
printf("Element at top of the stack:%d\n", peek());
}

*/

//6. WAP to implement a queue using linked list.


#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node with the given data
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = queue->front;
    int value = temp->data;
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    free(temp);
    return value;
}

// Function to display all elements in the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated to the queue
void freeQueue(struct Queue* queue) {
    struct Node* temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main()
 {
    // Demonstration of queue operations
    struct Queue* queue = createQueue();
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    displayQueue(queue);
    printf("Dequeued %d\n", dequeue(queue));
    displayQueue(queue);
    printf("Dequeued %d\n", dequeue(queue));
    displayQueue(queue);
    printf("Dequeued %d\n", dequeue(queue));
    displayQueue(queue);
    printf("Dequeued %d\n", dequeue(queue)); // Queue underflow
    freeQueue(queue);
    return 0;
}

