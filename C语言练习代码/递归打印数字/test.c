#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Print(int num, int sit); //打印每一位
int main()
{
	int num = 0;
	printf("请输入一个整数\n");
	scanf("%d",&num);
	printf("正序打印:\n");
	Print(num,1);
	printf("\n倒序打印:\n");
	Print(num, 0);
	return 0;
}

void Print(int num,int sit)
{
	if (sit)
	{
		//正序打印  
		if (num /10 > 0)
		{
			Print(num/10,sit);
			printf(" %d ,", num % 10);
		}
		else
		{
			printf(" %d ,", num % 10);
		}
	}
	else
	{
		//倒序打印
		if (num / 10 > 0)
		{
			printf(" %d ,", num % 10);
			Print(num / 10,sit);
		}
		else
		{
			printf(" %d ,", num % 10);
		}
	}
}