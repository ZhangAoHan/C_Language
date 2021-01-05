#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void* my_memset(void* dest, int c, uint count);
int main()
{
	char a[11]="1234567890";
	printf("未初始化之前的字符串:%s\n",a);
	printf("前5个字符初始化为字符*，后5个字符初始化为字符0\n");
	my_memset(a, '*', 5);
	printf("初始化之后的字符串:%s\n", a);
	my_memset(a + 5, 48, 5);
	printf("初始化之后的字符串:%s\n", a);
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