#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Str_len(char *str); //strlen
int main()
{
	char str[5];
	int len = 0;
	scanf("%s",str); //取出字符串首地址
	len = Str_len(str);
	printf("%d",len);
	return 0;
}

int Str_len(char* strs)
{
	if(*strs == '\0')
	{ 
		return 0;
	}
	else
	{
		return 1 + Str_len(strs +1);
	}
}
