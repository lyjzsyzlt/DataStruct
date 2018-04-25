#include "stdafx.h"
#include "strOperation.h"

void StrAssign(SString & T, char s[], int length)
{
	T[0] = length+'0';
	if (length > MAXSTRLEN)
	{
		for (int i = 0; i < MAXSTRLEN; i++)
			T[i + 1] = s[i];
		T[MAXSTRLEN] = '\0';
	}
	else
	{
		for (int i = 0; i < length; i++) {
			T[i + 1] = s[i];
		}
	}
}


bool Concat(SString & T, SString S1, SString S2)
{
	bool success = false;
	int len1 = S1[0] - '0';
	int len2 = S2[0] - '0';
	// S1，S2都未截断
	if ((len1-1) +len2 <= MAXSTRLEN)
	{
		for (int i = 1; i <= len1-1; i++)
			T[i] = S1[i];
		for (int i =  1; i <= len2; i++)
			T[i+len1-1] = S2[i];
		T[0] = len1-1+len2+'0';
		success = true;
	}
	// S2被截断
	else if (len1-1 < MAXSTRLEN)
	{
		for (int i = 1; i <= len1-1; i++)
			T[i] = S1[i];
		for (int i = len1; i <= MAXSTRLEN - 1; i++)
			T[i] = S2[i - len1 + 1];
		T[MAXSTRLEN] = '\0';
		T[0] = MAXSTRLEN+'0';
		success = true;
	}
	// S1被截断
	else
	{
		for (int i = 1; i <= MAXSTRLEN-1; i++)
			T[i] = S1[i];
		T[MAXSTRLEN] = '\0';
		T[0] = MAXSTRLEN + '0';
		success = true;
	}
	return success;
}

bool Concat(HString & T, HString S1, HString S2)
{

	if (!(T.ch = new char[S1.length + S2.length + 1]))// +1 是最后的'\0'
		return 0;
	for (int i = 0; i < S1.length; i++)
		T.ch[i] = S1.ch[i];
	for (int i = 0; i < S2.length; i++)
		T.ch[i + S1.length] = S2.ch[i];
	T.ch[S1.length + S2.length] = '\0';
	T.length = S1.length + S2.length;
	return 1;
}

int SubString(SString & Sub,SString S, int pos, int len)
{
	int L = S[0] - '0';
	if (pos<1 || pos>L-1 || len<0 || len>L - pos + 1)
		return 0;
	for (int i = 1; i <= len-1; i++)
		Sub[i] = S[pos + i - 1];
	Sub[len] = '\0';
	Sub[0] = len + '0';
	return 1;
}

int SubString(HString & Sub, HString S, int pos, int len)
{
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return 0;
	
	if (!(Sub.ch = new char[len + 1]))
		return 0;
	for (int i = 0; i < len; i++)
		Sub.ch[i] = S.ch[pos - 1 + i];
	Sub.ch[len] = '\0';
	Sub.length = len;
	return 0;
}

void StrAssign(HString & T, char s[], int length)
{
	if (T.ch)
		T.ch = NULL;
	if (length == 0)
	{
		T.ch = NULL;
		T.length = 0;
	}
	else
	{
		T.ch = new char[length];
		for (int i = 0; i < length; i++)
			T.ch[i] = s[i];
		T.length = length-1; // 去掉最后的'\0'
	}
}

bool StrInsert(HString & S, HString T, int pos)
{
	if (pos<1 || pos>S.length + 1)
		return 0;
	if (T.length)
	{
		if (S.ch=(char* )realloc(S.ch,(S.length+T.length)*sizeof(char)))
		{
			for (int i = S.length - 1; i >= pos - 1; i--)
				S.ch[i + T.length - 1] = S.ch[i];
			for (int i = 0; i < T.length - 1; i++)
				S.ch[i + pos - 1] = T.ch[i];
			S.length = S.length + T.length;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void PrintString(HString S)
{
	for (int i = 0; i < S.length; i++)
		cout << S.ch[i];
	cout << endl;
}
