//2021.5.21
//19:27
//����˳�򴮴洢

#include<stdio.h>
#include<string.h>

#define MAXLEN 255
typedef struct {
	char ch[MAXLEN];
	int length;
}SString;

void StrAssign(SString &T, char chars[]);	//��ֵ
int StrCopy(SString &T, char S[]);	//����
int StrEmpty(SString S);	//�п� 1:��
int StrCompare(SString S, SString T);	//�Ƚϲ���
int StrLength(SString S);	//�󴮳�
int SubString(SString &sub, SString s, int pos, int len);	//���Ӵ�
int Concat(SString &T, SString s1, SString s2);	//������
int Index(SString s, SString t);	//��λ
int ClearString(SString &S);	//���
int DestroyString(SString &S);	//����


int main()
{
	SString s, t, sss;
	char string[] = "abcd";
	char str[] = "aaaaabcd";
	StrAssign(s, string);
	StrAssign(t, string);
	StrAssign(sss, str);
	//SubString(t, s, 1, 2);
	//Concat(sss, s, t);
	//puts(sss.ch);
	printf("index=%d\n", Index(sss, s));
	return 0;
}

void StrAssign(SString & T, char chars[])
{
	strcpy(T.ch, chars);
	int len = 0;
	int i = 0;
	while (T.ch[i++]) {
		len++;
	}
	T.length = len;
}

int StrCopy(SString & T, char S[])
{
	StrAssign(T, S);
	return 0;
}

int StrEmpty(SString S)
{
	if (!S.ch[0])
		return 0;
	return 1;
}

int StrCompare(SString S, SString T)
{
	return strcmp(S.ch, T.ch);
}

int StrLength(SString S)
{
	int len = 0;
	int i = 0;
	while (S.ch[i++]) {
		len++;
	}
	S.length = len;
	return len;
}

int SubString(SString & sub, SString s, int pos, int len)
{
	if (pos + len > s.length) {
		printf("���в�����posλ�õ�len�����Ӵ�\n");
		return -1;
	}
	int j = 0;
	int i = pos;
	while (i < (pos + len)) {
		sub.ch[j++] = s.ch[i++];
	}
	sub.ch[j++] = '\0';
	return 0;
}

int Concat(SString & T, SString s1, SString s2)
{
	strcpy(T.ch, s1.ch);
	strcat(T.ch, s2.ch);
	return 0;
}

int Index(SString s, SString t)
{
	SString sub;
	int pos = 0;
	int n = s.length;
	int m = t.length;
	while (pos <= n - m + 1) {
		SubString(sub, s, pos, m);
		if (StrCompare(sub, t) != 0)
			++pos;
		else
			return pos;
	}
	return 0;
}
