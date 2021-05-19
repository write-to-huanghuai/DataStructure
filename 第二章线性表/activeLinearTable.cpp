// 动态线性表
// 2021.5.14  
// 20:31
// 创、销(无)、增、删、改(无)、查(无)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define ElemType int

typedef struct{
	ElemType * elem;//指示动态分配数组的指针
	int length;		//当前长度
	int listsize;	//顺序表的最大容量
}SqList;

Status InitList(SqList *L);	//初始化
Status ListInsert(SqList *L, int i, ElemType e); //插入
Status ListDelete(SqList *L, int i);	//删除
void printTable(SqList L);	//打印


Status InitList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));	//申请100空间
	if (!L->elem)	//申请失败
		return ERROR;
	L->length = 0;	//长度0
	L->listsize = LIST_INIT_SIZE;	//容量100
	return OK;	//申请成功
}

Status ListInsert(SqList *L, int i, ElemType e) {
	int j;
	ElemType *newbase;
	if (i<1 || i>L->length + 1)
		return ERROR;	//非法输入

	if (L->length >= L->length) {	//已存满，需更大空间
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));//大10的空间
		
		if (!newbase)	//申请失败
			return ERROR;

		L->elem = newbase;	//指针的连接
		L->listsize += LISTINCREMENT;	//新容量
	}

	for (j = L->length; j > i - 1; j--)	//复制之前的值到新的线性表中
		L->elem[j] = L->elem[j - 1];

	L->elem[i - 1] = e;	//插入操作
	printf("第%d个 %d 插入成功\n", i, L->elem[i - 1]);

	L->length++;
	return OK;
}

Status ListDelete(SqList * L, int i)
{
	int j;
	if (i<1|| i>L->length)	//	非法输入
		return ERROR;
	for (j = i - 1; j <= L->length; j++)	//将删除值后的线性表值前移
		L->elem[j] = L->elem[j + 1];
	(L->length)--;
	return OK;
}

void printTable(SqList L) {
	printf("\n");
	for (int i = 0; i < L.length; i++) {
		printf("i=%d\t", i);
		printf("%d \n", L.elem[i]);
	}
	printf("\n\n");
}

int main(){
	SqList L;
	int i;
	ElemType e;
	ElemType data[9] = { 1,2,3,4,5,6,7,8,-99 };
	InitList(&L);
	
	for (i = 1; i <= 9; i++) {
		ListInsert(&L, i, data[i-1]);
	}
	printTable(L);

	ListDelete(&L, 2);

	printTable(L);

	return 0;
}
