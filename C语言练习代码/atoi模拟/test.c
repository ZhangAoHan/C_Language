#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int my_atoi(const char* string);
int main()
{
	char a[] = "av-1524b23";
	char b[] = "a125-321s";
	char c[] = "+125s23";
	printf("测试字符串1：%s\n转换结果为：%d\n", a,my_atoi(a));
	printf("测试字符串2：%s\n转换结果为：%d\n", b, my_atoi(b));
	printf("测试字符串3：%s\n转换结果为：%d\n", c, my_atoi(b));
	return 0;
}

int my_atoi(const char *string)//将数字字符串转换为整型（符号位必须和数字紧挨着，不能有空格）
{
	int sit = 0;//符号位  1为正  -1为负
	int rest = 0;//结果
	do
	{
		if (*string - '0' <= 9 && *string - '0' >= 0) //碰见0-9内的数值
		{
			if (sit == 0) //第一次碰见数字，则提取符号位
			{
				if (*(string - 1) == '-')
				{
					sit = -1; //符号位为负
				}
				else
				{
					sit = 1; //符号位为正
				}
			}
			//提取结果
			rest = rest * 10 + (*string - '0');
		}
		else
		{
			//字符串中，数字直接不能有任何非数字字符，否则只计算前一段数字字符
			if (sit != 0 || *string == '\n') //没有碰见数字并且sit不为0，则认为数字提取已经结束
			{
				return rest * sit;
			}
		}
		string++;
	} while (1);
}