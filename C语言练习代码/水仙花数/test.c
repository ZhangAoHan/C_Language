#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < math.h >
#include < assert.h >
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
int SXH_num(int a);
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		if (SXH_num(i)) printf("%d ",i);
	}
	return 0;
}

int SXH_num(int a)
{
	int num = 1;//a��λ��
	int i = 0;
	int b = a;
	int sum = 0;
	while (b / 10 != 0)
	{
		num ++;
		b /= 10;
	}
	b = a;
	for (i = 1; i <= num; i++)
	{
		sum += pow(b % 10, num);
		b = b / 10;
	}
	if (sum == a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}