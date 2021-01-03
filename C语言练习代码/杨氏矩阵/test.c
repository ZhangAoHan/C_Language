#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int Find_num(int* a, int num1, int num2, int ob); //a为数组地址，num1为行数   num2为列数  ob为目标元素
int main()
{
	int a = 0;
	int b[4][4] = {  //定义一个杨氏矩阵
	1,2,3,4,
	2,4,6,8,
	3,5,7,9,
	4,6,9,10
	};
	printf("请输入要查找的整数\n");
	scanf("%d",&a);
	if (Find_num(b, 4, 4, a))
	{
		printf("找到了");
	}
	else
	{
		printf("没找到");
	}
}
//从矩阵的右上角开始查找num，如果a[i][j]<num，则往下查找；如果a[i][j]>num，则往左查找
//当a[i][j]等于num，或者i、j至少有一个超出矩阵范围，则结束查找。
//时间复杂度为m+n
int Find_num(int *a,int num1,int num2,int ob) //a为数组地址，num1为行数   num2为列数  ob为目标元素
{
	int hs = 0;
	int ls = num2;
	do
	{
		if (*(a + hs*(num2) + ls -1) > ob)
		{
			ls--;
		}
		else if (*(a + hs * (num2)+ls - 1) < ob)
		{
			hs++;
		}
		else
		{
			return 1; //有返回1
		}
		if (ls < 0 || hs < 0)
		{
			return 0;//没有返回0  
		}
	} while (1);
	
}