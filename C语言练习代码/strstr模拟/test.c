#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
//char* my_strstr1(const char* string, const char* strcharset);
//int main()
//{
//	char a[] = "abcdefa";
//	char b[] = "def";
//	char c[] = "";
//	char d[] = "acef";
//	printf("����1\n");
//	if (my_strstr1(a, b) == NULL)
//	{
//		printf("bΪ���ַ���\n");
//	}
//	else
//	{
//		printf("Ŀ���ַ����������ַ�������ʼλ��Ϊ��%p,\n��Ŀ���ַ����еģ�%c����ʼ\n", my_strstr1(a, b), *my_strstr1(a, b));
//	}
//	printf("����2\n");
//	if (my_strstr1(a, c) == NULL)
//	{
//		printf("bΪ���ַ���\n");
//	}
//	else
//	{
//		printf("Ŀ���ַ����������ַ�������ʼλ��Ϊ��%p,\n��Ŀ���ַ����еģ�%c����ʼ\n", my_strstr1(a, c), *my_strstr1(a, c));
//	}
//	printf("����3\n");
//	if (my_strstr1(a, d) == NULL)
//	{
//		printf("bΪ���ַ���\n");
//	}
//	else
//	{
//		printf("Ŀ���ַ����������ַ�������ʼλ��Ϊ��%p,\n��Ŀ���ַ����еģ�%c����ʼ\n", my_strstr1(a, d), *my_strstr1(a, d));
//	}
//	return 0;
//}
//
////������ⷨ
//char* my_strstr1(const char* string, const char* strcharset)
//{
//	int i = 0;//Ŀ���ַ����±�
//	int j = 0;//���ַ����±�
//	if (strcharset == NULL)
//	{
//		return string;
//	}
//	else
//	{
//		while (1)
//		{
//			if (*(string + i) == '\0') //Ŀ���ַ�������β�˻�û������˵��Ŀ���ַ��������Ӵ���
//			{
//				return NULL;
//			}
//			else
//			{
//				if (*(strcharset + j) == '\0') //b��ȫ���ж���ϣ�Ŀ���ַ����а����Ӵ�
//				{
//					return string + i;
//				}
//				else
//				{
//					if (*(string + i + j) == *(strcharset + j)) //ƥ�䵽�ַ�
//					{
//						j++;
//					}
//					else
//					{
//						j = 0;
//						i++;
//					}
//				}
//			}
//		}
//	}
//}

//KMP��
int main()
{

	return 0;
}

char* my_strstr_KMP(const char* string, const char* strcharset)
{
	
}