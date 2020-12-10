#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < assert.h >
void YH(int a);
int main()
{ 
	int a;
	printf("请输入一个数a（a<200),生成a行杨辉三角\n");
	scanf("%d",&a);
	YH(a);
	return 0;
}
void YH(int a)
{
	int i = 0;
	int j = 0;
	int arr1[200] = { 1 }; //显示数据
	int arr[200] = { 1 }; //上一行的数据
	arr1[0] = 1;
	arr1[1] = 1;
	arr[0] = 1;
	arr[1] = 1;
	for (i = 0; i < a; i++) //一共显示a行
	{
		if (i == 0) //第一行
		{
			printf("1");
		}
		else if (i == 1) //第二行
		{
			printf("1 1");
		}
		else  //
		{

			printf("1 ");
			for (j = 1; j <= i - 1; j++)  //第i+1行 共显示i+1个数
			{
				printf("%d ",arr1[j - 1] + arr1[j]);
				arr[j] = arr1[j - 1] + arr1[j];
			}
			arr[i] = 1;
			printf("1");
			for (j = 0; j <= i; j++) //数据迭代
			{
				arr1[j] = arr[j];
			}
		}
		printf("\n");
	}

}