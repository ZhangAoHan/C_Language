#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
char* my_strcat(char* strdest, const char* strsource);
int main()
{
	char a[20] = "abcdefg..!";
	char b[] = "zah scabv";
	printf("ԭ�ַ���Ϊ��%s\n%s\nճ������Ϊ��8\nճ������ַ���Ϊ��%s", a, b, my_strcat(a, b));
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