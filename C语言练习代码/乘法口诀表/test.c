#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Mul(int num); //�˷��ھ�����
int main()
{
	int num = 0;
	int sit = 1;
	do
	{
		printf("�������Сn: n*n�ĳ˷���\n");
		scanf("%d", &num);
		Mul(num);
		printf("0:�˳�     1������\n");
		scanf("%d", &sit);
	} while (sit);

	return 0;
}
void Mul(int num)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 1; i <= num; i++)
	{
		for(j = 1; j <= i; j++)
		{
			sum = i * j;
			printf("  %d X %d = %d  ",i,j,sum);
		}
		printf("\n");
	}
}