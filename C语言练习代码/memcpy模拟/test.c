#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void* my_memcpy(void* dest, const void* src, uint count);
int main()
{	
	//测试字符串
	char a[] = "12345678901234567890";
	char b[] = "abcdefghijklmnopqrst";
	char c[] = "abcdefghij1234567890";
	printf("测试情况1\n更改前：%s\n", a);
	my_memcpy(a + 9, a + 4, 5);  //dest>=src+n
	printf("更改后：%s\n", a);
	printf("测试情况2\n更改前：%s\n", b);
	my_memcpy(b, b + 5, 5); //dest<=src
	printf("更改后：%s\n", b);
	printf("测试情况3\n更改前：%s\n", c);
	my_memcpy(c + 4, c, 10);  //src+n>dest>src
	printf("更改后：%s\n", c);
	return 0;
}

void* my_memcpy(void* dest, const void* src, uint count)
{
	char* des = (char*)dest;
	if (src >= dest || (char*)src + count <= (char*)dest)
	{
		while (count--)
		{
			*(char*)des = *(char*)src;
			des = (char*)des + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		printf("源空间和目标空间有重叠，复制会出错。请使用memmove函数,本函数不会进行复制。\n");
	}
	return dest;
}
