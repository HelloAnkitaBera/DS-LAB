#include <stdio.h>
void printUniqueElements (int arr[], int n){
printf("Unique elements are:\n");
for (int i=0; i<n; i++){
int isDuplicate =0;

for (int j=0; j<n; j++){
if (arr[i]==arr[j] && i!=j){
isDuplicate= 1;
break;
}
}
if(!isDuplicate){
printf("%d", arr[i]);
}
}
printf("\n");
}
int main(){
int n;
printf("Enter the number of elements:");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements:\n", n);
for (int i=0; i<n; i++){
scanf("%d", &arr[i]);
}
printUniqueElements (arr,n);
return 0;
}