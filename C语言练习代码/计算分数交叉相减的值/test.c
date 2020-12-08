//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	double sum = 0;//结果
	for (i = 1; i <= 100; i++)
	{
		double j = 0;
		j = 1.0 / i;
		if (i % 2 == 0)
		{
			sum = sum - j;
		}
		else
		{
			sum = sum + j;
		}
	}
	printf("结果为：%f", sum);
	return 0;
}