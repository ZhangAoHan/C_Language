#define _CRT_SECURE_NO_WARNINGS 1

//ͳ�ƶ�������1�ĸ���
#include <stdio.h>

int main()
{
	int a = 0;
	printf("������һ����\n");
	scanf("%d",&a);
	printf("%d �Ķ�������1�ĸ���Ϊ: %d", a, One_Num(a));
	return 0;
}
int One_Num(int a)
{
	int i = 0;
	int num = 0;
	for (i = 0; i < 32; i++)
	{
		if ((a & 1) == 1)
		{
			num++;
		}
		a = a >> 1;
	}
	return num;
}