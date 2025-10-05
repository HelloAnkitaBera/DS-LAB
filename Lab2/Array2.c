#include<stdio.h>
int findSum(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
    sum += arr[i];
    return sum;

}

 int main(){
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d element: \n",n);
    for(int i=0; i<n; i++)
    scanf("%d", &arr[i]);

    int result = findSum(arr, n);
    printf("Sum of array elements: %d\n",result);
    return 0;
 }