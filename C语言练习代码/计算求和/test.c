#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < math.h >
#include < assert.h >
//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
int Qh(int a, int b);
int Qh_sum(int a, int b);
int main()
{
	int a = 0;
	printf("������һ��0-9����\n");
	scanf("%d",&a);
	assert(a <= 9 || a >= 0);  //����
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