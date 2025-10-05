#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
struct Node *head= NULL;
struct Node *createNode (int data){
struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
newNode->data= data;
newNode->next= NULL;
return newNode;
}
void insertAtBeginning(int data){
struct Node *newNode= createNode(data);
newNode->next= head;
head= newNode;
printf("Inserted %d at the beginning\n", data);
}
void insertAtEnd(int data){
struct Node *newNode= createNode(data);
if(head==NULL){
head= newNode;
printf("Inserted %d at the end.\n", data);
return;
}
struct Node *temp=head;
while(temp->next != NULL){
temp= temp-> next;
}
temp-> next= newNode;
printf("Inserted %d at the end.\n", data);
}
void insertAtPosition(int data, int position){
if(position<1){
printf("Invalid Position.\n");
return;
}
if(position==1){
insertAtBeginning(data);
return;
}
struct Node *newNode= createNode(data);
struct Node *temp= head;
for (int i= 1; i< position-1 && temp != NULL; i++){
temp= temp->next;}
if(temp==NULL){
printf("Position out of range.\n");
free(newNode);
return;
}
newNode->next=temp->next;
temp->next= newNode;
printf("Inserted %d at position %d.\n", data, position);

}
void deleteAtBeginning(){
if(head==NULL){
printf("List is empty.\n");
return;
}
struct Node *temp= head;
head= head->next;
printf("Deleted %d from beginning.\n", temp->data);
free(temp);
}
void deleteAtEnd(){
if (head==NULL){
printf("List is Empty.\n");
return;
}
if(head->next==NULL){
printf("Deleted %d from end.\n", head-> data);
free(head);
head=NULL;
return;
}
struct Node *temp=head;
while(temp->next->next != NULL){
temp= temp->next;
}
printf("Deleted %d from end.\n", temp->next->data);
free(temp->next);
temp->next=NULL;
}
void deleteAtPosition(int position){
if(position<1 || head==NULL){
printf("Invalid position or empty list.\n");
return;
}
if(position==1){
deleteAtBeginning();
return;}
struct Node *temp= head;
for(int i=1; i<position-1 && temp!=NULL; i++){
printf("Position out of range.\n");
return;
}
struct Node *toDelete= temp->next;
temp->next= toDelete->next;
printf("Deleted %d from position %d\n", toDelete->data, position);
free(toDelete);
}
void displayList(){
if (head==NULL){
printf("List is empty.\n");
return;
}
struct Node *temp=head;
printf("List:");
while(temp!= NULL){
printf("%d->", temp->data);

temp= temp->next;
}
printf("NULL\n");
}
int main(){
int choice, data, pos;
while(1){
printf("\n---MENU---\n");
printf("1. Insert At Beginning\n");
printf("2. Insert At End\n");
printf("3. Insert at Position\n");
printf("4. Delete from Beginning\n");
printf("5. Delete from End\n");
printf("6. Delete at Position\n");
printf("7. Display List\n");
printf("0. Exit\n");
printf("Enter your choice:");
scanf("%d", &choice);
switch(choice){
case 1:
printf("Enter data:");
scanf("%d", &data);
insertAtBeginning(data);
break;
case 2:
printf("Enter data:");
scanf("%d", &data);
insertAtEnd(data);
break;
case 3:
printf("Enter data:");
scanf("%d", &data);
printf("Enter position");
scanf("%d", &pos);
insertAtPosition(data, pos);
break;
case 4:
deleteAtBeginning();
break;
case 5:
deleteAtEnd();
break;
case 6:
printf("Enter position");
scanf("%d", &pos);
deleteAtPosition(pos);
break;
case 7:
displayList();
break;
case 0:
printf("Exiting...\n");
exit(0);
default:
printf("Invalid Choice.\n");
}
}

return 0;
}