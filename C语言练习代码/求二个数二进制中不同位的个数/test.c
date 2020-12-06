#define _CRT_SECURE_NO_WARNINGS 1

//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
#include <stdio.h>
int Gs(int a, int b);
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入二个数\n");
	scanf("%d %d",&a,&b);
	printf("共有 %d 个不同的位",Gs(a,b));
	return 0;
}
//按位异或  相同为0 不同为1，最后计算1的个数
int Gs(int a,int b)
{
	int i = 0;
	int sum = 0;
	int c = a^ b;
	for(i = 0; i < 32; i++)
	{
		sum += c & 1;
		c =c >> 1;
	}
	return sum;
}