#include <stdio.h>

int BinarySearch(int arr[], int b, int t, int x){ 
    if (b <= t) { 
        int mid = b + (t - b) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return BinarySearch(arr, b, mid - 1, x); 
        return BinarySearch(arr, mid + 1, t, x); 
    } 
    return -1; 
} 

int main(void) 
{ 
    int arr[] = {5, 12, 17, 23, 78, 97};
    int x = 23; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = BinarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("The Number Was Not Found") 
                   : printf("The Number Was Found In Cell No. %d",result); 
    return 0; 
} 