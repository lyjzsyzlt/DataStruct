#ifndef STRING_H
#define STRING_H

//������ʾ
const int MAXSTRLEN = 10;
// 0�ŵ�Ԫ��Ŵ��ĳ���
typedef unsigned char SString[MAXSTRLEN + 1]; 

// �ַ����ѷ���洢��ʾ
typedef struct
{
	char* ch;
	int length;
}HString;

#endif // !STRING_H
