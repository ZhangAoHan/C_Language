#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ַ������򣨵ݹ�ʵ�֣�
void Str_reverse(char* str, int sit); 
int main()
{
	char str[100];   //�����ַ������ȱ���С��100
	scanf("%s", str); //ȡ���ַ����׵�ַ
	printf("�ݹ鷴����Ϊ�� ");
	Str_reverse(str, 1);
	printf("\nѭ��������Ϊ�� ");
	Str_reverse(str, 0);

	return 0;
}


void Str_reverse(char* strs, int sit)
{
	if (sit)       //�ݹ�ʵ��
	{
		if (*strs != '\0')
		{
			Str_reverse(strs+1,1);
			printf("%c ", *strs);
		}
		//else  //��ӡ  '\0'���ո�Ĭ�ϲ���ӡ��
		//{
		//	printf("%c ", *strs);
		//}
	}
	else  //ѭ��ʵ��
	{
		int i = 0;
		char* p = strs;
		while (*p != '\0') //ȡ����\0���ĵ�ַ
		{
			p++;
			i++;
		}
		while (i > 0) //����ӡ�ո�
		{
			printf("%c ",*(p-1));
			p--;
			i--;
		}
		//while (i >= 0) //��ӡ�ո�
		//{
		//	printf("%c ", *p);
		//	p--;
		//	i--;
		//}
	}
}

