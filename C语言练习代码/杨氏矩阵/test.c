#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int Find_num(int* a, int num1, int num2, int ob); //aΪ�����ַ��num1Ϊ����   num2Ϊ����  obΪĿ��Ԫ��
int main()
{
	int a = 0;
	int b[4][4] = {  //����һ�����Ͼ���
	1,2,3,4,
	2,4,6,8,
	3,5,7,9,
	4,6,9,10
	};
	printf("������Ҫ���ҵ�����\n");
	scanf("%d",&a);
	if (Find_num(b, 4, 4, a))
	{
		printf("�ҵ���");
	}
	else
	{
		printf("û�ҵ�");
	}
}
//�Ӿ�������Ͻǿ�ʼ����num�����a[i][j]<num�������²��ң����a[i][j]>num�����������
//��a[i][j]����num������i��j������һ����������Χ����������ҡ�
//ʱ�临�Ӷ�Ϊm+n
int Find_num(int *a,int num1,int num2,int ob) //aΪ�����ַ��num1Ϊ����   num2Ϊ����  obΪĿ��Ԫ��
{
	int hs = 0;
	int ls = num2;
	do
	{
		if (*(a + hs*(num2) + ls -1) > ob)
		{
			ls--;
		}
		else if (*(a + hs * (num2)+ls - 1) < ob)
		{
			hs++;
		}
		else
		{
			return 1; //�з���1
		}
		if (ls < 0 || hs < 0)
		{
			return 0;//û�з���0  
		}
	} while (1);
	
}