#include <stdio.h>
#include <stdlib.h>
// Define node structure
struct Node {
int data;
struct Node* next;
};
struct Node* top = NULL; // top pointer of stack
// Function to push element into stack
void push(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Stack Overflow! Memory not available.\n");
return;
}

newNode->data = value;
newNode->next = top;
top = newNode;
printf("%d inserted into stack.\n", value);
}
// Function to pop element from stack
void pop() {
if (top == NULL) {
printf("Stack Underflow! Nothing to delete.\n");
return;
}
struct Node* temp = top;
printf("%d deleted from stack.\n", top->data);
top = top->next;
free(temp);
}
// Function to display stack
void display() {
if (top == NULL) {
printf("Stack is empty.\n");
return;
}
struct Node* temp = top;
printf("Stack elements are: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
// Main function with menu
int main() {
int choice, value;
while (1) {
printf("\n--- Stack Menu (Linked List) ---\n");
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
case 4:
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice! Try again.\n");
}
}
}