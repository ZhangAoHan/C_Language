//��д������һ��a�г��ֶ��ٸ�����9
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Num_9(int a);
int main()
{
	int i = 0;
	printf("���������֣�\n");
	scanf("%d",&i);
	printf("%d",Num_9(i));
	return 0;
}
int Num_9(int a)
{
	int i = 0;
	do
	{
		if (a / 10 == 0)
		{
			if (a == 9)
				i++;
			break;
		}
		else
		{
			if (a % 10 == 9)
				i++;
			a /= 10;
		}
	} while (1);
	return i;
}