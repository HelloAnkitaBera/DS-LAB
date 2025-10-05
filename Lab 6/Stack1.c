#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value){
    if (top == MAX - 1)
    {
        printf("Stack Overflow cannot insert %d\n", value);
    }
    
}

void pop(){
    if(top == -1){
        printf("Stack Underflow. Cannot delete.\n");
    } else {
        int value = stack[top];
        printf("Delete from stack. Deleted %d\n", value);
        top--;
           printf("Stack is empty.\n");
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}