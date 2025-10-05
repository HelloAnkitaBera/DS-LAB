#include <stdio.h>
int findSecondLargest(int arr[], int n) {
int first, second;
if (n < 2) {
printf("Array should have at least 2 elements.\n");
return -1;
}
first = second = -2147483648;
for (int i = 0; i < n; i++) {
if (arr[i] > first) {
second = first;
first = arr[i];
} else if (arr[i] > second && arr[i] < first) {
    second = arr[i];
}
}
if (second == -2147483648) {
printf("No second largest element found (all elements may be equal).\n");
return -1;
}
return second;
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
int secondLargest = findSecondLargest(arr, n);
if (secondLargest != -1) {
printf("Second largest element: %d\n", secondLargest);
}
return 0;
}