#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Print(int num, int sit); //��ӡÿһλ
int main()
{
	int num = 0;
	printf("������һ������\n");
	scanf("%d",&num);
	printf("�����ӡ:\n");
	Print(num,1);
	printf("\n�����ӡ:\n");
	Print(num, 0);
	return 0;
}

void Print(int num,int sit)
{
	if (sit)
	{
		//�����ӡ  
		if (num /10 > 0)
		{
			Print(num/10,sit);
			printf(" %d ,", num % 10);
		}
		else
		{
			printf(" %d ,", num % 10);
		}
	}
	else
	{
		//�����ӡ
		if (num / 10 > 0)
		{
			printf(" %d ,", num % 10);
			Print(num / 10,sit);
		}
		else
		{
			printf(" %d ,", num % 10);
		}
	}
}