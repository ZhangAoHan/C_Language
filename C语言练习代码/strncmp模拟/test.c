#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
int my_strncmp(const char* buf1, const char* buf2, uint count);

int main()
{
	//����1 ����ַ���
	char a[] = "abcde";
	char b[] = "abcde";
	if (my_strncmp(a, b, 5) == 0)
	{
		printf("�����ַ������\n");
	}
	else
	{
		printf("�����ַ��������,���ؽ��Ϊ��%d\n", my_strncmp(a, b, 5));
	}
	//����2 ������ַ���
	char c[] = "abcdefg";
	char d[] = "abcde!";
	if (my_strncmp(c, d, 6) == 0)
	{
		printf("�����ַ������\n");
	}
	else
	{
		printf("�����ַ��������,���ؽ��Ϊ��%d\n", my_strncmp(c, d, 6));
	}
	return 0;
}
int my_strncmp(const char* buf1, const char* buf2, uint count)
{
	while (count--)
	{
		if (*buf1 == *buf2)
		{
			buf1 ++;
			buf2 ++;
		}
		else
		{
			return (int)(*buf1 - *buf2);
		}
	}
	return 0;
}