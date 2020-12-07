//猜数字游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randn_num(void)
{
	int a = 0;
	srand((unsigned int)time(NULL));
	a = rand();
	a = a % 100;  //保证a在0-100之间
	return a;
}
void Game_play(int i)
{
	if (i == 1) //玩游戏
	{
		printf("******************************\n");
		printf("**********猜数字游戏**********\n");
		printf("********数字范围：0-100*******\n");
		printf("******************************\n");
	}
	else if (i == 2)  //提示界面 //猜大了
	{

		printf("您猜大了！\n");
	}
	else if (i == 3)      //猜小了
	{
		printf("您猜小了！\n");
	}

	else       //开始选择界面
	{
		printf("******************************\n");
		printf("**********猜数字游戏**********\n");
		printf("***********1:开始游戏*********\n");
		printf("***********0:退出游戏*********\n");
		printf("******************************\n");
	}
}
void Game_plays(void) //游戏进行中
{
	int p_set = 0;
	int p_data = 0;
	int num = randn_num(); //生成随机数
	Game_play(1);//进入游戏
	do
	{
		p_set = 1;
		printf("请输入数字");
		scanf("%d", &p_data);
		if (p_data > num) //猜大了
		{
			Game_play(2);
		}
		else if (p_data < num)//猜小了
		{
			Game_play(3);
		}
		else
		{
			printf("猜中了");
			p_set = 0;
		}
	} while (p_set != 0);    //游戏成功后推出
}
int main()
{
	int num = randn_num();  //生成随机数
	int set = 1;
	int data = 0;
	do
	{
		Game_play(5); //开始选择界面  >3的任意数字
		scanf("%d", &data);
		if (data == 1)//选择玩游戏
		{
			Game_plays();
		}
		else
		{
			set = 0;
		}
	} while (set == 1);

	return 0;
}
