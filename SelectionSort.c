#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionsort(int arr[], int n)
{
  int i, j, min;
  for (j = 0; j < (n - 1); j++)
    {
      for (i = 0; i < n; i++)
        {
          if (arr[i] > arr[i+1])
          swap(&arr[i], &arr[i+1]);
        }
    }
}

void printArray(int arr[], int size){
  int k;
  for(k=0; k<size; k++)
      printf("%d ", arr[k]);
}

int main(){
  int arr[] = {23, 78, 5, 97, 12, 17};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectionsort(arr,n);
  printArray(arr,n);
  return 0;
}
