#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Years(int year); //判断闰年函数
int main()
{
	int year = 0;
	int sit = 1;
	do
	{
		printf("请输入年份\n");
		scanf("%d", &year);
		Years(year);
		printf("0:退出     1：继续\n");
		scanf("%d", &sit);
	} while (sit);

	return 0;
}

void Years(int year) //判断闰年函数
{
	if (year % 4 == 0 && year % 100 != 0) //闰年
	{
		printf("%d 年是闰年\n",year);
	}
	else
	{
		printf("%d 年不是是闰年\n", year);
	}
}