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
//	printf("测试1\n");
//	if (my_strstr1(a, b) == NULL)
//	{
//		printf("b为空字符串\n");
//	}
//	else
//	{
//		printf("目标字符串包含子字符串，起始位置为：%p,\n在目标字符串中的：%c处起始\n", my_strstr1(a, b), *my_strstr1(a, b));
//	}
//	printf("测试2\n");
//	if (my_strstr1(a, c) == NULL)
//	{
//		printf("b为空字符串\n");
//	}
//	else
//	{
//		printf("目标字符串包含子字符串，起始位置为：%p,\n在目标字符串中的：%c处起始\n", my_strstr1(a, c), *my_strstr1(a, c));
//	}
//	printf("测试3\n");
//	if (my_strstr1(a, d) == NULL)
//	{
//		printf("b为空字符串\n");
//	}
//	else
//	{
//		printf("目标字符串包含子字符串，起始位置为：%p,\n在目标字符串中的：%c处起始\n", my_strstr1(a, d), *my_strstr1(a, d));
//	}
//	return 0;
//}
//
////暴力求解法
//char* my_strstr1(const char* string, const char* strcharset)
//{
//	int i = 0;//目标字符串下标
//	int j = 0;//子字符串下标
//	if (strcharset == NULL)
//	{
//		return string;
//	}
//	else
//	{
//		while (1)
//		{
//			if (*(string + i) == '\0') //目标字符串到结尾了还没跳出（说明目标字符串不含子串）
//			{
//				return NULL;
//			}
//			else
//			{
//				if (*(strcharset + j) == '\0') //b已全部判断完毕，目标字符串中包含子串
//				{
//					return string + i;
//				}
//				else
//				{
//					if (*(string + i + j) == *(strcharset + j)) //匹配到字符
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

//KMP法
int main()
{

	return 0;
}

char* my_strstr_KMP(const char* string, const char* strcharset)
{
	
}