#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;
int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

int isStackEmpty(void) {
	if (top == NULL) return 1;
	else return 0;
}
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;
	top = temp;
}
element pop(void) {
	element item;
	stackNode* temp = top;
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty !\n");
		return 0;
	}
	else {
		item=temp ->data;
		top = temp->link;
		free(temp);
		return item;
	}
}
element peek(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is empty\n");
		return 0;
	}
	else {
		return (top->data);
	}

}

void printStack(void) {
	stackNode* p = top;
	printf("\n STACK[");
	while (p) {
		printf("%d", p->data);
		p = p->link;
	}
	printf("]");
}
int main(void) {
	element item;
	top = NULL;
	printf("\n**연결 스택 연산**\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();
	
	item = peek(); printStack();
	printf("\tpeek=>%d", item);
	
	item = pop(); printStack();
	printf("\tpop=>%d", item);

	item = pop(); printStack();
	printf("\tpop=>%d", item);

	item = pop(); printStack();
	printf("\tpop=>%d", item);

	getchar(); return 0;
}
