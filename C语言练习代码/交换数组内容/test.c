#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void sz_print(int* num, int len);  //打印数组
void sz_cxchange(int* num, int* num2, int len); //完成逆序
int main()
{
	int arr[10] = {1,2,3,5,7,8,9,6,4,10};
	int arr1[10] = {6,8,7,5,1,2,3,9,4,10};
	printf("数组1交换前：");
	sz_print(arr, 10);//打印数组
	printf("\n");
	printf("数组2交换前：");
	sz_print(arr1, 10);//打印数组
	printf("\n");
	sz_cxchange(arr,arr1,10);//完成交换
	printf("数组1交换后：");
	sz_print(arr, 10);//打印数组
	printf("\n");
	printf("数组2交换后：");
	sz_print(arr1, 10);//打印数组
	return 0;
}
void sz_print(int* num, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *num);
		num++;
	}
}
void sz_cxchange(int* num, int *num2, int len) //递归完成交换数组内容
{
	int d = 0; //中间变量
	if (len > 0)
	{
		d = *num;
		*num = *num2;
		*num2 = d;
		sz_cxchange(num + 1,num2 + 1, len - 1);
	}
}