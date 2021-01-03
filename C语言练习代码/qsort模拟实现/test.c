#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void my_test(void);
void my_qsort(void* const base, uint num, uint width, int(*comper)(const void* s1, const void* s2));
int my_strcmp1(const void* s1, const void* s2);  //�Ƚ����������С //�ȽϽṹ��-�����С
int my_strcmp2(const void* s1, const void* s2);  //�Ƚ��ַ������С //�ȽϽṹ��-���ִ�С
void my_test(void);
int main()
{
	my_test();
	return 0;
}
//baseΪҪ�����ַ�����ʼ��ַ
//numΪҪ�����ַ���Ԫ�ظ���
//widthΪҪ�����ַ�Ԫ�صĴ�С����λB��
//int(*comper)(const void* s1, const void* s2)�ȽϺ���
void my_qsort(void *const base, uint num, uint width, int(*comper)(const void *s1,const void *s2))
{
	for (int i = 0; i < num - 1; i++)  //ð�������㷨
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (comper((char*)base + j * width, (char*)base + (j + 1) * width) == 1) //=1��ʾ����
			{
				char* p = (char*)base + j * width;
				//���н�������Ӧ��ַ�����ݽ��н�����
				for (int k = 0; k < width; k++)
				{
					char a = *(p + k);
					*(p + k) = *((char*)base + (j + 1) * width + k);
					*((char*)base + (j + 1) * width + k) = a;
				}
			}
		}
	}
}
int my_strcmp1(const void *s1, const void *s2)  //�Ƚ����������С 
{
	return *(int *)s1 > *(int *)s2 ? 1 : 0;  
}
int my_strcmp2(const void* s1, const void* s2)  //�Ƚ��ַ������С 
{
	return strcmp((char*)s1, (char*)s2);   //-1С��  0����  1����
}
int my_strcmp3(const void* s1, const void* s2)   //�ȽϽṹ��-�����С
{
	return *((char*)s1 + 20) > * ((char*)s2 + 20) ? 1 : 0;
}
int my_strcmp4(const void* s1, const void* s2)   //�ȽϽṹ��-���ִ�С
{
	return strcmp((char*)s1, (char*)s2);   //-1С��  0����  1����
}
//���Ժ���  ���飬�ṹ��
struct Student
{
	char name[20]; //����
	int age;   //����
};

void my_test(void)
{
	int i = 0;
	//��������-��������
	int a[11] = { 11,6,1,2,8,3,9,4,7,10,5 };
	my_qsort(a,11,4, my_strcmp1);
	for (i = 0; i < 11; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	//��������-�ַ�����
	char b[4] = { 'a','g','c','b' };
	my_qsort(b, 4, 1, my_strcmp2);
	for (i = 0; i < 4; i++)
	{
		printf("%c ", b[i]);
	}
	printf("\n");
	struct Student stu1[4] =
	{ {"zhang", 15 } ,{ "wang",18 } ,{ "li",25 },{ "qi",16 } };
	//���Խṹ��-����
	my_qsort(stu1, 4, 24, my_strcmp4);
	for (i = 0; i < 4; i++)
	{
		printf("%s ", stu1[i].name);
	}
	printf("\n");
	//���Խṹ��-����
	my_qsort(stu1, 4, 24, my_strcmp3);
	for (i = 0; i < 4; i++)
	{
		printf("%d ", stu1[i].age);
	}
	printf("\n");
}