#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Mul(int num); //乘法口诀表函数
int main()
{
	int num = 0;
	int sit = 1;
	do
	{
		printf("请输入大小n: n*n的乘法表\n");
		scanf("%d", &num);
		Mul(num);
		printf("0:退出     1：继续\n");
		scanf("%d", &sit);
	} while (sit);

	return 0;
}
void Mul(int num)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 1; i <= num; i++)
	{
		for(j = 1; j <= i; j++)
		{
			sum = i * j;
			printf("  %d X %d = %d  ",i,j,sum);
		}
		printf("\n");
	}
}