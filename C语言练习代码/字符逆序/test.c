#define _CRT_SECURE_NO_WARNINGS 1
//将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。
#include <stdio.h>
void DX_str(char* arr, int num);
int main()
{
	char arr[100] = { '0' };
	int num = 0;
	while (scanf("%c",&arr[num]) && arr[num] != '\n') ////获取键入的char型数组
	{
		num++;
	}
	DX_str(arr,num);
}
void DX_str(char *arr,int num)
{
	while (num --)
	{
		printf("%c",*(arr + num));
	}
}