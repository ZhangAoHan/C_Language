#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < ctype.h >
int main()
{
	//iscntrl:�ж��ַ��Ƿ�Ϊ�����ַ�  ͷ�ļ�< ctype.h >
	printf("d�ǿ����ַ���  %d", iscntrl('d'));
	printf("	�ǿ����ַ���  %d", iscntrl('	'));
	return 0;
}