#define _CRT_SECURE_NO_WARNINGS 1
//qsort����ϰʹ��
#include <stdio.h>
#include < stdlib.h >
void test(void);
int my_strcmp1(const void* s1, const void* s2);  //�Ƚ����������С 
int my_strcmp2(const void* s1, const void* s2);  //�Ƚ��ַ������С 
int my_strcmp3(const void* s1, const void* s2);   //�ȽϽṹ��-�����С
int my_strcmp4(const void* s1, const void* s2);  //�ȽϽṹ��-���ִ�С
int main()
{
	test();
	return 0;
}

int my_strcmp1(const void* s1, const void* s2)  //�Ƚ����������С 
{
	return *(int*)s1 > * (int*)s2 ? 1 : 0;
}
int my_strcmp2(const void* s1, const void* s2)  //�Ƚ��ַ������С 
{
	return strcmp((char*)s1, (char*)s2);
}
int my_strcmp3(const void* s1, const void* s2)   //�ȽϽṹ��-�����С
{
	return *((char*)s1 + 20) > * ((char*)s2 + 20) ? 1 : 0;
}
int my_strcmp4(const void* s1, const void* s2)   //�ȽϽṹ��-���ִ�С
{
	return strcmp((char*)s1, (char*)s2);   //-1С��  0����  1����
}
struct MyStruct
{
	char name[20];
	int age;
};
void test(void)
{
	int i = 0;
	/**********�����������*****************/
	int a[10] = {1,2,5,3,4,9,6,7,8,10};
	qsort(a,10,4, my_strcmp1);
	for (i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	/**********�ַ����������*****************/
	char b[10] = {2,4,1,3,5,6,9,8,7,10};
	char c[5] = { 'a','r','g','z','b' };
	qsort(b, 10, 1, my_strcmp2);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	qsort(c, 5, 1, my_strcmp2);
	for (i = 0; i < 5; i++)
	{
		printf("%c ", c[i]);
	}
	printf("\n");
	/**********�ṹ�����*****************/
	struct MyStruct stu[4] =
	{ {"zhang", 15 } ,{ "wang",18 } ,{ "li",25 },{ "qi",16 } };
	/**********�ṹ�����--��������***********/
	qsort(stu, 4, 24, my_strcmp3);  //��������
	for (i = 0; i < 4; i++)
	{
		printf("%s ", stu[i].name);
		printf("%d ", stu[i].age);
		printf("\n");
	}
	printf("\n");
	/**********�ṹ�����--��������***********/
	qsort(stu, 4, 24, my_strcmp4);  //��������
	for (i = 0; i < 4; i++)
	{
		printf("%s ", stu[i].name);
		printf("%d ", stu[i].age);
		printf("\n");
	}
	printf("\n");
}