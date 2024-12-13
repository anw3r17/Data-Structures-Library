#include<stdio.h>
int binarysearch(int x, int arr[], int low, int high) {
    if(low<=high) {
        int mid = high+low/2;
        if(arr[mid] == x)
        return mid;
        else if(arr[mid] < x)
        return binarysearch(x, arr, mid+1, high);
        else
        return binarysearch(x, arr, low, mid-1);
    
    }
}
int main() {
    int arr[50], i, n, x;
    printf("Enter the size of the Array:");
    scanf("%d", &n);
    printf("Enter the Elements to be inserted into the Array:");
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the Element you want to search in the Array:");
    scanf("%d", &x);
    int index = binarysearch(x, arr, 0, n-1);
    printf("The Element is at Index: %d", index);
    return 0;
}
