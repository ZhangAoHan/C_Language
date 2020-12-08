#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//9*9������ ����������15
#define H_num 9  //��ʾ���̴�С;
#define L_num 9
#define DH_num (H_num + 2)  //�������̴�С;
#define DL_num (L_num + 2)
#define DL 10    //��������
int Game(char* arr, char* arr1);  //��Ϸ����  ����1 ����һ��  ����0 �˳�
void Display(char* arr, int H, int L);
void Init(char* arr1, char* arr2);
int randn_num(int aa); //��������ɺ���
char DL_Num(int a, int b, char* arr1); //����������� �����������
void DL_Display(char* arr, int H, int L);  //�����ף���֤����������
void Game_GX(int x, int y, char* arr, char* arr1); //�Զ�̽������ʾ�����Զ�������ʾ�������ݣ�  arr��ʾ����  arr1��������
char ZAH_y(int a, int b, char* arr, char* arr1); //�Զ���չ����
int main()
{
	int aaa = H_num;
	int bbb = DH_num;
	char arr_dis[H_num][L_num] = {'0'};
	char arr[DH_num][DL_num] = {'0'};
	do
	{ 
		Init(arr_dis, arr);
		printf("/********1������********/\n");
		DL_Display(arr, DH_num, DL_num);
		printf("/**********����**********/\n");
		Display(arr_dis, H_num, L_num);
		//Display(arr, DH_num , DL_num );
		if (Game(arr_dis, arr) == 0)
			break;
	} while (1);
}


void Init(char* arr1,char* arr2)  //��ʼ������
{
	int i = 0;
	int a = 0;
	int b = 0;
	int num = 0;
	srand((unsigned int)time(NULL));
	printf("/**********ɨ��*********/\n");
	printf("/*����ѧԱ��86�� �Űº�*/\n");
	for (i = 0; i < H_num * L_num; i++) // ���̳�ʼ������
	{
		*(arr1 + i) = '*';
	}
	//���׳�ʼ��
	for (i = 0; i < DH_num * DL_num; i++) // ����λ�ó�ʼ��
	{
		*(arr2 + i) = '0';
	}
	i = 0;
	while (i < DL)
	{
		num++;
		a = randn_num(H_num - 2); //�������
		b = randn_num(L_num - 2); //�������
		if (*(arr2 + (a * DH_num) + b) == '0') //����λ�úϷ�
		{
			*(arr2 + (a * DH_num) + b) = '1';
			i++;
		}
	}
}
int randn_num(int aa) //��������ɺ���
{
	int a = 0;
	a = rand();
	a = a % aa + 2;  //��֤a��1-��aa+1��֮��
	return a;
}
void Display(char *arr,int H,int L)  //�����̣���ʾ������
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
		for (j = 0; j < L; j++)  //������
		{
			printf("%c ",*(arr ++));
		}
		printf("\n");
	}
	printf("/*****�������꣺a b*****/\n");
}

int Game(char* arr,char* arr1)  //��Ϸ����  ����1 ����һ��  ����0 �˳�
//arr:��ʾ����9*9
//arr1:��������11*11
//�Ϸ�����������  ���Ϸ�����������
{
	int nnum = 0;  
	do
	{
		int a = 0;
		int b = 0;
		char num = '0';
		scanf("%d %d",&a,&b);
		if (a < 1 || a > 9 || b < 1 || b > 9) //���겻�Ϸ�
		{
			printf("�������겻�Ϸ������귶Χ1-9�����������룡\n");
		}
		else if (*(arr + ((a - 1) * H_num ) + (b - 1)) != '*')  //���������Ѿ���̽���
		{
			printf("%c\n" ,* (arr + ((a - 1) * H_num + 1) + (b - 1)));
			printf("���������ѱ�̽�⣬���������룡\n");
		}
		else  //�Ϸ�����
		{
			//����Ƿ���,�����������
			//num = DL_Num(a  ,b,arr1);
			//if (num != 'D')  //û�д���
			//{
			//	*(arr + ((a - 1) * H_num) + b - 1) = num;  //��ʾ���̸��� 
			//	Display(arr, H_num, L_num); 
			//}
			//else
			//{

			//	break;
			//}
			//nnum ++;

			num = ZAH_y(a, b, arr, arr1);
			Display(arr, H_num, L_num);  //��ʾ���̸���   arr�Զ�ˢ��
			//DL_Display(arr1, DH_num, DL_num);  //�������λ�� ������֤
			if (num == 'D')  //����
				break;
		}
	} while (nnum < H_num * L_num - DL);
	//�Ƿ�����һ��
	printf("/*******�ٴ���Ϸ��*********/\n");
	printf("/***1���ٴ���Ϸ  0���˳�***/\n");
	scanf("%d", &nnum);
	return nnum;
}

char DL_Num(int a, int b, char* arr1) //����Ƿ��ף�ͬʱ����������� �����������  ���׷���D  
{
	if (*(arr1 + a * DH_num + b) == '1') //����
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
void DL_Display(char* arr, int H, int L)  //�����ף���֤����������
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
		for (j = 0; j < L - 2; j++)  //������
		{
			printf("%c ", *(arr + (1 + i) * L + j + 1));
		}
		printf("\n");
	}
}


/********************************************************��չ������Ӧ�������׵ĵط�**********************************************************************************/
/**********************************************************************************************************************************/
//�õ�����û�е��ף�����ʾ�� �� ����������ʾ��Χ���׵�����
char ZAH_y(int a, int b, char* arr, char *arr1)  //����Ϸ�����,��ʾ���̺Ϳ�������ָ��   �Զ������ʾ���Զ�������ʾ�������ݣ�  ����D ��ʾ���� ���򷵻ء�1�� ������Ϸ
{
	int num = 0;
	if (*(arr1 + a * DH_num + b )  == '1')   //����
	{
		*(arr + ((a - 1) * H_num) + b - 1) = 'X';  //X��ʾ����
		return 'D';
	}
	else                      //û�д���   �Զ�̽������ʾ�����Զ�������ʾ�������ݣ�
	{
		Game_GX(a, b, arr, arr1);
		return '1';
	}
	
}

void Game_GX(int x, int y, char *arr, char* arr1)  //�Զ�̽������ʾ�����Զ�������ʾ�������ݣ�  arr��ʾ����  arr1��������
{
	if ((x >= 1 || x <= 9) && (y >= 1 || y <= 9)) //����Ϸ�
	{
		if (*(arr + ((x - 1) * H_num) + (y - 1)) == '*')  //��������û��̽���
		{

			if (DL_Num(x, y, arr1) == '0')  //x y������Χû��
			{
				*(arr + ((x - 1) * H_num) + y - 1) = ' ';  //�����ʾ�� �������ᵼ���ظ��ݹ�
				if( y > 1) Game_GX(x, y - 1, arr, arr1); //̽Ѱ�˵� ��������
				if( y < 9) Game_GX(x, y + 1, arr, arr1); //̽Ѱ�˵� ��������
				if( x > 1) Game_GX(x - 1, y, arr, arr1); //̽Ѱ�˵� ��������
				if( x < 9) Game_GX(x + 1, y, arr, arr1); //̽Ѱ�˵� ��������
			}
			else   //�߽���ʾ
			{
					*(arr + ((x - 1) * H_num) + y - 1) = DL_Num(x, y, arr1);	
			}
		}
	}

}