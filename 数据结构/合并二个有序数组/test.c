#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void my_sort(int* arr, int num);
int main()
{
	int A[6] = {1,2,0,0,0,0};
	int B[4] = {1,2,3,4};
	merge(A,6,2,B,4,4);
	for (int i = 0; i < 6; i++)
	{
		printf("%d",A[i]);
	}
	return 0;
}
//方法
//先合并数组
//再排序（冒泡排序）
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//合并数组
	int i = 0;
	for (i = 0; i < n; i++)
	{
		nums1[m + i] = nums2[i];
	}
	my_sort(nums1, m + n);
}
void my_sort(int *arr,int num) //冒泡排序
{
	int i = 0;
	int j = 0;
	int data = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				data = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = data;
			}
		}
	}
}