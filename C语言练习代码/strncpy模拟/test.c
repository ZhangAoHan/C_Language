#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
char* my_strncpy(char* str1, const char* str2, uint num);
int main()
{
	char a[20]= "abcdefghiss";
	printf("ԭ�ַ���Ϊ��%s\nҪճ�����ַ���Ϊ��123\n \
ճ������Ϊ4,ճ����ʼλ��Ϊf\nճ����ɺ���ַ���Ϊ��%s",a, my_strncpy(a+5,"123",4)-5);
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
		else //num>str2�ĳ��ȣ�ֱ����ֹ
		{
			break;
		}
	}
	return str1;
}
