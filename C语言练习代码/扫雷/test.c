#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//9*9的棋盘 地雷数量：15
#define H_num 9  //显示棋盘大小;
#define L_num 9
#define DH_num (H_num + 2)  //可用棋盘大小;
#define DL_num (L_num + 2)
#define DL 10    //地雷数量
int Game(char* arr, char* arr1);  //游戏函数  返回1 再玩一次  返回0 退出
void Display(char* arr, int H, int L);
void Init(char* arr1, char* arr2);
int randn_num(int aa); //随机数生成函数
char DL_Num(int a, int b, char* arr1); //计算地雷数量 输入可用棋盘
void DL_Display(char* arr, int H, int L);  //画地雷（验证函数函数）
void Game_GX(int x, int y, char* arr, char* arr1); //自动探索可显示区域（自动更新显示棋盘内容）  arr显示棋盘  arr1可用棋盘
char ZAH_y(int a, int b, char* arr, char* arr1); //自动扩展函数
int main()
{
	int aaa = H_num;
	int bbb = DH_num;
	char arr_dis[H_num][L_num] = {'0'};
	char arr[DH_num][DL_num] = {'0'};
	do
	{ 
		Init(arr_dis, arr);
		printf("/********1：地雷********/\n");
		DL_Display(arr, DH_num, DL_num);
		printf("/**********棋盘**********/\n");
		Display(arr_dis, H_num, L_num);
		//Display(arr, DH_num , DL_num );
		if (Game(arr_dis, arr) == 0)
			break;
	} while (1);
}


void Init(char* arr1,char* arr2)  //初始化函数
{
	int i = 0;
	int a = 0;
	int b = 0;
	int num = 0;
	srand((unsigned int)time(NULL));
	printf("/**********扫雷*********/\n");
	printf("/*比特学员：86班 张奥涵*/\n");
	for (i = 0; i < H_num * L_num; i++) // 棋盘初始化函数
	{
		*(arr1 + i) = '*';
	}
	//地雷初始化
	for (i = 0; i < DH_num * DL_num; i++) // 地雷位置初始化
	{
		*(arr2 + i) = '0';
	}
	i = 0;
	while (i < DL)
	{
		num++;
		a = randn_num(H_num - 2); //随机行数
		b = randn_num(L_num - 2); //随机列数
		if (*(arr2 + (a * DH_num) + b) == '0') //地雷位置合法
		{
			*(arr2 + (a * DH_num) + b) = '1';
			i++;
		}
	}
}
int randn_num(int aa) //随机数生成函数
{
	int a = 0;
	a = rand();
	a = a % aa + 2;  //保证a在1-（aa+1）之间
	return a;
}
void Display(char *arr,int H,int L)  //画棋盘（显示函数）
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= H; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 0; i < H; i++)
	{
		printf("%d ", i + 1);
		for (j = 0; j < L; j++)  //画棋盘
		{
			printf("%c ",*(arr ++));
		}
		printf("\n");
	}
	printf("/*****输入坐标：a b*****/\n");
}

int Game(char* arr,char* arr1)  //游戏函数  返回1 再玩一次  返回0 退出
//arr:显示棋盘9*9
//arr1:可用棋盘11*11
//合法：更新坐标  不合法：重新输入
{
	int nnum = 0;  
	do
	{
		int a = 0;
		int b = 0;
		char num = '0';
		scanf("%d %d",&a,&b);
		if (a < 1 || a > 9 || b < 1 || b > 9) //坐标不合法
		{
			printf("输入坐标不合法，坐标范围1-9，请重新输入！\n");
		}
		else if (*(arr + ((a - 1) * H_num ) + (b - 1)) != '*')  //输入坐标已经被探测过
		{
			printf("%c\n" ,* (arr + ((a - 1) * H_num + 1) + (b - 1)));
			printf("输入坐标已被探测，请重新输入！\n");
		}
		else  //合法坐标
		{
			//检测是否触雷,计算地雷数量
			//num = DL_Num(a  ,b,arr1);
			//if (num != 'D')  //没有触雷
			//{
			//	*(arr + ((a - 1) * H_num) + b - 1) = num;  //显示棋盘更新 
			//	Display(arr, H_num, L_num); 
			//}
			//else
			//{

			//	break;
			//}
			//nnum ++;

			num = ZAH_y(a, b, arr, arr1);
			Display(arr, H_num, L_num);  //显示棋盘更新   arr自动刷新
			//DL_Display(arr1, DH_num, DL_num);  //输出地雷位置 方便验证
			if (num == 'D')  //触雷
				break;
		}
	} while (nnum < H_num * L_num - DL);
	//是否再玩一次
	printf("/*******再次游戏？*********/\n");
	printf("/***1：再次游戏  0：退出***/\n");
	scanf("%d", &nnum);
	return nnum;
}

char DL_Num(int a, int b, char* arr1) //检测是否触雷，同时计算地雷数量 输入可用棋盘  触雷返回D  
{
	if (*(arr1 + a * DH_num + b) == '1') //触雷
	{
		return 'D';
	}
	else
	{
		return (*(arr1 + a * DH_num + b - 1) - '0') + (*(arr1 + a * DH_num + b + 1) - '0') +
			(*(arr1 + (a - 1) * DH_num + b - 1) - '0') + (*(arr1 + (a - 1) * DH_num + b) - '0') + (*(arr1 + (a - 1) * DH_num + b + 1) - '0') +
			(*(arr1 + (a + 1) * DH_num + b - 1) - '0') + (*(arr1 + (a + 1) * DH_num + b) - '0') + (*(arr1 + (a + 1) * DH_num + b + 1) - '0') + '0';
	}

}
void DL_Display(char* arr, int H, int L)  //画地雷（验证函数函数）
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= H - 2; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 0; i < H - 2; i++)
	{
		printf("%d ", i + 1);
		for (j = 0; j < L - 2; j++)  //画棋盘
		{
			printf("%c ", *(arr + (1 + i) * L + j + 1));
		}
		printf("\n");
	}
}


/********************************************************扩展：自适应给出无雷的地方**********************************************************************************/
/**********************************************************************************************************************************/
//该点四周没有地雷，则显示‘ ’ 否则正常显示周围地雷的数量
char ZAH_y(int a, int b, char* arr, char *arr1)  //输入合法坐标,显示棋盘和可用棋盘指针   自动变更显示（自动更新显示棋盘内容）  返回D 表示触雷 否则返回‘1’ 继续游戏
{
	int num = 0;
	if (*(arr1 + a * DH_num + b )  == '1')   //触雷
	{
		*(arr + ((a - 1) * H_num) + b - 1) = 'X';  //X表示地雷
		return 'D';
	}
	else                      //没有触雷   自动探索可显示区域（自动更新显示棋盘内容）
	{
		Game_GX(a, b, arr, arr1);
		return '1';
	}
	
}

void Game_GX(int x, int y, char *arr, char* arr1)  //自动探索可显示区域（自动更新显示棋盘内容）  arr显示棋盘  arr1可用棋盘
{
	if ((x >= 1 || x <= 9) && (y >= 1 || y <= 9)) //坐标合法
	{
		if (*(arr + ((x - 1) * H_num) + (y - 1)) == '*')  //输入坐标没被探测过
		{

			if (DL_Num(x, y, arr1) == '0')  //x y坐标周围没雷
			{
				*(arr + ((x - 1) * H_num) + y - 1) = ' ';  //变更显示‘ ’，不会导致重复递归
				if( y > 1) Game_GX(x, y - 1, arr, arr1); //探寻此点 上下左右
				if( y < 9) Game_GX(x, y + 1, arr, arr1); //探寻此点 上下左右
				if( x > 1) Game_GX(x - 1, y, arr, arr1); //探寻此点 上下左右
				if( x < 9) Game_GX(x + 1, y, arr, arr1); //探寻此点 上下左右
			}
			else   //边界显示
			{
					*(arr + ((x - 1) * H_num) + y - 1) = DL_Num(x, y, arr1);	
			}
		}
	}

}