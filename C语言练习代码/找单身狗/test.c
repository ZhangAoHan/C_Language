#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void dsg(int* sz, int num, int* a, int* b);//sz为数组 ab为二只单身狗
int main()
{
	int a = 0;
	int b = 0;
	int sz[12] = { 1,2,3,4,5,6,7,5,4,3,2,1 };
	dsg(sz, 12, &a, &b);
	printf("二只单身狗是：%d %d", a, b);
	return 0;
}
//A^A=0
// 0^A=A  
// 1^2^3=1^3^2 满足交换律和结合律
//A^B
void dsg(int* sz, int num,int* a, int* b)//sz为数组 ab为二只单身狗
{
	int i = 0;
	int sum = 0;
	int* s = sz;
	*a = 0;
	*b = 0;
	//先求出二个单身狗异或的值
	for (i = 0; i < num; i++)
	{
		sum ^= *s;
		s++;
	}
	int sit = 0;//二个单身狗的一个不同的位
	for (i = 0; i < 32; i++)
	{
		if (sum & 1 << i)
		{
			sit = i;
			break;
		}
	}
	for (i = 0; i < num; i++)
	{
		if (*sz & (1 << sit))
		{
			*a ^= *sz;
		}
		else
		{
			*b ^= *sz;
		}
		sz++;
	}
}
