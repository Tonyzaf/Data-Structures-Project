#include <stdio.h>
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = {5, 12, 17, 23, 78, 97};
    int x = 12; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = search(arr, n, x); 
    (result == -1) ? printf("The Number Was Not Found") 
                   : printf("The Number Was Found In Cell No. %d",result); 
    return 0; 
} 