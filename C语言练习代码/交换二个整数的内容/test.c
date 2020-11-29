#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Exchange(int x,int y);
int main()
{
	int x = 0;
	int y = 0;
	int sit = 1;
	do
	{
		printf("请输入二个数\n");
		scanf("%d %d", &x,&y);
		Exchange(x, y);
		printf("0:退出     1：继续\n");
		scanf("%d", &sit);
	} while (sit);
	return 0;
}
void Exchange(int x, int y) //交换二个数的内容
{
	int* p_x = &x;
	int* p_y = &y;
	int c = 0;
	c = *p_x;  //取值
	*p_x = *p_y; //赋值
	*p_y = c;
	printf("交换结果为：\n");
	printf("%d %d\n", *p_x, *p_y);
}