#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void dsg(int* sz, int num, int* a, int* b);//szΪ���� abΪ��ֻ����
int main()
{
	int a = 0;
	int b = 0;
	int sz[12] = { 1,2,3,4,5,6,7,5,4,3,2,1 };
	dsg(sz, 12, &a, &b);
	printf("��ֻ�����ǣ�%d %d", a, b);
	return 0;
}
//A^A=0
// 0^A=A  
// 1^2^3=1^3^2 ���㽻���ɺͽ����
//A^B
void dsg(int* sz, int num,int* a, int* b)//szΪ���� abΪ��ֻ����
{
	int i = 0;
	int sum = 0;
	int* s = sz;
	*a = 0;
	*b = 0;
	//�����������������ֵ
	for (i = 0; i < num; i++)
	{
		sum ^= *s;
		s++;
	}
	int sit = 0;//����������һ����ͬ��λ
	for (i = 0; i < 32; i++)
	{
		if (sum & 1 << i)
		{
			sit = i;
			break;
		}
	}
	for (i = 0; i < num; i++)
	{
		if (*sz & (1 << sit))
		{
			*a ^= *sz;
		}
		else
		{
			*b ^= *sz;
		}
		sz++;
	}
}
