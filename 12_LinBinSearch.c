#include <stdio.h>

int Linearsearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[], int size, int element) {
    int low, mid , high;
    high = size - 1;
    low = 0;

    while (low <= high)
    {
        mid = (low+high)/2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid]<element){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
        
    }
    return -1;
}

int main() {
    // unsorted arrray for linear search
    // int arr[] = {23, 4, 1, 5, 73, 425, 521, 415, 6, 92, 45, 244, 5, 2, 6, 75, 7, 3};
    // int size = sizeof(arr) / sizeof(int);
    
    int element = 73;
    int arr[] = {2, 14, 31, 55, 73, 425, 521};
    int size = sizeof(arr) / sizeof(int);
    int searchIndex = BinarySearch(arr, size, element);
    if (searchIndex != -1) {
        printf("The element %d was found at index %d.\n", element, searchIndex);
    } else {
        printf("The element %d was not found in the array.\n", element);
    }
    
    return 0;
}
