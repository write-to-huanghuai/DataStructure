//数组实现顺序栈
//2021.5.16
//20:19

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

#define ElemType int

typedef struct Stack {
	ElemType data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack *S);	//初始化栈
int StackEmpty(SqStack *S);	//判空，空返回1，否则返回0
int StackFull(SqStack *S);	//判满，满返回1.否则返回0
void Push(SqStack *S, ElemType e);	//进栈
void Pop(SqStack * S, ElemType *e);	//出栈

void InitStack(SqStack *S) {
	S->top = -1;
}

int StackEmpty(SqStack *S) {
	if (-1 == S->top)
		return 1;
	return 0;
}

int StackFull(SqStack * S){
	if (MAXSIZE - 1 == S->top)
		return 1;
	return 0;
}

void Push(SqStack * S, ElemType e){
	if (!StackFull(S)) {
		S->top++;
		S->data[S->top] = e;
		printf("进栈成功\n");

	}
	else
		printf("栈满\n");
}

void Pop(SqStack * S, ElemType *e) {
	if (!StackEmpty(S)) {
		*e = S->data[S->top];
		S->top--;
		printf("出栈成功");
	}
	else
		printf("空栈");
}

void GetTop(SqStack *S, ElemType *e) {
	if (!StackEmpty(S)) {
		*e = S->data[S->top];
		return;
	}
	else
		printf("栈空\n");
}

int main() {
	SqStack S;
	ElemType ele, *e;
	ele = 0;
	e = &ele;

	InitStack(&S);
	for (int i = 0; i < 5; i++)
		Push(&S, i);
	
	GetTop(&S, e);
	printf("栈顶元素为:%d\n", *e);

	for (int i = 0; i < 5; i++) {
		Pop(&S, e);
		printf("第%d个元素:%d\n", i, *e);
	}
	return 0;
}
