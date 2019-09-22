#include <stdio.h>
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int s1 = m - l + 1; 
    int s2 =  r - m; 
  
    int Left[s1], Right[s2]; 
  
    for (i = 0; i < s1; i++) 
        Left[i] = arr[l + i]; 
    for (j = 0; j < s2; j++) 
        Right[j] = arr[m + 1+ j]; 
    
    i = 0;  
    j = 0;  
    k = l; 
    while (i < s1 && j < s2) 
    { 
        if (Left[i] <= Right[j]) 
        { 
            arr[k] = Left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < s1) 
    { 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
  
    while (j < s2) 
    { 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int arr[] = {23, 78, 5, 97, 17, 12};
    int size = sizeof(arr)/sizeof(arr[0]); 
    mergeSort(arr, 0, size - 1); 
    printf("\nSorted array is \n"); 
    printArray(arr, size); 
    return 0; 
} 