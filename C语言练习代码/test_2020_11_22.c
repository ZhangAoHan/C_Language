
//#include <stdio.h>
////打印闰年（能被4整除，不能被100整除）
//int main()
//{
//	int i = 1000;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0)
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//打印素数（不能被除1和自身之外的数整除）
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = i-1;
//		for (j = i-1; j > 1; j--)
//		{
//			if (i % j == 0)//成立则为合数
//			{
//				break;
//			}
//		}
//		if (j == 1) //成立则为素数
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;//出现9数字的个数
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			sum = sum + 1;
//		}
//	}
//	printf("一共有%d个数字中包含9！",sum);
//	return 0;
//}

////计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0;//结果
//	for (i = 1; i <= 100; i++)
//	{
//		double j = 0;
//		j = 1.0 / i;
//		if (i % 2 == 0)
//		{
//			sum = sum - j;
//		}
//		else
//		{
//			sum = sum + j;
//		}
//	}
//	printf("结果为：%f", sum);
//	return 0;
//}
////求10 个整数中最大值
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	int max = 0;//最大数
//	printf("请输入10个整数");
////输入数的数量小于10时，等待输入. 输入数量大于10个时，只取前10个
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d",&arr[i]);
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("结果为：%d", max);
//	return 0;
//}

//在屏幕上输出9*9乘法口诀表
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	printf("乘法口诀表");
//	for (i = 1; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			sum = i * j;
//			printf("%d x %d = %d  ",i,j,sum);
//		}
//		printf("\n");//换行
//	}
//	return 0;
//}
////猜数字游戏
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int randn_num(void)
//{
//	int a = 0;
//	srand((unsigned int)time(NULL));
//	a = rand();
//	a = a % 100;  //保证a在0-100之间
//	return a;
//}
//void Game_play(int i)
//{
//	if (i == 1) //玩游戏
//	{
//		printf("******************************\n");
//		printf("**********猜数字游戏**********\n");
//		printf("********数字范围：0-100*******\n");
//		printf("******************************\n");
//	}
//	else if (i == 2)  //提示界面 //猜大了
//	{
//
//		printf("您猜大了！\n");
//	}
//	else if(i == 3 )      //猜小了
//	{
//		printf("您猜小了！\n");
//	}
//	
//	else       //开始选择界面
//	{
//		printf("******************************\n");
//		printf("**********猜数字游戏**********\n");
//		printf("***********1:开始游戏*********\n");
//		printf("***********0:退出游戏*********\n");
//		printf("******************************\n");
//	}
//}
//void Game_plays(void) //游戏进行中
//{
//	int p_set = 0;
//	int p_data = 0;
//	int num = randn_num(); //生成随机数
//	Game_play(1);//进入游戏
//	do  
//	{
//		p_set = 1;
//		printf("请输入数字");
//		scanf("%d", &p_data);
//		if (p_data > num) //猜大了
//		{
//			Game_play(2);
//		}
//		else if (p_data < num)//猜小了
//		{
//			Game_play(3);
//		}
//		else
//		{
//			printf("猜中了");
//			p_set = 0;
//		}
//	} while (p_set != 0);    //游戏成功后推出
//}
//int main()
//{
//	int num = randn_num();  //生成随机数
//	int set = 1;
//	int data=0;
//	do
//	{
//		Game_play(5); //开始选择界面  >3的任意数字
//		scanf("%d", &data);
//		if (data == 1)//选择玩游戏
//		{
//			Game_plays();
//		}
//		else
//		{
//			set = 0;
//		}
//	} while (set == 1);
//	
//	return 0;
//}
//二分查找
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };//模拟数组
int xb = -1;//下标
void Find_num(int len,int num)
{
	int left = 0;
	int right = len;
	int Success = 0;
	do
	{
		int sit = (left + right) / 2;//寻找中心下标
		if (arr[sit] > num) //num在左边
		{
			right = sit - 1;
		}
		else if (arr[sit] < num) //num在右边
		{
			left = sit + 1;
		}
		else //已经找到
		{
			xb = sit;
			Success = 1;
		}
		if ( left == right )
		{
			if (arr[sit] == num) //进行最后一次判断，防止漏掉
			{
				xb = sit;
			}
			Success = 1;
		
		}
	} while (!Success);
}

int main()
{
	int len = sizeof(arr) / sizeof(arr[0]) - 1;//最大下标
	printf("请输入一个数");
	int num = 0;
	scanf("%d",&num);
	Find_num(len, num);
	if (xb == -1)//没有找到
	{
		printf("没有找到");
	}
	else
	{
		printf("下标为：%d", xb);
	}
	

	return 0;
}