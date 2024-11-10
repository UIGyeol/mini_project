#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
typedef char* element; // 변경: element를 문자열 포인터로 정의
typedef struct stackNode {
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top = NULL;

int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);
void autoCloseTag(char* exp);

// HTML 태그를 보고 자동으로 닫기 태그 출력
void autoCloseTag(char* exp) {
    if (strcmp(exp, "<div>") == 0) {
        printf("</div>\n");
    }
    else if (strcmp(exp, "<a>") == 0) {
        printf("</a>\n");
    }
    else if (strcmp(exp, "<body>") == 0) {
        printf("</body>\n");
    }
    else {
        printf("알 수 없는 태그입니다.\n");
    }
}

int isStackEmpty(void) {
    return top == NULL;
}

void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

element pop(void) {
    if (isStackEmpty()) {
        printf("\n\nStack is Empty!\n");
        return NULL;
    }
    stackNode* temp = top;
    element item = temp->data;
    top = temp->link;
    free(temp);
    return item;
}

element peek(void) {
    if (isStackEmpty()) {
        printf("\n\nStack is empty\n");
        return NULL;
    }
    return top->data;
}

void printStack(void) {
    stackNode* p = top;
    printf("\nSTACK [");
    while (p) {
        printf("%s ", p->data);
        p = p->link;
    }
    printf("]\n");
}

int main(void) {
    char express[50];  // 크기를 지정하여 메모리 할당
    printf("HTML 태그를 입력하세요: ");
    scanf("%s", express);  // 문자열 입력 받음
    printf("입력된 태그: %s\n", express);
    autoCloseTag(express);  // 자동으로 닫기 태그 생성
    return 0;
}
