#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void* my_memmove(void* dst, const void* src, uint count);
int main()
{
	//�����ַ���
	char a[] = "12345678901234567890";
	char b[] = "abcdefghijklmnopqrst";
	char c[] = "abcdefghij1234567890";
	printf("�������1\n����ǰ��%s\n", a);
	my_memmove(a + 9,a + 4,5);  //dest>=src+n
	printf("���ĺ�%s\n",a);
	printf("�������2\n����ǰ��%s\n", b);
	my_memmove(b, b+5, 5); //dest<=src
	printf("���ĺ�%s\n", b);
	printf("�������3\n����ǰ��%s\n", c);
	my_memmove(c + 4, c, 10);  //src+n>dest>src
	printf("���ĺ�%s\n", c);
	return 0;
}
//��src��ǰcount���ֽڵ����ݸ��Ƶ�dst��
void* my_memmove(void* dst, const void* src, uint count)
{
	void* ret = dst;
	if (dst <= src || (char*)dst >= ((char*)src + count)) {
		//���1�����2
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else {
		//�ڴ�ռ��ص�
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return(ret);
}
