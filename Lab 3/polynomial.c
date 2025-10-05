#include <stdio.h>
#define MAX 100
int poly1[MAX][2], poly2[MAX][2], result[MAX][2];
int size1 = 0, size2 = 0;
int inputPolynomial(int poly[MAX][2]) {
int n;
printf("Enter number of terms: ");
scanf("%d", &n);
printf("Enter each term as: coefficient exponent (highest exponent first)\n");
for(int i = 0; i < n; i++) {
printf("Term %d: ", i + 1);
scanf("%d%d", &poly[i][0], &poly[i][1]);}
return n;}
void displayPolynomial(int poly[MAX][2], int size) {
for(int i = 0; i < size; i++) {
printf("%dx^%d", poly[i][0], poly[i][1]);
if(i != size - 1) printf(" + ");}
printf("\n");}
int addPolynomials(int p1[MAX][2], int size1, int p2[MAX][2], int size2, int res[MAX][2]) {
int i = 0, j = 0, k = 0;
while(i < size1 && j < size2) {
if(p1[i][1] > p2[j][1]) {
res[k][0] = p1[i][0];
res[k][1] = p1[i][1];

i++;}
else if(p1[i][1] < p2[j][1]) {
res[k][0] = p2[j][0];
res[k][1] = p2[j][1];
j++;}
else {
res[k][0] = p1[i][0] + p2[j][0];
res[k][1] = p1[i][1];
i++;
j++;}
k++;}
while(i < size1) {
res[k][0] = p1[i][0];
res[k][1] = p1[i][1];
i++;
k++;}
while(j < size2) {
res[k][0] = p2[j][0];
res[k][1] = p2[j][1];
j++;
k++;}
return k;}
int multiplyPolynomials(int p1[MAX][2], int size1, int p2[MAX][2], int size2, int res[MAX][2]) {
int temp[MAX][2];
int k = 0;
for(int i = 0; i < size1; i++) {
for(int j = 0; j < size2; j++) {
temp[k][0] = p1[i][0] * p2[j][0];
temp[k][1] = p1[i][1] + p2[j][1];
k++;}}
int final[MAX][2];
int fsize = 0;
for(int i = 0; i < k; i++) {
int coeff = temp[i][0];
int exp = temp[i][1];
int found = 0;
for(int j = 0; j < fsize; j++) {
if(final[j][1] == exp) {
final[j][0] += coeff;
found = 1;
break;}}
if(!found) {
final[fsize][0] = coeff;
final[fsize][1] = exp;
fsize++;}}
for(int i = 0; i < fsize; i++) {
res[i][0] = final[i][0];
res[i][1] = final[i][1];
}
return fsize;
}
void main() {
int choice, resultSize;
do {
printf("\n--- Polynomial Operations Menu ---\n");
printf("1. Input First Polynomial\n");
printf("2. Input Second Polynomial\n");
printf("3. Display First Polynomial\n");
printf("4. Display Second Polynomial\n");

printf("5. Add Polynomials\n");
printf("6. Multiply Polynomials\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Input First Polynomial:\n");
size1 = inputPolynomial(poly1);
break;
case 2:
printf("Input Second Polynomial:\n");
size2 = inputPolynomial(poly2);
break;
case 3:
printf("First Polynomial: ");
displayPolynomial(poly1, size1);
break;
case 4:
printf("Second Polynomial: ");
displayPolynomial(poly2, size2);
break;
case 5:
resultSize = addPolynomials(poly1, size1, poly2, size2, result);
printf("Sum: ");
displayPolynomial(result, resultSize);
break;
case 6:
resultSize = multiplyPolynomials(poly1, size1, poly2, size2, result);
printf("Product: ");
displayPolynomial(result, resultSize);
break;
case 7:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Try again.\n");}}
while(choice != 7);

}