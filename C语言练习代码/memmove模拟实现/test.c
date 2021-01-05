#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void* my_memmove(void* dst, const void* src, uint count);
int main()
{
	//测试字符串
	char a[] = "12345678901234567890";
	char b[] = "abcdefghijklmnopqrst";
	char c[] = "abcdefghij1234567890";
	printf("测试情况1\n更改前：%s\n", a);
	my_memmove(a + 9,a + 4,5);  //dest>=src+n
	printf("更改后：%s\n",a);
	printf("测试情况2\n更改前：%s\n", b);
	my_memmove(b, b+5, 5); //dest<=src
	printf("更改后：%s\n", b);
	printf("测试情况3\n更改前：%s\n", c);
	my_memmove(c + 4, c, 10);  //src+n>dest>src
	printf("更改后：%s\n", c);
	return 0;
}
//将src的前count个字节的内容复制到dst中
void* my_memmove(void* dst, const void* src, uint count)
{
	void* ret = dst;
	if (dst <= src || (char*)dst >= ((char*)src + count)) {
		//情况1和情况2
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else {
		//内存空间重叠
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return(ret);
}
