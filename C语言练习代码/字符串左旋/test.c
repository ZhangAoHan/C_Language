#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
void ZX(const char* arr, const int k, int num);
int main()
{
	char arr[100] = {'0'};
	int num = 0;
	int k = 0;
	printf("请输入字符串，以换行结束\n");
	while (scanf("%c", &arr[num]) && arr[num] != '\n')
	{
		num++;
	}
	printf("请输入左旋数量（输入一个整数）\n");
	scanf("%d",&k);
	ZX(arr,k,num);
	return 0;
}
void ZX(const char *arr,const int k,int num)
{
	int i = 0;
	printf("原字符串为：");
	for (i = 0; i < num; i++)
	{
		printf("%c",*(arr+i));
	}
	printf("\n");
	printf("左旋后字符串为：");
	for (i = k; i < num; i++)
	{
		printf("%c", *(arr + i));
	}
	for (i = 0; i < k ; i++)
	{
		printf("%c", *(arr + i));
	}
	printf("\n");
}