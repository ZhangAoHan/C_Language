#define _CRT_SECURE_NO_WARNINGS 1

#include < stdio.h >
//int main()
//{
//	printf("%s\n",__FILE__);
//	printf("%d\n",__LINE__);
//	printf("%s\n", __DATE__);
//	printf("%d\n", __TIME__);
//	return 0;
//}
//#define ADD(a,b) a+b
//#define ADD1(a,b) ((a)+(b))
//int main()
//{
//	int a = 5;
//	int b = 3;
//	printf("%d\n",10*ADD(a,b));  //运行结果为53
//	printf("%d\n", 10 * ADD1(a, b));//运行结果为80
//	return 0;
//}
//#define ABS             //未初始化的全局变量
//#define AD 2            //初始化的全局变量
//int my_add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//int main()
//{
//	int a = 5;
//	int b = 3;
//	int c = ma_add(a,b);
//	printf("%d",c);
//	return 0;
//}

int main()
{
	char b = 0;
	int a = 5;
	printf("%d\n", sizeof(b = a + 2)); //运行结果为1
	printf("%d\n", b);          //运行结果为0
	return 0; 
}