#pragma once
#ifndef STROPERATION_H
#define STROPERATION_H
#include"str.h"
#include<malloc.h>
#include<iostream>
using namespace std;

// �������ַ������Ƹ�SString
void StrAssign(SString &T, char s[],int length);
// ����SString�ַ�����������
bool Concat(SString& T, SString S1, SString S2);
bool Concat(HString& T, HString S1, HString S2);

// ��ȡS���ַ���
int SubString(SString &Sub, SString S,int pos, int len);
int SubString(HString &Sub, HString S, int pos, int len);

void StrAssign(HString &T, char s[], int length);
// ��S����pos�ַ�ǰ���봮T
bool StrInsert(HString &S, HString T, int pos);

void PrintString(HString S);
#endif // !STROPERATION_H
