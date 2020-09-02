#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *last = NULL;

void addBeg() {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	printf("enter data: ");
	scanf("%d", &temp -> data);
	
	if(last == NULL) {
		temp -> next = temp;
		last = temp;
	}

	else {
		temp -> next = last -> next;
		last -> next = temp;
	}
}

void display() {
	if(last == NULL) {
		printf("list empty\n");
		return;
	}

	struct node *q = last -> next;

	printf("elements are: ");

	do {
		printf("%d ", q -> data);
		q = q -> next;
	} while(q != last -> next);

	printf("\n");
}

void addAfter() {
	struct node *trav, *temp;
	int pos;

	if(last == NULL) {
		printf("list empty\n");
		return;
	}

	trav = last -> next;

	printf("enter position: ");
	scanf("%d", &pos);

	while(pos--) {
		trav = trav -> next;
		if(trav == last -> next) {
			printf("invalid position\n");
			return;
		}
	}

	temp = (struct node *)malloc(sizeof(struct node));

	printf("enter data: ");
	scanf("%d", &temp -> data);

	temp -> next = trav -> next;
	trav -> next = temp;
}

void delByPos() {
	struct node *trav, *prev;
	int pos;

	if(last == NULL) {
		printf("list empty\n");
		return;
	}

	if(last -> next == last) {
		last = NULL;
		return;
	}

	printf("enter position: ");
	scanf("%d", &pos);

	prev = last -> next;

	while(pos-- - 1) {
		prev = prev -> next;
		if(prev == last -> next) {
			printf("invalid position\n");
			return;
		}
	}

	trav = prev -> next;
	prev -> next = trav -> next;

	free(trav);
}

int main() {
	while(1) {
		int ch;
		printf("1. addBeg\n2. addAfterPos\n3. delByPos\n4. display\nenter choice: ");
		scanf("%d", &ch);

		switch(ch) {
			case 1: addBeg();
				break;
			case 2: addAfter();
				break;
			case 3: delByPos();
				break;
			case 4: display();
				break;
		}
	}
}
