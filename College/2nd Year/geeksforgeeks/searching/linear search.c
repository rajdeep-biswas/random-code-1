#include <stdio.h>

int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int scan, flag = -1;

	printf("enter element to search: ");
	scanf("%d", &scan);

	for(int i = 0; i < 7; i++)
		if(arr[i] == scan) {
			flag = i;
			break;
		}

	if(flag != -1)
		printf("element found at %d\n", flag);
	else
		printf("element not found\n");
}