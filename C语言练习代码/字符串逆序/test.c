#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//字符串逆序（递归实现）
void Str_reverse(char* str, int sit); 
int main()
{
	char str[100];   //输入字符串长度必须小于100
	scanf("%s", str); //取出字符串首地址
	printf("递归反向结果为： ");
	Str_reverse(str, 1);
	printf("\n循环反向结果为： ");
	Str_reverse(str, 0);

	return 0;
}


void Str_reverse(char* strs, int sit)
{
	if (sit)       //递归实现
	{
		if (*strs != '\0')
		{
			Str_reverse(strs+1,1);
			printf("%c ", *strs);
		}
		//else  //打印  '\0'：空格（默认不打印）
		//{
		//	printf("%c ", *strs);
		//}
	}
	else  //循环实现
	{
		int i = 0;
		char* p = strs;
		while (*p != '\0') //取出‘\0’的地址
		{
			p++;
			i++;
		}
		while (i > 0) //不打印空格
		{
			printf("%c ",*(p-1));
			p--;
			i--;
		}
		//while (i >= 0) //打印空格
		//{
		//	printf("%c ", *p);
		//	p--;
		//	i--;
		//}
	}
}

