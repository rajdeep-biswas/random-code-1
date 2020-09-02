#include <stdio.h>
#include <string.h>

char string[20], stringrev[20], stack[20];
int top = -1;

void push(char c) {
	stack[++top] = c;
}

char pop() {
	return stack[top--];
}

void display() {
	printf("%s\n", stack);
}

int main() {
	int i;
	printf("enter string: ");
	scanf("%s", string);

	printf("input: %s\n", string);
	
	for(i = 0; i < strlen(string); i++)
		push(string[i]);

	printf("stack: ");
	display();

	for(i = 0; i < strlen(stack); i++)
		stringrev[i] = pop();

	printf("reverse: %s\n", stringrev);
}
