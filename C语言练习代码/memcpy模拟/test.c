#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void* my_memcpy(void* dest, const void* src, uint count);
int main()
{	
	//�����ַ���
	char a[] = "12345678901234567890";
	char b[] = "abcdefghijklmnopqrst";
	char c[] = "abcdefghij1234567890";
	printf("�������1\n����ǰ��%s\n", a);
	my_memcpy(a + 9, a + 4, 5);  //dest>=src+n
	printf("���ĺ�%s\n", a);
	printf("�������2\n����ǰ��%s\n", b);
	my_memcpy(b, b + 5, 5); //dest<=src
	printf("���ĺ�%s\n", b);
	printf("�������3\n����ǰ��%s\n", c);
	my_memcpy(c + 4, c, 10);  //src+n>dest>src
	printf("���ĺ�%s\n", c);
	return 0;
}

void* my_memcpy(void* dest, const void* src, uint count)
{
	char* des = (char*)dest;
	if (src >= dest || (char*)src + count <= (char*)dest)
	{
		while (count--)
		{
			*(char*)des = *(char*)src;
			des = (char*)des + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		printf("Դ�ռ��Ŀ��ռ����ص������ƻ������ʹ��memmove����,������������и��ơ�\n");
	}
	return dest;
}
