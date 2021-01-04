#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
char* my_strncpy(char* str1, const char* str2, uint num);
int main()
{
	char a[20]= "abcdefghiss";
	printf("原字符串为：%s\n要粘贴的字符串为：123\n \
粘贴长度为4,粘贴起始位置为f\n粘贴完成后的字符串为：%s",a, my_strncpy(a+5,"123",4)-5);
	return 0;
}

char* my_strncpy(char* str1, const char* str2, uint num)
{
	char* s = str1;
	while (num--)
	{
		if (*str2 != '\0')
		{
			*s = *str2;
			s++;
			str2++;
		}
		else //num>str2的长度，直接终止
		{
			break;
		}
	}
	return str1;
}
