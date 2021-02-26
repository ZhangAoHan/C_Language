#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize);
int main()
{
	int A[10] = {1,1,2,2,3,4,5};
	int j = removeDuplicates(A,7);
	for (int i = 0; i < j; i++)
	{
		printf("%d",A[i]);
	}
	printf("\n%d",j);
	return 0;
}

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize < 2) //一个元素不用排序
	{
		return numsSize;
	}
	int i = 0;
	int j = 0;//不重复数据长度
	for (i = 0; i < numsSize - 1; i++)
	{
		if (nums[i + 1] != nums[i])
		{
			j++;
			nums[j] = nums[i + 1];
		}
	}
	return j + 1;
}


