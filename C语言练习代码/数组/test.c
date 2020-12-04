#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void sz_init(int* num, int len);  //数组初始化
void sz_print(int* num, int len);  //打印数组
void sz_reverse(int* num, int len); //完成逆序
int main()
{
	int arr[10] = {1,2,3,5,7,8,9,6,4,10};
	sz_reverse(arr,10);//完成逆序
	printf("数组逆序打印");
	sz_print(arr, 10);//打印数组
	printf("\n");
	printf("数组初始化打印");
	sz_init(arr,10);//数组初始化
	sz_print(arr,10);//打印数组
	return 0;
}

void sz_init(int *num, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		*num = 0;
		num++;
	}
}

void sz_print(int *num, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ",*num);
		num++;
	}
}
void sz_reverse(int* num, int len) //递归完成逆序
{
	int d = 0; //中间变量
	if (len / 2 > 0)
	{
		d = *num;
		*num = *(num+len-1);
		*(num + len-1) = d;
		sz_reverse(num+1,len-2);
	}
}