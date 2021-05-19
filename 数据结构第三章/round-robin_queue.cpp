//循环队列
//2021.5.17
//14.59
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 10
#define ElemType int

typedef struct SqQueue {
	ElemType data[MAXSIZE];
	int front, rear, size;
}SqQueue;

void InitQueue(SqQueue *q);	//初始化循环队列
int QueueEmpty(SqQueue q);	//判空 空为OK，否则为ERROR
int QueueFull(SqQueue q);	//判满 空为OK，否则为ERROR
int EnQueue(SqQueue *q, ElemType e);	//进队列
ElemType DeQueue(SqQueue *q);	//出队列
ElemType GetHead(SqQueue *q);	//读队头元素

void InitQueue(SqQueue *q){
	q->front = 0;
	q->rear = 0;
	q->size = 0;
}

int QueueEmpty(SqQueue q){
	if (q.rear == q.front)
		return OK;
	return ERROR;

	//way2:size == 0
}

int QueueFull(SqQueue q){
	if ((q.rear + 1 - q.front) % MAXSIZE == 0)	//书上一般是(q.rear+1)%MAXSIZE == q.frant
		return OK;
	return ERROR;

	//way2:size == MAXSIZE-1
}

int EnQueue(SqQueue *q, ElemType e){
	if (QueueFull(*q))
	{
		printf("队满\n");
		return ERROR;
	}	

	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;

	q->size++;

	printf("%d进队成功\n", e);
	return OK;
}

ElemType DeQueue(SqQueue * q){
	ElemType e;

	if (QueueEmpty(*q)) {
		printf("队列为空\n");
		return ERROR;
	}

	e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	q->size -= 1;
	printf("\n%d出队列成功\n", e);
	return e;
}

ElemType GetHead(SqQueue * q)
{
	if (QueueEmpty(*q)) {
		printf("队列为空\n");
		return ERROR;
	}
	return q->data[q->front];
}

int main() {
	SqQueue q;
	InitQueue(&q);
	
	for (int i = 1; i < 6; i++) {
		EnQueue(&q, i);
		printf("头为%d\n", GetHead(&q));
	}
	printf("\n\n\n\n");
	for (int i = 1; i < 6; i++) {
		DeQueue(&q);
		printf("头为%d\n", GetHead(&q));
	}
	return 0;
}
