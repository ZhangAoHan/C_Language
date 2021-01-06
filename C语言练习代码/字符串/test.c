#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < ctype.h >
int main()
{
	//iscntrl:判断字符是否为控制字符  头文件< ctype.h >
	printf("d是控制字符吗？  %d", iscntrl('d'));
	printf("	是控制字符吗？  %d", iscntrl('	'));
	return 0;
}