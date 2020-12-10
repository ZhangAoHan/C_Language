#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < math.h >
#include < assert.h >
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
int Qh(int a, int b);
int Qh_sum(int a, int b);
int main()
{
	int a = 0;
	printf("请输入一个0-9的数\n");
	scanf("%d",&a);
	assert(a <= 9 || a >= 0);  //断言
	printf("S = %d + %d%d + %d%d%d + %d%d%d%d + %d%d%d%d%d = %d",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, Qh_sum(a , 5));
}
int Qh(int a, int b)
{
	if (b > 0)
	{
		return a * pow( 10, b) + Qh(a, b - 1);
	}
	else
		return a;
}
int Qh_sum(int a,int b)
{
	int i = 1;
	int sum = 0;
	for (i = 1; i <= b; i++)
	{
		sum += Qh(a,i - 1);
	}
	return sum;
}