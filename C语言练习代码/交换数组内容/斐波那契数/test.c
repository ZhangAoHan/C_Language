#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//递归和非递归分别实现求第n个斐波那契数
int FB(int num, int sit);  //实现求第n个斐波那契数
int main()
{
	int n = 0;
	int sum = 0;
	printf("请输入：n\n");
	scanf("%d", &n);
	sum = FB(n, 1);
	printf("递归结果为： %d \n", sum);
	sum = FB(n, 0);
	printf("非递归结果为： %d \n", sum);
	return 0;
}
int FB(int num, int sit)
{
	if (sit)
	{
		if (num > 2)
		{
			return FB(num-1,1)+FB(num-2,1);
		}
		else
		{
			return 1;
		}
	}
	else
	{
		int i = 2;
		int a = 1;
		int b = 1;
		int c = 1;
		if (num > 2)
		{
			while ( i < num)
			{
				a = b;
				b = c;
				c = a + b;
				i++;
			}
			return c;
		}
		else
		{
			return 1;
		}
	}
}