/*
子任务名任务:1_2 动态顺序存储线性表的基本实现
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define ElemType int

typedef struct
{
	ElemType * elem;
	int length;
	int listsize;
}SqList;
//函数介绍
Status InitList(SqList *L); //初始化
Status ListInsert(SqList *L, int i, ElemType e);//插入
Status ListDelete(SqList *L, int i, ElemType *e);//删除
void ListPrint(SqList L);//输出打印
void DeleteMin(SqList *L);//删除最小

Status InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//申请100空间
	if (!L->elem)//申请失败
		return ERROR;
	L->length = 0;//长度0
	L->listsize = LIST_INIT_SIZE;//容量100
	return OK;//申请成功
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	int j;
	ElemType *newbase;
	if (i<1 || i>L->length + 1)
		return ERROR;//非法输入

	if (L->length >= L->listsize)//存满了，需要更大空间
	{
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));//大10的空间
		if (!newbase)//申请失败
			return ERROR;
		L->elem = newbase;//调指针
		L->listsize += LISTINCREMENT;//新容量
	}

	for (j = L->length; j > i - 1; j--)//从后往前覆盖
		L->elem[j] = L->elem[j - 1];
	L->elem[i - 1] = e;//在留出的位置赋值
	L->length++;//长度+1
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
	int j;
	if (i<1 || i>L->length)//非法输入/表空
		return ERROR;
	*e = L->elem[i - 1];//为了返回值
	for (j = i - 1; j <= L->length; j++)//从前往后覆盖
		L->elem[j] = L->elem[j + 1];
	(L->length)--;//长度减1
	return OK;//返回删除值
}

void ListPrint(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
	printf("\n");//为了美观
}

void DeleteMin(SqList *L)
{
	//表空在Listdelete函数里判断
	int i;
	int j = 0;//最小值下标
	ElemType *e;
	for (i = 0; i < L->length; i++)//寻找最小
	{
		if (L->elem[i] < L->elem[j])
			j = i;
	}
	ListDelete(L, j + 1, &e);//调用删除，注意j要+1
}

int main(void)
{
	SqList L;
	int i;
	ElemType e;
	ElemType data[9] = { 11,-22,-33,3,-88,21,77,0,-9 };
	InitList(&L);
	for (i = 1; i <= 9; i++)
	{
		ListInsert(&L, i, data[i - 1]);
	}
	printf("插入完成后 L = : ");
	ListPrint(L);
	ListDelete(&L, 2, &e);
	printf("删除第 2 个后L = : ");
	ListPrint(L);
	DeleteMin(&L);
	printf("删除L中最小值后L = : ");
	ListPrint(L);
	DeleteMin(&L);
	printf("删除L中最小值后L = : ");
	ListPrint(L);
	DeleteMin(&L);
	printf("删除L中最小值后L = : ");
	ListPrint(L);
}
