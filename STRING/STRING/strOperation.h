#pragma once
#ifndef STROPERATION_H
#define STROPERATION_H
#include"str.h"
#include<malloc.h>
#include<iostream>
using namespace std;

// 将常量字符串复制给SString
void StrAssign(SString &T, char s[],int length);
// 两个SString字符串进行连接
bool Concat(SString& T, SString S1, SString S2);
bool Concat(HString& T, HString S1, HString S2);

// 截取S的字符串
int SubString(SString &Sub, SString S,int pos, int len);
int SubString(HString &Sub, HString S, int pos, int len);

void StrAssign(HString &T, char s[], int length);
// 在S串的pos字符前插入串T
bool StrInsert(HString &S, HString T, int pos);

void PrintString(HString S);
#endif // !STROPERATION_H
