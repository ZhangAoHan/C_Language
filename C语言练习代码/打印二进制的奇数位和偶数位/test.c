#define _CRT_SECURE_NO_WARNINGS 1

//��ӡ���������Ƶ�����λ��ż��λ
#include <stdio.h>
void Printf_JO(int a);
int main()
{
	int a = 0;
	printf("������һ����\n");
	scanf("%d",&a);
	Printf_JO(a);
	return 0;
}
void Printf_JO(int a)
{
	int i = 0;
	int b = a;
	printf("�Ӹ�λ����λȡ\n");
	printf("����λΪ�� \n");
	for (i = 0; i < 16; i++)
	{
		printf("%d ",(b & 0x80000000) / 0x80000000);
		b = b << 2;
	}
	b = a;
	printf("\nż��λΪ�� \n");
	for (i = 0; i < 16; i++)
	{
		printf("%d ", (b & 0x40000000) / 0x40000000);
		b = b << 2;
	}
}