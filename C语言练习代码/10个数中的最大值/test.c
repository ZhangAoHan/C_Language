//求10 个整数中最大值
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int arr[10] = {0};
	int i = 0;
	int max = 0;//最大数
	printf("请输入10个整数\n");
//输入数的数量小于10时，等待输入. 输入数量大于10个时，只取前10个
	for (i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("结果为：%d", max);
	return 0;
}