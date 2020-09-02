// this one is broken

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
	char post[20];
	int i, res;
	printf("enter postfix: ");
	scanf("%s", post);
	for(i = 0; i < strlen(post); i++) {
		if(post[i] != '+' && post[i] != '-' && post[i] != '/' && post[i] != '*')
			push(post[i]);
		else {
			int top = pop() - '0';
			int topm1 = pop() - '0';
			if(post[i] == '+')
				push(topm1 + top);
			else if(post[i] == '-')
				push(topm1 - top);
			else if(post[i] == '*')
				push(topm1 * top);
			else if(post[i] == '/')
				push(topm1 / top);
			printf("%d %d %d %d\n", top, topm1, top + topm1, stack[top + 1]);
		}	
		printf("%d\n", stack[top + 1]);
	}
	printf("result: %c\n", pop());
}
