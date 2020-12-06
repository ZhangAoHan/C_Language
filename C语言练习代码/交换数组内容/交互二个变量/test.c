#define _CRT_SECURE_NO_WARNINGS 1

//交换两个变量（不创建临时变量）
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("请输入二个数a和b \n");
	scanf("%d %d",&a,&b);
	printf("交换前a= %d b=%d\n",a,b);
	b = a ^ b; 
	a = a ^ b;
	b = a ^ b;
	printf("交换前a= %d b=%d \n", a, b);
	return 0;
}
