#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//三子棋
//规则： 3*3的棋盘上（共可以放9个元素）
// A B各三个元素（轮流放置），放完三个元素后，每次只能移动一个己方元素，并且不能移动对方元素
// 胜利条件：三个元素排成一列 为胜



void Init_display(void);//初始显示函数
int Scan(int a, int b, int c, int d, int* arr1, int* arr2, int sit);//检测棋子落子或移动是否合理
void Game_hint(int a);
void QP_display(char* arr, int* arr1, int* arr2); //棋盘显示函数(AB棋子位置)
void QP_Init(void); //棋盘初始化
int Victory_Judgment(void);  //判断是否胜利（移动环节才调用）
void QZ_Init(void); //棋子位置初始化

int arr_A[3][2] = { {0,0},{0,0},{0,0} }; //棋子初始化
int arr_B[3][2] = { {0,0},{0,0},{0,0} };
char arr[4][4] = { {'0','1','2','3' },{'1','*','*','*' },{'2','*','*','*' },{'3','*','*','*' } };
int main()
{
	int sit = 1; //落子模式和移动模式（1-6为落子模式 7为移动模式）
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int Legal = 0; //合法标志位
	int i = 0;
	Init_display(); //初始化显示
	QP_display(arr, arr_A, arr_B); //刷新棋盘
	do
	{
			if (sit < 7) //落子模式
			{
				if (sit % 2 == 1) //A落子
				{
					Game_hint(2); //提示信息
				}
				else //B落子
				{
					Game_hint(3); //提示信息
				}
				scanf("%d %d",&c,&d); //键入坐标
				Legal = Scan(0, 0, c, d, arr_A, arr_B, 1); //落子模式检测
				if (Legal)  //键入合法
				{
					if (sit % 2 == 1)//A					//如果合法 将坐标储存
					{
						arr_A[sit / 2][0] = c;
						arr_A[sit / 2][1] = d;
					}
					else
					{
						if (sit >= 2) //正常输入，肯定满足此条件（加上此语句为了：消除警告）
						{
							arr_B[sit / 2 - 1][0] = c;
							arr_B[sit / 2 - 1][1] = d;
						}
					}

					QP_display(arr, arr_A, arr_B); //刷新棋盘
					sit++;
					if (sit > 4) //落下第三个棋子时 检测第三个棋子是否达到胜利条件
					{
						if (Victory_Judgment() == 1) //A胜利
						{
							Game_hint(6);
							printf("**********是否重玩？**********");
							printf("*********是：1 否：0 *********\n");
							scanf("%d", &i);
							if (i)
							{
								QP_Init();
								QZ_Init();
								Init_display(); //初始化显示
								sit = 1; //落子模式和移动模式（1-6为落子模式 7为移动模式）
								Legal = 0; //合法标志位
							}
							else
							{
								break;
							}
						}
						if (Victory_Judgment() == 2) //B胜利
						{
							Game_hint(7);
							printf("**********是否重玩？**********");
							printf("*********是：1 否：0 *********\n");
							scanf("%d", &i);
							if (i)
							{
								QP_Init();
								QZ_Init();
								Init_display(); //初始化显示
								sit = 1; //落子模式和移动模式（1-6为落子模式 7为移动模式）
								Legal = 0; //合法标志位
							}
							else
							{
								break;
							}
						}
					}
				}
			}
			else  //棋子移动模式
			{
				if (sit == 7) //A移动
				{
					
					Game_hint(4); //提示信息
				}
				else    //B移动
				{
					Game_hint(5); //提示信息
				}
				scanf("%d %d %d %d", &a, &b,&c, &d); //键入坐标
				Legal = Scan(a, b, c, d, arr_A, arr_B, 0); //落子模式检测
				if (Legal)  //键入合法
				{
					//替换坐标
					if (sit == 7) //A
					{
						for (i = 0; i < 3; i++)
						{
							if (arr_A[i][0] == a && arr_A[i][1] == b)
							{
								arr_A[i][0] = c;
								arr_A[i][1] = d;
							}
						}
					}
					else    //B
					{
						for (i = 0; i < 3; i++)
						{
							if (arr_B[i][0] == a && arr_B[i][1] == b)
							{
								arr_B[i][0] = c;
								arr_B[i][1] = d;
							}
						}
					}
					QP_display(arr, arr_A, arr_B); //刷新棋盘
					if (sit == 7)
					{
						sit = 8;
					}
					else
					{
						sit = 7;
					}
				}
				// 判断是否有人胜利
				if (Victory_Judgment() == 1) //A胜利
				{
					Game_hint(6);
					printf("**********是否重玩？**********");
					printf("*********是：1 否：0 *********\n");
					scanf("%d", &i);
					if (i)
					{
						QP_Init();
						QZ_Init();
						Init_display(); //初始化显示
						sit = 1; //落子模式和移动模式（1-6为落子模式 7为移动模式）
						Legal = 0; //合法标志位
					}
					else
					{
						break; 
					}
				}
				else if (Victory_Judgment() == 2) //B胜利
				{
					Game_hint(7); 
					printf("**********是否重玩？**********");
					printf("*********是：1 否：0 *********\n");
					scanf("%d", &i);
					if (i)
					{
						QP_Init();
						QZ_Init();
						Init_display(); //初始化显示
						sit = 1; //落子模式和移动模式（1-6为落子模式 7为移动模式）
						Legal = 0; //合法标志位
					}
					else
					{
						break;
					}
				}
				
			}
	} while (1);
	return 0;
}



//初始显示函数
void Init_display(void)
{
	printf("/*********三子棋**********/\n");
	printf("/*******A棋子：o**********/\n");
	printf("/*******B棋子：#**********/\n");
	printf("/***前三步落子键入：a b***/\n");
	printf("/**移动棋子键入：a b c d**/\n");
}
//游戏运行提示函数
void Game_hint(int a)
{
	switch (a)
	{
	case 0:
		printf("落子不合法，请重新落子\n");
		break;
	case 1:
		printf("棋子移动不合法，请重新移动\n");
		break;
	case 2:
		printf("请A选手落子\n");
		break;
	case 3:
		printf("请B选手落子\n");
		break;
	case 4:
		printf("请A选手移动棋子\n");
		break;
	case 5:
		printf("请B选手移动棋子\n");
		break;
	case 6:
		printf("A选手胜利！\n");
		break;
	case 7:
		printf("B选手胜利！\n");
		break;
	}
}

void QP_display(char* arr,int* arr1,int* arr2) //棋盘显示函数(AB棋子位置)
//将非棋子位置标为*   A棋子:o  B棋子：v
{
	int i = 0;
	int j = 0;
	//先初始化棋盘
	QP_Init();
	for (i = 0; i < 3; i++) //将棋子坐标更新到棋盘上
	{
		if (*(arr1 + 2 * i) != 0 && *(arr1 + 2 * i + 1) != 0) //A棋子坐标合法
		{
			*(arr + 4 * (*(arr1 + 2 * i)) + (*(arr1 + 2 * i + 1)) ) = 'o';
		}
		if (*(arr2 + 2 * i) != 0 && *(arr2 + 2 * i + 1) != 0) //A棋子坐标合法
		{
			*(arr + 4 * (*(arr2 + 2 * i)) + (*(arr2 + 2 * i + 1)) ) = 'v';
		}
	}
	//打印棋盘
	for (i = 0; i < 4; i++)
	{
		printf("%c %c %c %c\n",*(arr + 4 * i),*(arr + 4 * i + 1), *(arr + 4 * i + 2), *(arr + 4 * i + 3));
	}
}


int Scan(int a, int b, int c, int d,int *arr1,int *arr2,int sit)//检测棋子移动是否合理（不能移动对手的棋子）,并且自己的棋子不能重叠 合法返回1 不合法返回0
// (a,b)棋子初始位置（落子模式下为（0,0）） (c,d)为棋子最终位置   arr1：A选手棋子位置（本次移动未记录）  arr2：B选手棋子位置  sit=1 落子模式  sit=0移动模式
{
	int i = 0;
	int j = 0;
	if (sit) //落子合法性检验(不与其余棋子的位置重叠)
	{
		if (c > 3 || c < 0 || d > 3 || d < 0) //落子不合法
		{
			Game_hint(0);
			return 0;
		}

	}
	else     //移动合法性检验
	{
		if (a > 3 || a < 0 || b > 3 || b < 0 || c > 3 || c < 0 || d > 3 || d < 0) //落子不合法
		{
			Game_hint(0);
			return 0;
		}
			
		if (abs(c + d - a - b) != 1)  //移动方向
		{
			Game_hint(1);
			return 0;
		}
			
	}
	// 检验此次棋子最终坐标是否与现有棋子坐标重叠？
	for (i = 0; i < 3; i++) //检验落子是否和其余棋子重叠
	{
		if (c == *(arr1 + 2 * i))
		{
			if (d == *(arr1 + 2 * i + 1)) //落子与A棋子重叠
			{
				Game_hint(1);
				return 0;
			}
		}
		if (c == *(arr2 + 2 * i))
		{
			if (d == *(arr2 + 2 * i + 1)) //落子与B棋子重叠
			{
				Game_hint(1);
				return 0;
			}
		}
	}
	return 1;  //合法
}

void QP_Init(void) //棋盘初始化
{
	arr[0][0] = '0';
	arr[0][1] = '1';
	arr[0][2] = '2';
	arr[0][3] = '3';
	arr[1][0] = '1';
	arr[1][1] = '*';
	arr[1][2] = '*';
	arr[1][3] = '*';
	arr[2][0] = '2';
	arr[2][1] = '*';
	arr[2][2] = '*';
	arr[2][3] = '*';
	arr[3][0] = '3';
	arr[3][1] = '*';
	arr[3][2] = '*';
	arr[3][3] = '*';
}
void QZ_Init(void) //棋子位置初始化
{
	arr_A[0][0] = 0;
	arr_A[0][1] = 0;
	arr_A[1][0] = 0;
	arr_A[1][1] = 0;
	arr_A[2][0] = 0;
	arr_A[2][1] = 0;

	arr_B[0][0] = 0;
	arr_B[0][1] = 0;
	arr_B[1][0] = 0;
	arr_B[1][1] = 0;
	arr_B[2][0] = 0;
	arr_B[2][1] = 0;
}
int Victory_Judgment(void)  //胜利判断函数(在移动环节起作用)   返回0：没有胜利者  1：A胜利  2：B胜利
//A胜利条件：A的3枚棋子排成一行 或 B的棋子被堵死（B没有可以移动的棋子）
{
	int i = 0;
	/****************************
	              检测A B是否排成直线
	***************************************************/
	//排成一条直线： 设A的三枚棋子为： 棋子1（x1,y1）  棋子2(x2,y2)  棋子3(x3,y3)
	//如果A的三枚棋子在一条直线上，一行（x相同） 或 一列(y相同) 或 对角线（2种情况）
	if ((arr_A[0][0] == arr_A[1][0]) && (arr_A[0][0] == arr_A[2][0]) && (arr_A[1][0] == arr_A[2][0])) //一行
	{
		printf("A棋子排成一行\n");
		return 1;
	}
	else if((arr_A[0][1] == arr_A[1][1]) && (arr_A[0][1] == arr_A[2][1]) && (arr_A[1][1] == arr_A[2][1]))
	{
		printf("A棋子排成一列\n");
		return 1;
	}
	else if ((arr_A[0][0] == arr_A[0][1]) && (arr_A[1][0] == arr_A[1][1]) && (arr_A[2][0] == arr_A[2][1]))
	{
		if ((arr_A[0][0] != 0) && (arr_A[1][0] != 0) && (arr_A[2][0] != 0))
		{
			printf("A棋子排成对角线\n");
			return 1;
		}
	}

	if ((arr_B[0][0] == arr_B[1][0]) && (arr_B[0][0] == arr_B[2][0]) && (arr_B[1][0] == arr_B[2][0])) //一行
	{
		printf("B棋子排成一行\n");
		return 2;
	}
	else if ((arr_B[0][1] == arr_B[1][1]) && (arr_B[0][1] == arr_B[2][1]) && (arr_B[1][1] == arr_B[2][1]))
	{
		printf("B棋子排成一列\n");
		return 2;
	}
	else if ((arr_B[0][0] == arr_B[0][1]) && (arr_B[1][0] == arr_B[1][1]) && (arr_B[2][0] == arr_B[2][1]))
	{
		if ((arr_B[0][0] != 0) && (arr_B[1][0] != 0) && (arr_B[2][0] != 0))
		{
			printf("B棋子排成对角线\n");
			return 2;
		}
	}
	return 0; //没有人胜利
}

