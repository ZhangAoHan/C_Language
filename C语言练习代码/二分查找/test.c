//二分查找
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };//模拟数组
int xb = -1;//下标
void Find_num(int len,int num)
{
	int left = 0;
	int right = len;
	int Success = 0;
	do
	{
		int sit = (left + right) / 2;//寻找中心下标
		if (arr[sit] > num) //num在左边
		{
			right = sit - 1;
		}
		else if (arr[sit] < num) //num在右边
		{
			left = sit + 1;
		}
		else //已经找到
		{
			xb = sit;
			Success = 1;
		}
		if ( left == right )
		{
			if (arr[sit] == num) //进行最后一次判断，防止漏掉
			{
				xb = sit;
			}
			Success = 1;
		
		}
	} while (!Success);
}

int main()
{
	int len = sizeof(arr) / sizeof(arr[0]) - 1;//最大下标
	printf("请输入一个数");
	int num = 0;
	scanf("%d",&num);
	Find_num(len, num);
	if (xb == -1)//没有找到
	{
		printf("没有找到");
	}
	else
	{
		printf("下标为：%d", xb);
	}
	

	return 0;
}