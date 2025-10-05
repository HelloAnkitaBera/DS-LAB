#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
int data;
struct Node *next;

};
struct Node *head = NULL;
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
// Display list
void display() {
if (head == NULL) {
printf("List is empty!\n");
return;
}
struct Node* temp = head;
printf("List: ");
do {
printf("%d ", temp->data);
temp = temp->next;
} while (temp != head);
printf("\n");
}
// Insert at beginning
void insertAtBeginning(int data) {
struct Node* newNode = createNode(data);
if (head == NULL) {
head = newNode;
head->next = head;
} else {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;
newNode->next = head;
temp->next = newNode;
head = newNode;
}
}
// Insert at end
void insertAtEnd(int data) {
struct Node* newNode = createNode(data);
if (head == NULL) {
head = newNode;
head->next = head;
} else {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;

temp->next = newNode;
newNode->next = head;
}
}
// Insert at position (1-based index)
void insertAtPosition(int data, int pos) {
if (pos == 1) {
insertAtBeginning(data);
return;
}
struct Node* newNode = createNode(data);
struct Node* temp = head;
for (int i = 1; i < pos - 1; i++) {
temp = temp->next;
if (temp == head) {
printf("Position out of range!\n");
free(newNode);
return;
}
}
newNode->next = temp->next;
temp->next = newNode;
}
// Delete at beginning
void deleteAtBeginning() {
if (head == NULL) {
printf("List is empty!\n");
return;
}
if (head->next == head) {
free(head);
head = NULL;
return;
}
struct Node* temp = head;
struct Node* last = head;
while (last->next != head)
last = last->next;
head = head->next;
last->next = head;
free(temp);
}
// Delete at end
void deleteAtEnd() {
if (head == NULL) {

printf("List is empty!\n");
return;
}
if (head->next == head) {
free(head);
head = NULL;
return;
}
struct Node* temp = head;
struct Node* prev = NULL;
while (temp->next != head) {
prev = temp;
temp = temp->next;
}
prev->next = head;
free(temp);
}
// Delete at position
void deleteAtPosition(int pos) {
if (head == NULL) {
printf("List is empty!\n");
return;
}
if (pos == 1) {
deleteAtBeginning();
return;
}
struct Node* temp = head;
struct Node* prev = NULL;
for (int i = 1; i < pos; i++) {
prev = temp;
temp = temp->next;
if (temp == head) {
printf("Position out of range!\n");
return;
}
}
prev->next = temp->next;
free(temp);
}
// Main function
int main() {
int choice, data, pos;
while (1) {
printf("\n--- Menu ---\n");
printf("1. Insert at Beginning\n");

printf("2. Insert at End\n");
printf("3. Insert at Position\n");
printf("4. Delete at Beginning\n");
printf("5. Delete at End\n");
printf("6. Delete at Position\n");
printf("7. Display\n");
printf("8. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data: ");
scanf("%d", &data);
insertAtBeginning(data);
break;
case 2:
printf("Enter data: ");
scanf("%d", &data);
insertAtEnd(data);
break;
case 3:
printf("Enter data and position: ");
scanf("%d %d", &data, &pos);
insertAtPosition(data, pos);
break;
case 4:
deleteAtBeginning();
break;
case 5:
deleteAtEnd();
break;
case 6:
printf("Enter position: ");
scanf("%d", &pos);
deleteAtPosition(pos);
break;
case 7:
display();
break;
case 8:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}