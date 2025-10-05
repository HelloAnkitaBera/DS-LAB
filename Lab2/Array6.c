#include <stdio.h>
void mergeArrays(int arr1[], int arr2[], int merged[], int n){
for (int i=0; i<n; i++){
merged[i]=arr1[i];
}
for (int i=0; i<n; i++){
merged[n+i]=arr2[i];
}
}
void sortDescending(int arr[], int size){
int temp;
for (int i=0; i<size-1; i++){
for (int j= i+1; j<size; j++){
if (arr[i]< arr[j]){
temp= arr[i];
arr[i]=arr[j];
arr[j]=temp;
}}}}
int main(){
int n;
printf("Enter the size of the arrays:");
scanf("%d", &n);
int arr1[n], arr2[n], merged[2*n];
printf("Enter %d elements for first array:\n", n);
for (int i=0; i<n; i++){
scanf("%d", &arr1[i]);
}
printf("Enter elements for second array:\n",n);
for (int i=0; i<n; i++){
scanf("%d", &arr2[i]);
}
mergeArrays(arr1, arr2, merged, n);
sortDescending(merged, 2*n);
printf("Merged array in descending order:\n");
for(int i=0; i<2*n; i++){
printf("%d", &merged[i]);
}
printf("\n");
return 0;
}