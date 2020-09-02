#include <stdio.h>

void dat(int arr[], int l, int h) {
	int m = (l + h) / 2;
	if(l + 1 == h) {
		printf("%d %d\n", arr[l], arr[h]);
		return;
	}
	dat(arr, l, m);
	dat(arr, m + 1, h);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    dat(arr, 0, size);
    return 0; 
} 