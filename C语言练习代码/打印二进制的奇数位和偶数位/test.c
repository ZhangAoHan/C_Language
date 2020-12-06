#define _CRT_SECURE_NO_WARNINGS 1

//打印整数二进制的奇数位和偶数位
#include <stdio.h>
void Printf_JO(int a);
int main()
{
	int a = 0;
	printf("请输入一个数\n");
	scanf("%d",&a);
	Printf_JO(a);
	return 0;
}
void Printf_JO(int a)
{
	int i = 0;
	int b = a;
	printf("从高位往低位取\n");
	printf("奇数位为： \n");
	for (i = 0; i < 16; i++)
	{
		printf("%d ",(b & 0x80000000) / 0x80000000);
		b = b << 2;
	}
	b = a;
	printf("\n偶数位为： \n");
	for (i = 0; i < 16; i++)
	{
		printf("%d ", (b & 0x40000000) / 0x40000000);
		b = b << 2;
	}
}