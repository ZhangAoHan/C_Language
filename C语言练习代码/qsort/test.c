#define _CRT_SECURE_NO_WARNINGS 1
//qsort的练习使用
#include <stdio.h>
#include < stdlib.h >
void test(void);
int my_strcmp1(const void* s1, const void* s2);  //比较整型数组大小 
int my_strcmp2(const void* s1, const void* s2);  //比较字符数组大小 
int my_strcmp3(const void* s1, const void* s2);   //比较结构体-年龄大小
int my_strcmp4(const void* s1, const void* s2);  //比较结构体-名字大小
int main()
{
	test();
	return 0;
}

int my_strcmp1(const void* s1, const void* s2)  //比较整型数组大小 
{
	return *(int*)s1 > * (int*)s2 ? 1 : 0;
}
int my_strcmp2(const void* s1, const void* s2)  //比较字符数组大小 
{
	return strcmp((char*)s1, (char*)s2);
}
int my_strcmp3(const void* s1, const void* s2)   //比较结构体-年龄大小
{
	return *((char*)s1 + 20) > * ((char*)s2 + 20) ? 1 : 0;
}
int my_strcmp4(const void* s1, const void* s2)   //比较结构体-名字大小
{
	return strcmp((char*)s1, (char*)s2);   //-1小于  0等于  1大于
}
struct MyStruct
{
	char name[20];
	int age;
};
void test(void)
{
	int i = 0;
	/**********整型数组测试*****************/
	int a[10] = {1,2,5,3,4,9,6,7,8,10};
	qsort(a,10,4, my_strcmp1);
	for (i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	/**********字符型数组测试*****************/
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
	/**********结构体测试*****************/
	struct MyStruct stu[4] =
	{ {"zhang", 15 } ,{ "wang",18 } ,{ "li",25 },{ "qi",16 } };
	/**********结构体测试--年龄排序***********/
	qsort(stu, 4, 24, my_strcmp3);  //年龄排序
	for (i = 0; i < 4; i++)
	{
		printf("%s ", stu[i].name);
		printf("%d ", stu[i].age);
		printf("\n");
	}
	printf("\n");
	/**********结构体测试--名字排序***********/
	qsort(stu, 4, 24, my_strcmp4);  //年龄排序
	for (i = 0; i < 4; i++)
	{
		printf("%s ", stu[i].name);
		printf("%d ", stu[i].age);
		printf("\n");
	}
	printf("\n");
}