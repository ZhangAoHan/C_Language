#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ݹ�ʵ��n��k�η�
int N_k(int num, int k, int sit);  //ʵ��n��k�η�
int main()
{
	int n = 0;
	int k = 0;
	int sum = 0;
	printf("�����룺n�� ָ����k\n");
	scanf("%d %d",&n,&k);
	sum = N_k(n,k,1);
	printf("�ݹ���Ϊ�� %d \n",sum);
	sum = N_k(n, k, 0);
	printf("�ǵݹ���Ϊ�� %d \n", sum);
	return 0;
}
int N_k(int num, int k, int sit)
{
	if (sit)
	{
		if (k > 0)
		{
			return num*N_k(num,k-1,1);
		}
		else
		{
			return 1;
		}
	}
	else
	{
		int sum = 1;
		while(k > 0)
		{
			sum = sum * num;
			k--;
		}
		return sum;
	}
}