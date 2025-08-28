#include <stdio.h>

void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) printf("%d\n", arr[i]);
}

int main() {
int arr[] = {1, 2, 3, 4, 5}, arr2[] = {6, 7, 8, 9, 10};
int n = sizeof(arr) / sizeof(arr[0]), m = sizeof(arr2) / sizeof(arr2[0]);
printArray(arr, n);
printArray(arr, n);
printArray(arr2, m);

return 0;
}