#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
int FB(int num, int sit);  //ʵ�����n��쳲�������
int main()
{
	int n = 0;
	int sum = 0;
	printf("�����룺n\n");
	scanf("%d", &n);
	sum = FB(n, 1);
	printf("�ݹ���Ϊ�� %d \n", sum);
	sum = FB(n, 0);
	printf("�ǵݹ���Ϊ�� %d \n", sum);
	return 0;
}
int FB(int num, int sit)
{
	if (sit)
	{
		if (num > 2)
		{
			return FB(num-1,1)+FB(num-2,1);
		}
		else
		{
			return 1;
		}
	}
	else
	{
		int i = 2;
		int a = 1;
		int b = 1;
		int c = 1;
		if (num > 2)
		{
			while ( i < num)
			{
				a = b;
				b = c;
				c = a + b;
				i++;
			}
			return c;
		}
		else
		{
			return 1;
		}
	}
}