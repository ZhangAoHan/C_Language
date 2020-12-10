#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >

int Qs(int a);  //a:钱数
int main()
{
	printf("%d元钱可以喝%d瓶汽水",20,Qs(20));
	return 0;
}
int Qs(int a)  //a:钱数
{
	int b = 0;//瓶子数量
	int num = 0; //可以喝的汽水数量
	while (a > 0)
	{
		num++;
		a--;
		b++;
		if (b == 2) //2个瓶子 相当于1元钱
		{
			a++;
			b = 0;
		}
	}
	return num;
}