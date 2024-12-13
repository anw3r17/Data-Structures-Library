#include <stdio.h>

int binary(int x, int arr[], int low, int high) {
    if (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            return binary(x, arr, mid+1, high);
        }
        else {
            return binary(x, arr, low, mid-1);
        }
    }
    return -1; 
}

int main() {
    int i, n, x, arr[100];
    printf("Enter the size of array:");
    scanf("%d", &n);
    printf("Enter the elements in the array:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &x);
    int index = binary(x, arr, 0, n-1);
    if (index == -1) {
        printf("Element not found\n");
    }
    else {
        printf("The element is at index %d\n", index);
    }
    return 0;
} 