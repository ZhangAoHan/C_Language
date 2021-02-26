#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int removeElement(int* nums, int numsSize, int val);
//int main()
//{
//	int A [13]= {1,2,3,4,5,2,1,1,3,5,6,1,5};
//	int j = removeElement(A, 13, 1);
//	for (int i = 0; i < j; i++)
//	{
//		printf("%d ",A[i]);
//	}
//	return 0;
//}
////重头寻找不是要删除的元素  按顺序从头开始放即可
//int removeElement(int* nums, int numsSize, int val) {
//	int i = 0;
//	int j = 0; //最终数据个数
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != val)  //不是要删除的元素
//		{
//			nums[j] = nums[i];
//			j++;
//		}
//	}
//	return j;
//}
void Print_Factorial(const int N);
void Returnsum(int* num, int* nums, int n, int nu);
void Val(int* num, int* numSize, int n, int nums, int sit);
#define Max 10
int main()
{
	Print_Factorial(20);
	return 0;
}
//4!      10  10! 
//4 * 3 > 10
//a[0] = 4 * 3 % 10 = 2
//a[1] = 4 * 3 / 10 = 1;
//4 * 3 * 2 = a[1] * 2 a[0] * 2
//如果a[1] * 2 > 10 a[2] = a[1] * 2 / 10; a[1]=a[1]*2%10
//如果a[0]*2>10 a[1]=a[1]+a[0]*2/10 a[0]=a[0]*2%10
//递归写法 (从小往大乘)
void Print_Factorial(const int N)
{
	int Sum[3000] = {1}; //初始开辟过大的空间
	int nums = 1;
	if (N >= 0)
	{
		Returnsum(Sum, &nums, 1, N);
		//最后还要反向输出
		for (int i = 0; i < nums; i++)
		{
			printf("%d ", Sum[nums - 1 - i]);
		}
		printf("\n%d", nums);
	}
	else
		printf("Invaild input");
}
void Returnsum(int* num, int* nums, int n, int nu)  //nums: 结果位数=1 num：结果数组   n:递归的数=0 nu递归的次数
{
	if (n <= nu)
	{
		Val(num, nums, *nums, n++, 0);
		Returnsum(num, nums, n, nu);
	}
}


void Val(int* num, int *numSize,int n,int nums, int sit)//递归求结果
{
	if (n > 0)
	{
		if (num[*numSize - n] * nums + sit > Max)
		{
			int data = 0;
			int ssit = 0;
			data = (num[*numSize - n] * nums + sit) % 10;
			ssit = (num[*numSize - n] * nums + sit) / 10;
			num[*numSize - n] = data;
			sit = ssit;
		}
		else
		{
			num[*numSize - n] = (num[*numSize - n] * nums + sit) % 10;
			sit = 0;
		}
		Val(num, numSize, n - 1, nums, sit);
	}
	else
	{
		while (sit) //说明有进位
		{
			num[*numSize] = sit % 10;
			*numSize = *numSize + 1;
			sit = sit / 10;
		}
	}
}
