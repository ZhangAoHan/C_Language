#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
int my_memcmp(const void* buf1, const void* buf2, uint count);

int main()
{
	//����1 ����ַ���
	char a[] = "abcde";
	char b[] = "abcde";
	if (my_memcmp(a, b, 5) == 0)
	{
		printf("�����ַ������\n");
	}
	else
	{
		printf("�����ַ��������,���ؽ��Ϊ��%d\n", my_memcmp(a, b, 5));
	}
	//����2 ������ַ���
	char c[] = "abcdefg";
	char d[] = "abcde!";
	if (my_memcmp(c, d, 6) == 0)
	{
		printf("�����ַ������\n");
	}
	else
	{
		printf("�����ַ��������,���ؽ��Ϊ��%d\n", my_memcmp(c, d, 6));
	}
	return 0;
}
int my_memcmp(const void* buf1, const void* buf2, uint count)
{
	while (count--)
	{
		if (*(char*)buf1 == *(char*)buf2)
		{
			buf1=(char*)buf1 + 1;
			buf2 = (char*)buf2 + 1;
		}
		else
		{
			return (int)(*(char*)buf1 - *(char*)buf2);
		}
	}
	return 0; 
}