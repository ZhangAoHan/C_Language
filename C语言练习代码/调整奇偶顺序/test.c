#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//输入一个整数数组，实现一个函数，
//
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//
//所有偶数位于数组的后半部分。
void Sz(int* arr, int num);
int main()
{
	int num = 0;  //输入字符串的数量
	int arr[200] = { 0 };
	int i = 0;
	printf("请输入一维数组\n");
	printf("最少输入一个数，最多不超过200个数\n");
	while (scanf("%d", &arr[num]) && getchar() != '\n')  //获取键入的int型数组
	{
		num++;
	}
	Sz(arr, num );
	for (i = 0; i <= num; i++)
	{
		printf("%d ",arr[i]);
	}
}

void Sz(int* arr, int num)  //调整奇偶顺序
{
	int arr1[200] = {0};
	int* arr2 = arr;
	int i = 0;  
	int j = num ; //偶数从末尾存放
	int k = 0;  //奇数从头存放
	while (i <= num)
	{
		if (*arr2 % 2 == 0) //偶数  放最后
		{
			arr1[j] = *arr2;
			arr2++;
			j--;
		}
		else
		{
			arr1[k] = *arr2;
			arr2++;
			k++;
		}
		i++;
	}
	for (i = 0; i <= num; i++)
	{
		*(arr + i) = arr1[i];
	}
}