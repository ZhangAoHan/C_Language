
#include <stdio.h>
int Find_sushu(int min, int max); //����Ѱ�������ķ�Χ
int main()
{
	int error = 0;
	error = Find_sushu(100, 200);
	if (error == 1)
	{
		printf("���������Ǵ���1����Ȼ��");
	}
	return 0;
}

int Find_sushu(int min, int max) //����Ѱ�������ķ�Χ
{
	int i = 0;
	int j = 0;
	if (min <= 1) //�����������1
	{
		return 1;
	}
	for (i = min; i <= max; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)//����
			{
				break;
			}
		}
		if (j == i) 
		{
			printf("%d\n",i);
		}
	}
	return 0;
}