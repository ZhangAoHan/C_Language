#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Years(int year); //�ж����꺯��
int main()
{
	int year = 0;
	int sit = 1;
	do
	{
		printf("���������\n");
		scanf("%d", &year);
		Years(year);
		printf("0:�˳�     1������\n");
		scanf("%d", &sit);
	} while (sit);

	return 0;
}

void Years(int year) //�ж����꺯��
{
	if (year % 4 == 0 && year % 100 != 0) //����
	{
		printf("%d ��������\n",year);
	}
	else
	{
		printf("%d �겻��������\n", year);
	}
}