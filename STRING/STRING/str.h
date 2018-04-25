#ifndef STRING_H
#define STRING_H

//定长表示
const int MAXSTRLEN = 10;
// 0号单元存放串的长度
typedef unsigned char SString[MAXSTRLEN + 1]; 

// 字符串堆分配存储表示
typedef struct
{
	char* ch;
	int length;
}HString;

#endif // !STRING_H
