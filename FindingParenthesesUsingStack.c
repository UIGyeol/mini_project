#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char element;
typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

int testPair(char* exp);
stackNode* top;
int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

int testPair(char* exp) {
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(':
		case '[':
		case '{':
			push(symbol); break;
		case ')':
		case ']':
		case '}':
			
			if (isStackEmpty())return 0;

			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					return 0;
				else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;

}

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
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);
	if (testPair(express) == 1)
		printf("\n\n수식의 괄호가 맞게 사용되었습니다!");
	else
		printf("\n\n수식의 괄호가 틀렸습니다.");
	getchar();
	return 0;
}
