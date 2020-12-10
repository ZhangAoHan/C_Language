#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < math.h >
//打印菱形
// 1 8  3 9  5 10  *数量=13 - |行号-7|*2 排列方式为从中间往两边分
int main()
{
	int i = 0;
	int j = 0;
	int num = 0; //第i行*的数量
	for (i = 1; i <= 13; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			num = 13 - abs(i - 7) * 2;  //第i行*的数量(奇数)  (13-num)/2
			if (j <= (13 - num) / 2 || j > 7 + num / 2)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}