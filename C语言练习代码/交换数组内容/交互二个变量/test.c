#define _CRT_SECURE_NO_WARNINGS 1

//����������������������ʱ������
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("�����������a��b \n");
	scanf("%d %d",&a,&b);
	printf("����ǰa= %d b=%d\n",a,b);
	b = a ^ b; 
	a = a ^ b;
	b = a ^ b;
	printf("����ǰa= %d b=%d \n", a, b);
	return 0;
}
