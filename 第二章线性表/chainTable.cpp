///*
//������������:1_2 ��̬˳��洢���Ա�Ļ���ʵ��
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define LIST_INIT_SIZE 100
//#define LISTINCREMENT 10
//#define Status int
//#define OVERFLOW -1
//#define OK 1
//#define ERROR 0
//#define ElemType int
//
//typedef struct
//{
//	ElemType * elem;
//	int length;
//	int listsize;
//}SqList;
////��������
//Status InitList(SqList *L); //��ʼ��
//Status ListInsert(SqList *L, int i, ElemType e);//����
//Status ListDelete(SqList *L, int i, ElemType *e);//ɾ��
//void ListPrint(SqList L);//�����ӡ
//void DeleteMin(SqList *L);//ɾ����С
//
//Status InitList(SqList *L)
//{
//	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//����100�ռ�
//	if (!L->elem)//����ʧ��
//		return ERROR;
//	L->length = 0;//����0
//	L->listsize = LIST_INIT_SIZE;//����100
//	return OK;//����ɹ�
//}
//
//Status ListInsert(SqList *L, int i, ElemType e)
//{
//	int j;
//	ElemType *newbase;
//	if (i<1 || i>L->length + 1)
//		return ERROR;//�Ƿ�����
//
//	if (L->length >= L->listsize)//�����ˣ���Ҫ����ռ�
//	{
//		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));//��10�Ŀռ�
//		if (!newbase)//����ʧ��
//			return ERROR;
//		L->elem = newbase;//��ָ��
//		L->listsize += LISTINCREMENT;//������
//	}
//
//	for (j = L->length; j > i - 1; j--)//�Ӻ���ǰ����
//		L->elem[j] = L->elem[j - 1];
//	L->elem[i - 1] = e;//��������λ�ø�ֵ
//	L->length++;//����+1
//	return OK;
//}
//
//Status ListDelete(SqList *L, int i, ElemType *e)
//{
//	int j;
//	if (i<1 || i>L->length)//�Ƿ�����/���
//		return ERROR;
//	*e = L->elem[i - 1];//Ϊ�˷���ֵ
//	for (j = i - 1; j <= L->length; j++)//��ǰ���󸲸�
//		L->elem[j] = L->elem[j + 1];
//	(L->length)--;//���ȼ�1
//	return OK;//����ɾ��ֵ
//}
//
//void ListPrint(SqList L)
//{
//	int i;
//	for (i = 0; i < L.length; i++)
//		printf("%d ", L.elem[i]);
//	printf("\n");//Ϊ������
//}
//
//void DeleteMin(SqList *L)
//{
//	//�����Listdelete�������ж�
//	int i;
//	int j = 0;//��Сֵ�±�
//	ElemType *e;
//	for (i = 0; i < L->length; i++)//Ѱ����С
//	{
//		if (L->elem[i] < L->elem[j])
//			j = i;
//	}
//	ListDelete(L, j + 1, &e);//����ɾ����ע��jҪ+1
//}
//
//int main(void)
//{
//	SqList L;
//	int i;
//	ElemType e;
//	ElemType data[9] = { 11,-22,-33,3,-88,21,77,0,-9 };
//	InitList(&L);
//	for (i = 1; i <= 9; i++)
//	{
//		ListInsert(&L, i, data[i - 1]);
//	}
//	printf("������ɺ� L = : ");
//	ListPrint(L);
//	ListDelete(&L, 2, &e);
//	printf("ɾ���� 2 ����L = : ");
//	ListPrint(L);
//	DeleteMin(&L);
//	printf("ɾ��L����Сֵ��L = : ");
//	ListPrint(L);
//	DeleteMin(&L);
//	printf("ɾ��L����Сֵ��L = : ");
//	ListPrint(L);
//	DeleteMin(&L);
//	printf("ɾ��L����Сֵ��L = : ");
//	ListPrint(L);
//}