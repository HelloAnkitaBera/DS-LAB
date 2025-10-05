#include <stdio.h>
int countDuplicates(int arr[], int n){
int count =0;
for(int i=0; i<n; i++){
int isDuplicate=0;
for(int j= i+1; j<n; j++){
if(arr[i]==arr[j]){
isDuplicate=1;
break;
}
}
int alreadyCounted=0;
for(int k=0; k<1; k++){
if(arr[i]==arr[k]){
alreadyCounted=1;
break;
}
}
if (isDuplicate && ! alreadyCounted){
count ++;
}
}
return count;
}
int main(){
int n;
printf("Enter number of elements:");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements:\n", n);
for(int i=0; i<n; i++){
scanf("%d", &arr[i]);
}
int totalDuplicates= countDuplicates(arr,n);
printf("Total number of duplicate elements:%d\n", totalDuplicates);
return 0;
}