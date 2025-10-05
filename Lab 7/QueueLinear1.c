#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Insertion
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)  // first element
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

// Deletion
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete\n");
    } else {
        printf("%d deleted from queue\n", queue[front]);
        front++;
    }
}

// Display
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); // Overflow
    display();

    return 0;
}
