#include <stdio.h>

void insertionSort(int arr[], int size)
{
    int i, j, t;
    for (i = 1; i < size; i++) {
        t = arr[i];
        j = i - 1;
        for (j = i - 1; j >= 0 && t < arr[j]; j--){
          arr[j + 1] = arr[j];
        }
        arr[j + 1] = t;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}


int main(){
  int arr[] = {23, 78, 5, 97, 12, 17};
  int n = sizeof(arr)/sizeof(arr[0]);
  insertionSort(arr,n);
  printArray(arr,n);
  return 0;
}