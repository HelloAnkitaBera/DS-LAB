#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;


void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) { 
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    }
    printf("%d inserted into queue\n", value);
}


void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Cannot delete\n");
    } else if (front == rear) { 
        printf("%d deleted from queue\n", front->data);
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        printf("%d deleted from queue\n", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}


void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(50);
    enqueue(60);
    display();

    return 0;
}
