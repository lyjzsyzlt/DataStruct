// STRING.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"str.h"
#include"strOperation.h"
#include<iostream>
using namespace std;

int main()
{
	/*SString T;
	SString S1;
	SString S2;
	char s1[] = "1234567890";
	StrAssign(S1,s1,sizeof(s1));

	char s2[] = "789123123";
	StrAssign(S2, s2, sizeof(s2));
	
	if (Concat(T, S1, S2))
		cout << T << endl;

	SString Sub;
	if (SubString(Sub, S1, 1, 5))
		cout << Sub << endl;
*/
	HString S1, S2;
	char s1[] = "12345";
	StrAssign(S1, s1, sizeof(s1));
	char s2[] = "789";
	StrAssign(S2, s2, sizeof(s2));
	//cout<<StrInsert(S1, S2,7)<<endl;
	HString T;
	cout << Concat(T, S1, S2)<<endl;

	for (int i = 0; i < T.length; i++)
		cout << T.ch[i];
	cout << endl;
	HString Sub;
	cout << SubString(Sub, T, 2, 8) << endl;
	PrintString(Sub);

    return 0;
}

