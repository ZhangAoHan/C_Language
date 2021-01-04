#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
char* my_strncat(char* strdest, const char* strsource, uint count);
int main()
{
	char a[20] = "abcdefg..!";
	char b[] = "zah scabv";
	printf("原字符串为：%s\n%s\n粘贴长度为：8\n粘贴后的字符串为：%s",a,b, my_strncat(a,b,8));
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
		else  //count>strsource的长度   直接终止
		{
			break;
		}
	}
	return strdest;
}