#define _CRT_SECURE_NO_WARNINGS 1

//统计二进制中1的个数
#include <stdio.h>

int main()
{
	int a = 0;
	printf("请输入一个数\n");
	scanf("%d",&a);
	printf("%d 的二进制中1的个数为: %d", a, One_Num(a));
	return 0;
}
int One_Num(int a)
{
	int i = 0;
	int num = 0;
	for (i = 0; i < 32; i++)
	{
		if ((a & 1) == 1)
		{
			num++;
		}
		a = a >> 1;
	}
	return num;
}