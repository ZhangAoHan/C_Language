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
////��ͷѰ�Ҳ���Ҫɾ����Ԫ��  ��˳���ͷ��ʼ�ż���
//int removeElement(int* nums, int numsSize, int val) {
//	int i = 0;
//	int j = 0; //�������ݸ���
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != val)  //����Ҫɾ����Ԫ��
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
//���a[1] * 2 > 10 a[2] = a[1] * 2 / 10; a[1]=a[1]*2%10
//���a[0]*2>10 a[1]=a[1]+a[0]*2/10 a[0]=a[0]*2%10
//�ݹ�д�� (��С�����)
void Print_Factorial(const int N)
{
	int Sum[3000] = {1}; //��ʼ���ٹ���Ŀռ�
	int nums = 1;
	if (N >= 0)
	{
		Returnsum(Sum, &nums, 1, N);
		//���Ҫ�������
		for (int i = 0; i < nums; i++)
		{
			printf("%d ", Sum[nums - 1 - i]);
		}
		printf("\n%d", nums);
	}
	else
		printf("Invaild input");
}
void Returnsum(int* num, int* nums, int n, int nu)  //nums: ���λ��=1 num���������   n:�ݹ����=0 nu�ݹ�Ĵ���
{
	if (n <= nu)
	{
		Val(num, nums, *nums, n++, 0);
		Returnsum(num, nums, n, nu);
	}
}


void Val(int* num, int *numSize,int n,int nums, int sit)//�ݹ�����
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
		while (sit) //˵���н�λ
		{
			num[*numSize] = sit % 10;
			*numSize = *numSize + 1;
			sit = sit / 10;
		}
	}
}
