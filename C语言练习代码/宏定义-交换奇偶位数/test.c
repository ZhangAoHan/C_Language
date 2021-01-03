#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//交换一个整数的奇数位和偶数位
//a &0x aa aa aa aa 取出偶数位   
//a &0x 55 55 55 55 取出奇数位
// 偶数位右移+奇数位左移
#define JH(a) ((a & 0xaaaaaaaa) >> 1) + ((a & 0x55555555) << 1)
int main()
{
	int a = 1;  //0x00 00 00 01 交换后应为0x00 00 00 02
	printf("%d\n", JH(a));
	 a = 2;//0x00 00 00 02 交换后应为0x00 00 00 01
	printf("%d\n", JH(a));
	 a = 3; //0x00 00 00 03=0000 0011 交换后应为0x00 00 00 03=0000 0011
	printf("%d\n", JH(a));
	 a = 4;//0x00 00 00 04=0000 0100 交换后应为0x00 00 00 08=0000 1000
	printf("%d\n", JH(a));
	return 0;
}