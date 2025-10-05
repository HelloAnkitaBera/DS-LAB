#include <stdio.h>
void countFrequency(int arr[], int n) {
int freq[n];
for (int i = 0; i < n; i++) {
freq[i] = -1;}
for (int i = 0; i < n; i++) {
int count = 1;
for (int j = i + 1; j < n; j++) {
if (arr[i] == arr[j]) {
count++;

freq[j] = 0;}}
if (freq[i] != 0) {
freq[i] = count;}}
printf("Element | Frequency\n");
for (int i = 0; i < n; i++) {
if (freq[i] != 0) {
printf(" %d | %d\n", arr[i], freq[i]);}}}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);}
countFrequency(arr, n);
return 0;}