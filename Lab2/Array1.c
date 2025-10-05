#include<stdio.h>
 void displayReverse(int arr[], int n){
    printf("Reverse array:\n");
    for(int i= n-1; i>=0; i--)
    printf("%d\n",arr[i]);

 }

 int main(){
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d element: \n",n);
    for(int i=0; i<n; i++)
    scanf("%d", &arr[i]);

    displayReverse(arr, n);
    return 0;
 }
    

