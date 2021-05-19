// 动态线性表
// 2021.5.16
// 16:18
// 创、增、删、改、查

#include<stdio.h>
#include<stdlib.h>

#define ElemType int
#define OK 1
#define ERROR 0

typedef struct Lnode{
	ElemType data;
	struct Lnode *next;
}Lnode;

Lnode ListHeadInsert(Lnode *L);	//链表头插法初始化
Lnode ListTailInsert(Lnode *L);	//链表尾插法初始化
Lnode *GetElem(Lnode *L, int i);	//按照序号查找
Lnode *FindElem(Lnode *L, ElemType i);	//按照值进行查找，返回匹配的第一个节点
Lnode NextInsert(Lnode *L, ElemType e, int i);	//后插
Lnode PreInsert(Lnode *L, ElemType e, int i);	//前插
Lnode ListDelete(Lnode *L, int i);	//删除节点
void ListPrint(Lnode *L);	//打印链表

Lnode ListHeadInsert(Lnode *L) {
	Lnode *s;
	ElemType x;

	//头结点初始化
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;		

	scanf("%d", &x);
	while (-1 != x) {//x == -1 时结束
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
	//头结点初始化
	L = (Lnode*)malloc(sizeof(Lnode));
	p = L;
	p->next = NULL;

	scanf("%d", &x);
	while (-1 != x) {//x == -1 时结束
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = x;//注意交换顺序
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
		printf("\n查找的第%d个位置不存在\n", i);
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

	Lnode *p = GetElem(L, i-1);	//找到插入前驱
	// 位置不能换
	s->next = p->next;
	p->next = s;

	return *L;
}

Lnode PreInsert(Lnode *L, ElemType e, int i) {
	Lnode * s = (Lnode *)malloc(sizeof(Lnode));
	s->data = e;


	Lnode *p = GetElem(L, i - 1);	//找到插入前驱
	// 位置不能换
	s->next = p->next;
	p->next = s;

	//交换p,s的值
	ElemType temp = p->data;
	p->data = s->data;
	s->data = temp;

	return *L;
}

Lnode ListDelete(Lnode *L, int i) {
	Lnode *p, *q;
	p = GetElem(L, i - 1);	//找到前驱节点
	q = p->next;	//q为删除节点
	p->next = q->next;
	free(q);
	return *L;
}

void ListPrint(Lnode *L) {
	int i = 0;
	while (L->next != NULL) {
		i++;
		L = L->next;
		printf("第%d个节点值为: %d\n", i, L->data);
	}
}

int main() {
	Lnode L;
	L = ListTailInsert(&L);
	ListPrint(&L);

	printf("\n第%d个位置的值为： %d\n", 3, GetElem(&L, 3)->data);

	printf("\n值为： %d\n", 3, FindElem(&L, 3)->data);

	L = PreInsert(&L, 1010, 3);

	ListPrint(&L);

	ListDelete(&L, 3);

	ListPrint(&L);
	return 0;
}