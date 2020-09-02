// this one works fine except for inputs like ()[]

#include <stdio.h>
#include <string.h>

#define size 20

int stack[size], top = -1;

void push(char ele) {
	stack[++top] = ele;
}

char pop() {
	return stack[top--];
}

int main() {
	int i, valid = 1;
	char brex[20];
	printf("enter expression: ");
	scanf("%s", brex);
	for(i = 0; i < strlen(brex); i++) {
		if(brex[i] == '(' || brex[i] == '{' || brex[i] == '[')
			push(brex[i]);
		if(brex[i] == ')' || brex[i] == '}' || brex[i] == ']') {
			if(top == -1)
				valid = 0;
			else {
				char popped = pop();
				if(popped == '(' && brex[i] != ')')
					valid = 0;
				if(popped == '{' && brex[i] != '}')
					valid = 0;
				if(popped == '[' && brex[i] != ']')
					valid = 0;
			}
		}	 
	}
	if(top != -1)
		valid = 0;

	if(valid == 0)
		printf("invalid\n");
	else
		printf("valid\n");
}
