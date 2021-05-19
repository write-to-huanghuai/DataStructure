// ��̬���Ա�
// 2021.5.16
// 16:18
// ��������ɾ���ġ���

#include<stdio.h>
#include<stdlib.h>

#define ElemType int
#define OK 1
#define ERROR 0

typedef struct Lnode{
	ElemType data;
	struct Lnode *next;
}Lnode;

Lnode ListHeadInsert(Lnode *L);	//����ͷ�巨��ʼ��
Lnode ListTailInsert(Lnode *L);	//����β�巨��ʼ��
Lnode *GetElem(Lnode *L, int i);	//������Ų���
Lnode *FindElem(Lnode *L, ElemType i);	//����ֵ���в��ң�����ƥ��ĵ�һ���ڵ�
Lnode NextInsert(Lnode *L, ElemType e, int i);	//���
Lnode PreInsert(Lnode *L, ElemType e, int i);	//ǰ��
Lnode ListDelete(Lnode *L, int i);	//ɾ���ڵ�
void ListPrint(Lnode *L);	//��ӡ����

Lnode ListHeadInsert(Lnode *L) {
	Lnode *s;
	ElemType x;

	//ͷ����ʼ��
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;		

	scanf("%d", &x);
	while (-1 != x) {//x == -1 ʱ����
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return *L;
}

Lnode ListTailInsert(Lnode *L) {
	Lnode *s, *p;
	ElemType x;
	//ͷ����ʼ��
	L = (Lnode*)malloc(sizeof(Lnode));
	p = L;
	p->next = NULL;

	scanf("%d", &x);
	while (-1 != x) {//x == -1 ʱ����
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = x;//ע�⽻��˳��
		p->next = s;
		s->next = NULL;
		p = p->next;
		scanf("%d", &x);
	}
	return *L;
}

Lnode *GetElem(Lnode *L, int i) {
	int j = 1;
	Lnode *p = L->next;

	if (i < 0) {
		printf("\n���ҵĵ�%d��λ�ò�����\n", i);
		return NULL;
	}

	while (p && i != j) {
		p = p->next;
		j++;
	}
	return p;
}

Lnode *FindElem(Lnode *L, ElemType e) {
	int j = 1;
	Lnode *p = L->next;

	while (p != NULL && p->data != e)
		p = p->next;

	return p;
}

Lnode NextInsert(Lnode *L, ElemType e, int i) {
	Lnode * s = (Lnode *)malloc(sizeof(Lnode));
	s->data = e;

	Lnode *p = GetElem(L, i-1);	//�ҵ�����ǰ��
	// λ�ò��ܻ�
	s->next = p->next;
	p->next = s;

	return *L;
}

Lnode PreInsert(Lnode *L, ElemType e, int i) {
	Lnode * s = (Lnode *)malloc(sizeof(Lnode));
	s->data = e;


	Lnode *p = GetElem(L, i - 1);	//�ҵ�����ǰ��
	// λ�ò��ܻ�
	s->next = p->next;
	p->next = s;

	//����p,s��ֵ
	ElemType temp = p->data;
	p->data = s->data;
	s->data = temp;

	return *L;
}

Lnode ListDelete(Lnode *L, int i) {
	Lnode *p, *q;
	p = GetElem(L, i - 1);	//�ҵ�ǰ���ڵ�
	q = p->next;	//qΪɾ���ڵ�
	p->next = q->next;
	free(q);
	return *L;
}

void ListPrint(Lnode *L) {
	int i = 0;
	while (L->next != NULL) {
		i++;
		L = L->next;
		printf("��%d���ڵ�ֵΪ: %d\n", i, L->data);
	}
}

int main() {
	Lnode L;
	L = ListTailInsert(&L);
	ListPrint(&L);

	printf("\n��%d��λ�õ�ֵΪ�� %d\n", 3, GetElem(&L, 3)->data);

	printf("\nֵΪ�� %d\n", 3, FindElem(&L, 3)->data);

	L = PreInsert(&L, 1010, 3);

	ListPrint(&L);

	ListDelete(&L, 3);

	ListPrint(&L);
	return 0;
}