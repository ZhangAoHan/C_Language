#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//��ӡ�����������Լ��
int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
	printf("�����������\n");
	scanf("%d %d", &a, &b);
	//������������ a<b
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	int i = 0;
	for (i = a; i >= 2; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("���Լ��Ϊ��%d", i);
			break;
		}
	}
	//���û���ҵ�����ӡ���
	if (i == 1)
	{
		printf("û�����Լ����������ֻ�ܱ�1����");
	}
	return 0;
}