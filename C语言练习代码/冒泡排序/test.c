#define _CRT_SECURE_NO_WARNINGS 1
//冒泡排序
#include <stdio.h>


int main()
{
	int arr[] = {1, 5, 3, 2, 9, 4, 6, 7, 8, 0}; //定义10个数
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int k = 0;
	//冒泡排序函数
	for (i = 1; i < len ; i++)
	{
		for (j = 0; j < len - i; j++) //第n轮 只用比较len-n个数就行
		{
			if (arr[j] > arr[j + 1])  //如果右边数小于左边，交换位置
			{
				k = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = k;
			}
		}
	}
	for (i = 0; i <= len - 1; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
