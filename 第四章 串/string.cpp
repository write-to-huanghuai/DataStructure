//2021.5.21
//19:27
//定长顺序串存储

#include<stdio.h>
#include<string.h>

#define MAXLEN 255
typedef struct {
	char ch[MAXLEN];
	int length;
}SString;

void StrAssign(SString &T, char chars[]);	//赋值
int StrCopy(SString &T, char S[]);	//复制
int StrEmpty(SString S);	//判空 1:空
int StrCompare(SString S, SString T);	//比较操作
int StrLength(SString S);	//求串长
int SubString(SString &sub, SString s, int pos, int len);	//求子串
int Concat(SString &T, SString s1, SString s2);	//串连接
int Index(SString s, SString t);	//定位
int ClearString(SString &S);	//清空
int DestroyString(SString &S);	//销毁


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
		printf("串中不存在pos位置的len长度子串\n");
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
