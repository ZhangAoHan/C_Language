#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int my_strcmp(const char* buf1, const char* buf2);

int main()
{
	//����1 ����ַ���
	char a[] = "abcde";
	char b[] = "abcde";
	if (my_strcmp(a, b, 5) == 0)
	{
		printf("�����ַ������\n");
	}
	else
	{
		printf("�����ַ��������,���ؽ��Ϊ��%d\n", my_strcmp(a, b));
	}
	//����2 ������ַ���
	char c[] = "abcdefg";
	char d[] = "abcde!";
	if (my_strcmp(c, d) == 0)
	{
		printf("�����ַ������\n");
	}
	else
	{
		printf("�����ַ��������,���ؽ��Ϊ��%d\n", my_strcmp(c, d));
	}
	return 0;
}
int my_strcmp(const char* buf1, const char* buf2)
{
	while (*buf1++ == *buf2++)
	{
		if (*buf1 == '\0')  //�ַ������
			return 0;
	}
	return (int)(*buf1 - *buf2);
}