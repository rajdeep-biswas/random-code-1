#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

float weight = 0;

int count(int arr[], int low, int high, int x) 
{ 
  
    if ((low > high) || (low == high && arr[low] != x)) 
        return 0; 
   
    if (low == high && arr[low] == x) 
        return 1;

    printf("%d %d\n", arr[low], arr[high]); 
  
    return count(arr, low, (low + high) / 2, x) + count(arr, 1 + (low + high) / 2, high, x); 
} 

void printArray(float arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%.1f ", arr[i]); 
    printf("\n"); 
}
/*
void swap(float *a, float *b) {
   float t = *a;
   *a = *b;
   *b = t;
}

void heapPermutation(float a[], int size, int n) {   
    if (size == 1) {
        //count++;
        recursor(a, 0, n - 1);
        printf("weight: %0.2f\n", weight); 
        printArray(a, n);
        return; 
    } 
  
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n); 
        if (size % 2 == 1) 
            swap(&a[0], &a[size - 1]); 
        else
            swap(&a[i], &a[size - 1]);
    }
} 
*/
int factorial(int n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main() {
    int size = 5;
    printf("enter size: ");
//    scanf("%d", &size);
    int arr[] = {1, 2, 3, 4, 5}; //(float*) malloc(size * sizeof(int)); *also make the arr a pointer
//    printf("enter %d elements\n", size); 

//    for(int i = 0; i < size; i++)
//        scanf("%f", &arr[i]);
    count(arr, 0, size, 0);
    float finalweight = weight / factorial(size);
    printf("final weight: %f\n", finalweight);
    return 0; 
} 
