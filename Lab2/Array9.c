#include <stdio.h>
void separateOddEven(int arr[], int n, int even[], int *evenCount, int odd[], int *oddCount) {
*evenCount = 0;
*oddCount = 0;
for (int i = 0; i < n; i++) {
if (arr[i] % 2 == 0) {
even[*evenCount] = arr[i];
(*evenCount)++;
} else {
odd[*oddCount] = arr[i];
(*oddCount)++;
}
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n], even[n], odd[n];
int evenCount, oddCount;
printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
separateOddEven(arr, n, even, &evenCount, odd, &oddCount);
printf("Even elements: ");
for (int i = 0; i < evenCount; i++) {
printf("%d ", even[i]);
}
printf("\n");
printf("Odd elements: ");
for (int i = 0; i < oddCount; i++) {
printf("%d ", odd[i]);
}
printf("\n");
return 0;
}