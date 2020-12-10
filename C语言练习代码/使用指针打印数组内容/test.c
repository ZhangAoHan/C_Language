#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//使用指针打印数组内容
void sz_printf(int* arr, int num);
int main()
{
	int num = 0;  //输入字符串的数量
	int arr[200] = {0};
	printf("请输入一维数组\n");
	printf("最少输入一个数，最多不超过200个数\n");
	while (scanf("%d",&arr[num]) && getchar() != '\n')  //获取键入的int型数组
	{
		num++;
	}

	sz_printf(arr,num + 1);
}

void sz_printf(int *arr,int num)
{
	int i = 0;
	while ( num --)
	{
		printf("%d ",*(arr ++));
	}
}