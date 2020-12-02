#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//计算一个数的每位之和（递归实现）
int DigitSum(int num, int sit); //计算一个数的每位之和（递归实现）
int main()
{
	int num;   //输入字符串长度必须小于100
	int sums = 0;
	scanf("%d",&num); //取出字符串首地址
	printf("递归求和结果为:  ",sums);
	sums = DigitSum(num, 1);
	printf(" = %d \r\n ",sums);
	printf("非递归求和结果为:  ",sums);
	sums = DigitSum(num, 0);
	printf(" = %d \n ", sums);
	return 0;
}
int DigitSum(int num, int sit)
{
	if (sit) //递归的方式
	{
		if (num / 10 > 0)  //倒序提取+输出
		{
			printf(" %d +", num % 10);
			return DigitSum(num/10,1) + num % 10;
			
		}
		else  
		{
			printf(" %d", num % 10);
			return num % 10;
		}
	}
	else  //非递归的方式
	{
		int sum = 0;
		while (num / 10 > 0)
		{
			printf(" %d +", num % 10);  //倒序提取+输出
			sum = sum + num % 10;
			num = num / 10;
		}
		printf(" %d", num % 10);  //提取最后一位
		sum = sum + num % 10;
		return sum;
	}
}