
#include <stdio.h>
int Find_sushu(int min, int max); //输入寻找素数的范围
int main()
{
	int error = 0;
	error = Find_sushu(100, 200);
	if (error == 1)
	{
		printf("素数必须是大于1的自然数");
	}
	return 0;
}

int Find_sushu(int min, int max) //输入寻找素数的范围
{
	int i = 0;
	int j = 0;
	if (min <= 1) //素数必须大于1
	{
		return 1;
	}
	for (i = min; i <= max; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)//合数
			{
				break;
			}
		}
		if (j == i) 
		{
			printf("%d\n",i);
		}
	}
	return 0;
}