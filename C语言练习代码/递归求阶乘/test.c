#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int JC(int num, int sit); //��׳�
int main()
{
	int num = 0;
	int result = 0;
	printf("������һ������\n");
	scanf("%d", &num);
	printf("�ݹ鷨��׳ˣ�:\n");
	result=JC(num, 0);
	printf("���Ϊ��%d", result);
	printf("\n�ǵݹ鷨��׳�\n");
	result=JC(num, 1);
	printf("���Ϊ��%d", result);
	return 0;
}

int JC(int num, int sit)
{
	if (sit)
	{
		if (num > 1)  //�ݹ�ģʽ
		{
			return num * JC(num - 1, 0);
		}
		else
			return 1;
	}
	else            //ѭ��ģʽ
	{
		int i = 0;
		int result = 1;
		for (i = num; i > 0; i--)
		{
			result = result * i;
		}
		return result;
	}

}