#include <stdio.h>
int InterpolationSearch(int arr[], int n, int x) 
{  
    int lo = 0, hi = (n - 1); 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
    { 
        if (lo == hi){ 
            if (arr[lo] == x) return lo; 
            return -1; 
        }
        int pos = lo + (((double)(hi-lo) / 
              (arr[hi]-arr[lo]))*(x - arr[lo])); 
        if (arr[pos] == x) 
            return pos; 
        if (arr[pos] < x) 
            lo = pos + 1; 
        else
            hi = pos - 1; 
    } 
    return -1; 
} 

int main(void) 
{ 
    int arr[] = {5, 12, 17, 23, 78, 97};
    int x = 23; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = InterpolationSearch(arr, n - 1, x); 
    (result == -1) ? printf("The Number Was Not Found") 
                   : printf("The Number Was Found In Cell No. %d",result); 
    return 0; 
} 