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
		printf("�����������\n");
		scanf("%d %d", &x,&y);
		Exchange(x, y);
		printf("0:�˳�     1������\n");
		scanf("%d", &sit);
	} while (sit);
	return 0;
}
void Exchange(int x, int y) //����������������
{
	int* p_x = &x;
	int* p_y = &y;
	int c = 0;
	c = *p_x;  //ȡֵ
	*p_x = *p_y; //��ֵ
	*p_y = c;
	printf("�������Ϊ��\n");
	printf("%d %d\n", *p_x, *p_y);
}