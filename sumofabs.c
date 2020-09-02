#include <stdio.h>

void sumOfAbsoluteDifferences(int arr[], int n) { 
    int sum = 0; 
    for (int i = 0; i < n - 1; i++) {
		sum += abs(arr[i] - arr[i + 1]);
    }
    printf("%d\n", sum);
} 

int main() { 
    int arr[] = {5, 4, 3, 1, 2}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    sumOfAbsoluteDifferences(arr, n);
    return 0; 
}