#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//����һ������������λ��ż��λ
//a &0x aa aa aa aa ȡ��ż��λ   
//a &0x 55 55 55 55 ȡ������λ
// ż��λ����+����λ����
#define JH(a) ((a & 0xaaaaaaaa) >> 1) + ((a & 0x55555555) << 1)
int main()
{
	int a = 1;  //0x00 00 00 01 ������ӦΪ0x00 00 00 02
	printf("%d\n", JH(a));
	 a = 2;//0x00 00 00 02 ������ӦΪ0x00 00 00 01
	printf("%d\n", JH(a));
	 a = 3; //0x00 00 00 03=0000 0011 ������ӦΪ0x00 00 00 03=0000 0011
	printf("%d\n", JH(a));
	 a = 4;//0x00 00 00 04=0000 0100 ������ӦΪ0x00 00 00 08=0000 1000
	printf("%d\n", JH(a));
	return 0;
}