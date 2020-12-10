#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < math.h >
#include < assert.h >
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
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
	int num = 1;//a的位数
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
		sum += pow(b % 10, 3);
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