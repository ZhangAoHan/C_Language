#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void* my_memset(void* dest, int c, uint count);
int main()
{
	char a[11]="1234567890";
	printf("δ��ʼ��֮ǰ���ַ���:%s\n",a);
	printf("ǰ5���ַ���ʼ��Ϊ�ַ�*����5���ַ���ʼ��Ϊ�ַ�0\n");
	my_memset(a, '*', 5);
	printf("��ʼ��֮����ַ���:%s\n", a);
	my_memset(a + 5, 48, 5);
	printf("��ʼ��֮����ַ���:%s\n", a);
	return 0;
}
void* my_memset(void* dest, int c, uint count)
{
	char* des = dest;
	while (count --)
	{
		*des = c;
		des++;
	}
	return dest;
}