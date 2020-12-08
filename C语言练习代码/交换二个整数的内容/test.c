#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Exchange(int* x,int* y);
int main()
{
	int x = 0;
	int y = 0;
	int sit = 1;
	do
	{
		printf("请输入二个数\n");
		scanf("%d %d", &x,&y);
		printf("交换前为：\n");
		printf("%d %d\n", x, y);
		Exchange(&x, &y);
		printf("交换后为：\n");
		printf("%d %d\n", x, y);
		printf("0:退出     1：继续\n");
		scanf("%d", &sit);
	} while (sit);
	return 0;
}
void Exchange(int* x, int* y) //交换二个数的内容
{
	int c = 0;
	c = *x;  //取值
	*x = *y; //赋值
	*y = c;
}