#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
char* my_strcat(char* strdest, const char* strsource);
int main()
{
	char a[20] = "abcdefg..!";
	char b[] = "zah scabv";
	printf("原字符串为：%s\n%s\n粘贴长度为：8\n粘贴后的字符串为：%s", a, b, my_strcat(a, b));
	return 0;
}

char* my_strcat(char* strdest, const char* strsource)
{
	char* s = strdest;
	while (*s != '\0')
	{
		s++;
	}
	while (*strsource != '\0')
	 {
		*s = *strsource;
		s++;
		strsource++;
	 }
	return strdest;
}