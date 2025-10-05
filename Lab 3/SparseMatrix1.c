#include <stdio.h>
#define MAX 100
typedef struct{
int row;
int col;
int value;
} Triplet;
int matrix[MAX][MAX], rows, cols;
void inputMatrix(){
int i, j;
printf("Enter number of rows and columns:");
scanf("%d%d", &rows, &cols);
printf("Enter elements of the matrix:\n");
for(i=0; i<rows; i++){
for(j=0; j<cols; j++){
printf("Element [%d][%d]:", i,j);
scanf("%d", &matrix[i][j]);}}}
int convertToTripletRowMajor(Triplet triplet[1]){
int k= 1,i,j;
for(i=0; i<rows; i++){
for (j=0; j<cols; j++){
if(matrix[i][j]!=0){
triplet[k].row=i;
triplet[k].col=j;
triplet[k].value=matrix[i][j];
k++;}}}
triplet[0].row=rows;
triplet[0].col=cols;
triplet[0].value=k-1;
return k;}
int convertToTripletColMajor(Triplet triplet[1]){
int k=1,i,j;
for(j=0; j<cols; j++){
for(i=0; i<rows; i++){
if(matrix[i][j]!=0){
triplet[k].row=i;
triplet[k].col=j;
triplet[k].value= matrix[i][j];
k++;}}}
triplet[0].row=rows;
triplet[0].col=cols;
triplet[0].value=k-1;
return k;}
void displayTriplet(Triplet triplet[], int size){
int i;
printf("\nTriplet Form:\n");

printf("Row\tCol\tValue\n");
for(i=0;i<size;i++){
printf("%d\t%d\t%d\n", triplet[i].row, triplet[i].col, triplet[i].value);}}
int main(){
int choice;
Triplet triplet[MAX];
int size;
do{
printf("\n--- Sparse Matrix Triplet Menu---\n");
printf("1.Input Sparse Matrix\n");
printf("2.Display Triplet in Row Major\n");
printf("3. Display Triplet in Column Major");
printf("4.Exit\n");
printf("Enter your choice:");
scanf("%d", &choice);
switch(choice){
case 1:
inputMatrix();
break;
case 2:
size= convertToTripletRowMajor(triplet);
displayTriplet(triplet,size);
break;
case 3:
size= convertToTripletColMajor(triplet);
displayTriplet(triplet,size);
break;
case 4:
printf("\nExiting...\n");
break;
deafult:
printf("Invalid Choice\n");}
} while(choice !=4);
return 0;
}