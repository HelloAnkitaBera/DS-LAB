#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)  
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}


void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Cannot delete\n");
    } else {
        printf("%d deleted from queue\n", queue[front]);
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);
    enqueue(70); 
    display();

    return 0;
}
