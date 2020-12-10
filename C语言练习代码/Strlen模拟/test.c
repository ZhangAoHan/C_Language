#define _CRT_SECURE_NO_WARNINGS 1
//strlen 模拟
#include <stdio.h>



int main()
{
	char arr[] = "abscjdksuslaj asdl";
	int num = 0;//字符串数量

	num = Str_len(arr);
	printf("%d",num);
	return 0;
}
int Str_len(const char *arr)
{
	char* p = arr;
	while (*(p++) != '\0');
	return p - arr - 1;
}
//int Str_len(char *str,int sit); //strlen
//int main()
//{
//	char str[100];   //输入字符串长度必须小于100
//	int len = 0;
//	scanf("%s",str); //取出字符串首地址
//	len = Str_len(str,1);
//	printf("递归求解结果为： %d\n",len);
//	len = Str_len(str, 0);
//	printf("循环求解结果为： %d\n", len);
//	return 0;
//}
//
//int Str_len(char* strs,int sit)
//{
//	if (sit)  //递归求解
//	{
//		if (*strs == '\0')
//		{
//			return 0;
//		}
//		else
//		{
//			return 1 + Str_len(strs + 1,1);
//		}
//	}
//	else  //非递归求解
//	{
//		int len = 0;
//		while (*strs != '\0')
//		{
//			len++;
//			strs++;
//		}
//		return len;
//	}
//
//}




