#include <stdio.h>

#define size 5

int ch;
int q[size];
int rear = -1;
int front = -1;

void insert() {
	if(front == 0 && rear == size - 1 || front == rear + 1) {
		printf("queue overflow\n");
		return;
	}
	if(front == -1) {
		front = rear;
		rear = 0;
	}
	else {
		if(rear == size - 1)
			rear = 0;
		else
			rear++;
	}
	printf("enter element: ");
	scanf("%d", q[++rear]);
}

void delete() {
	if(front == -1) {
		printf("queue underflow\n");
	}
	ch = q[front];
	printf("element deleted: %d", ch);
	
	if(front == rear)
		front = rear = -1;
	else {
		if(front == size - 1)
			front = 0;
		else
			front++;
	}
}

void display() {
	int i;
	if(front == -1)
		printf("queue underflow\n");
	if(rear >= front)
		for(i = front; i < size; i++)
			printf("%d ", q[i]);
	else {
		for(i = front; i < size; i++)
			printf("%d ", q[i]);
		for(i = 0; i < rear; i++)
			printf("%d ", q[i]);
	}
	printf("\n");
}

int main() {
	int ch;
	while(1) {
		printf("1. insert\n2. delete\n3. display\n4. exit\nenter choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: return 0;
		}
	}
}
