#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
char* my_strncat(char* strdest, const char* strsource, uint count);
int main()
{
	char a[20] = "abcdefg..!";
	char b[] = "zah scabv";
	printf("ԭ�ַ���Ϊ��%s\n%s\nճ������Ϊ��8\nճ������ַ���Ϊ��%s",a,b, my_strncat(a,b,8));
	return 0;
}

char* my_strncat(char * strdest, const char *strsource, uint count)
{
	char * s= strdest;
	while (*s != '\0')
	{
		s++;
	}
	while (count--)
	{
		if (*strsource != '\0')
		{
			*s = *strsource;
			s++;
			strsource++;
		}
		else  //count>strsource�ĳ���   ֱ����ֹ
		{
			break;
		}
	}
	return strdest;
}