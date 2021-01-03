#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
void my_test(void);
void my_qsort(void* const base, uint num, uint width, int(*comper)(const void* s1, const void* s2));
int my_strcmp1(const void* s1, const void* s2);  //比较整型数组大小 //比较结构体-年龄大小
int my_strcmp2(const void* s1, const void* s2);  //比较字符数组大小 //比较结构体-名字大小
void my_test(void);
int main()
{
	my_test();
	return 0;
}
//base为要排序字符的起始地址
//num为要排序字符的元素个数
//width为要排序字符元素的大小（单位B）
//int(*comper)(const void* s1, const void* s2)比较函数
void my_qsort(void *const base, uint num, uint width, int(*comper)(const void *s1,const void *s2))
{
	for (int i = 0; i < num - 1; i++)  //冒泡排序算法
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (comper((char*)base + j * width, (char*)base + (j + 1) * width) == 1) //=1表示大于
			{
				char* p = (char*)base + j * width;
				//进行交换（对应地址的内容进行交换）
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
int my_strcmp1(const void *s1, const void *s2)  //比较整型数组大小 
{
	return *(int *)s1 > *(int *)s2 ? 1 : 0;  
}
int my_strcmp2(const void* s1, const void* s2)  //比较字符数组大小 
{
	return strcmp((char*)s1, (char*)s2);   //-1小于  0等于  1大于
}
int my_strcmp3(const void* s1, const void* s2)   //比较结构体-年龄大小
{
	return *((char*)s1 + 20) > * ((char*)s2 + 20) ? 1 : 0;
}
int my_strcmp4(const void* s1, const void* s2)   //比较结构体-名字大小
{
	return strcmp((char*)s1, (char*)s2);   //-1小于  0等于  1大于
}
//测试函数  数组，结构体
struct Student
{
	char name[20]; //名字
	int age;   //年龄
};

void my_test(void)
{
	int i = 0;
	//测试数组-整型数组
	int a[11] = { 11,6,1,2,8,3,9,4,7,10,5 };
	my_qsort(a,11,4, my_strcmp1);
	for (i = 0; i < 11; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	//测试数组-字符数组
	char b[4] = { 'a','g','c','b' };
	my_qsort(b, 4, 1, my_strcmp2);
	for (i = 0; i < 4; i++)
	{
		printf("%c ", b[i]);
	}
	printf("\n");
	struct Student stu1[4] =
	{ {"zhang", 15 } ,{ "wang",18 } ,{ "li",25 },{ "qi",16 } };
	//测试结构体-名字
	my_qsort(stu1, 4, 24, my_strcmp4);
	for (i = 0; i < 4; i++)
	{
		printf("%s ", stu1[i].name);
	}
	printf("\n");
	//测试结构体-年龄
	my_qsort(stu1, 4, 24, my_strcmp3);
	for (i = 0; i < 4; i++)
	{
		printf("%d ", stu1[i].age);
	}
	printf("\n");
}