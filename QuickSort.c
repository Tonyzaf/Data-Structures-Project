#include <stdio.h>

void swap (int *n1, int *n2){
int temp = *n1;
*n1 = *n2;
*n2 = temp;
}

void quicksort(int arr[],int left,int right){
   int i, j, pivot, temp;

   if(left<right){
      pivot=left;
      i=left;
      j=right;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<right)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            swap(&arr[i],&arr[j]);
         }
      }
      swap(&arr[pivot],&arr[j]);
      quicksort(arr,left,j-1);
      quicksort(arr,j+1,right);

   }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {23, 78, 5, 97, 17, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}