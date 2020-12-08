#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//打印二个数的最大公约数
int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
	printf("请输入二个数\n");
	scanf("%d %d", &a, &b);
	//将二个数排序 a<b
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	int i = 0;
	for (i = a; i >= 2; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("最大公约数为：%d", i);
			break;
		}
	}
	//如果没有找到，打印结果
	if (i == 1)
	{
		printf("没有最大公约数，二个数只能被1整除");
	}
	return 0;
}