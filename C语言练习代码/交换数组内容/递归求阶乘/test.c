#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int JC(int num, int sit); //求阶乘
int main()
{
	int num = 0;
	int result = 0;
	printf("请输入一个整数\n");
	scanf("%d", &num);
	printf("递归法求阶乘：:\n");
	result=JC(num, 0);
	printf("结果为：%d", result);
	printf("\n非递归法求阶乘\n");
	result=JC(num, 1);
	printf("结果为：%d", result);
	return 0;
}

int JC(int num, int sit)
{
	if (sit)
	{
		if (num > 1)  //递归模式
		{
			return num * JC(num - 1, 0);
		}
		else
			return 1;
	}
	else            //循环模式
	{
		int i = 0;
		int result = 1;
		for (i = num; i > 0; i--)
		{
			result = result * i;
		}
		return result;
	}

}