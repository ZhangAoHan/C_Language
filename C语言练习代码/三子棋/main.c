#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//������
//���� 3*3�������ϣ������Է�9��Ԫ�أ�
// A B������Ԫ�أ��������ã�����������Ԫ�غ�ÿ��ֻ���ƶ�һ������Ԫ�أ����Ҳ����ƶ��Է�Ԫ��
// ʤ������������Ԫ���ų�һ�� Ϊʤ



void Init_display(void);//��ʼ��ʾ����
int Scan(int a, int b, int c, int d, int* arr1, int* arr2, int sit);//����������ӻ��ƶ��Ƿ����
void Game_hint(int a);
void QP_display(char* arr, int* arr1, int* arr2); //������ʾ����(AB����λ��)
void QP_Init(void); //���̳�ʼ��
int Victory_Judgment(void);  //�ж��Ƿ�ʤ�����ƶ����ڲŵ��ã�
void QZ_Init(void); //����λ�ó�ʼ��

int arr_A[3][2] = { {0,0},{0,0},{0,0} }; //���ӳ�ʼ��
int arr_B[3][2] = { {0,0},{0,0},{0,0} };
char arr[4][4] = { {'0','1','2','3' },{'1','*','*','*' },{'2','*','*','*' },{'3','*','*','*' } };
int main()
{
	int sit = 1; //����ģʽ���ƶ�ģʽ��1-6Ϊ����ģʽ 7Ϊ�ƶ�ģʽ��
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int Legal = 0; //�Ϸ���־λ
	int i = 0;
	Init_display(); //��ʼ����ʾ
	QP_display(arr, arr_A, arr_B); //ˢ������
	do
	{
			if (sit < 7) //����ģʽ
			{
				if (sit % 2 == 1) //A����
				{
					Game_hint(2); //��ʾ��Ϣ
				}
				else //B����
				{
					Game_hint(3); //��ʾ��Ϣ
				}
				scanf("%d %d",&c,&d); //��������
				Legal = Scan(0, 0, c, d, arr_A, arr_B, 1); //����ģʽ���
				if (Legal)  //����Ϸ�
				{
					if (sit % 2 == 1)//A					//����Ϸ� �����괢��
					{
						arr_A[sit / 2][0] = c;
						arr_A[sit / 2][1] = d;
					}
					else
					{
						if (sit >= 2) //�������룬�϶���������������ϴ����Ϊ�ˣ��������棩
						{
							arr_B[sit / 2 - 1][0] = c;
							arr_B[sit / 2 - 1][1] = d;
						}
					}

					QP_display(arr, arr_A, arr_B); //ˢ������
					sit++;
					if (sit > 4) //���µ���������ʱ �������������Ƿ�ﵽʤ������
					{
						if (Victory_Judgment() == 1) //Aʤ��
						{
							Game_hint(6);
							printf("**********�Ƿ����棿**********");
							printf("*********�ǣ�1 ��0 *********\n");
							scanf("%d", &i);
							if (i)
							{
								QP_Init();
								QZ_Init();
								Init_display(); //��ʼ����ʾ
								sit = 1; //����ģʽ���ƶ�ģʽ��1-6Ϊ����ģʽ 7Ϊ�ƶ�ģʽ��
								Legal = 0; //�Ϸ���־λ
							}
							else
							{
								break;
							}
						}
						if (Victory_Judgment() == 2) //Bʤ��
						{
							Game_hint(7);
							printf("**********�Ƿ����棿**********");
							printf("*********�ǣ�1 ��0 *********\n");
							scanf("%d", &i);
							if (i)
							{
								QP_Init();
								QZ_Init();
								Init_display(); //��ʼ����ʾ
								sit = 1; //����ģʽ���ƶ�ģʽ��1-6Ϊ����ģʽ 7Ϊ�ƶ�ģʽ��
								Legal = 0; //�Ϸ���־λ
							}
							else
							{
								break;
							}
						}
					}
				}
			}
			else  //�����ƶ�ģʽ
			{
				if (sit == 7) //A�ƶ�
				{
					
					Game_hint(4); //��ʾ��Ϣ
				}
				else    //B�ƶ�
				{
					Game_hint(5); //��ʾ��Ϣ
				}
				scanf("%d %d %d %d", &a, &b,&c, &d); //��������
				Legal = Scan(a, b, c, d, arr_A, arr_B, 0); //����ģʽ���
				if (Legal)  //����Ϸ�
				{
					//�滻����
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
					QP_display(arr, arr_A, arr_B); //ˢ������
					if (sit == 7)
					{
						sit = 8;
					}
					else
					{
						sit = 7;
					}
				}
				// �ж��Ƿ�����ʤ��
				if (Victory_Judgment() == 1) //Aʤ��
				{
					Game_hint(6);
					printf("**********�Ƿ����棿**********");
					printf("*********�ǣ�1 ��0 *********\n");
					scanf("%d", &i);
					if (i)
					{
						QP_Init();
						QZ_Init();
						Init_display(); //��ʼ����ʾ
						sit = 1; //����ģʽ���ƶ�ģʽ��1-6Ϊ����ģʽ 7Ϊ�ƶ�ģʽ��
						Legal = 0; //�Ϸ���־λ
					}
					else
					{
						break; 
					}
				}
				else if (Victory_Judgment() == 2) //Bʤ��
				{
					Game_hint(7); 
					printf("**********�Ƿ����棿**********");
					printf("*********�ǣ�1 ��0 *********\n");
					scanf("%d", &i);
					if (i)
					{
						QP_Init();
						QZ_Init();
						Init_display(); //��ʼ����ʾ
						sit = 1; //����ģʽ���ƶ�ģʽ��1-6Ϊ����ģʽ 7Ϊ�ƶ�ģʽ��
						Legal = 0; //�Ϸ���־λ
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



//��ʼ��ʾ����
void Init_display(void)
{
	printf("/*********������**********/\n");
	printf("/*******A���ӣ�o**********/\n");
	printf("/*******B���ӣ�#**********/\n");
	printf("/***ǰ�������Ӽ��룺a b***/\n");
	printf("/**�ƶ����Ӽ��룺a b c d**/\n");
}
//��Ϸ������ʾ����
void Game_hint(int a)
{
	switch (a)
	{
	case 0:
		printf("���Ӳ��Ϸ�������������\n");
		break;
	case 1:
		printf("�����ƶ����Ϸ����������ƶ�\n");
		break;
	case 2:
		printf("��Aѡ������\n");
		break;
	case 3:
		printf("��Bѡ������\n");
		break;
	case 4:
		printf("��Aѡ���ƶ�����\n");
		break;
	case 5:
		printf("��Bѡ���ƶ�����\n");
		break;
	case 6:
		printf("Aѡ��ʤ����\n");
		break;
	case 7:
		printf("Bѡ��ʤ����\n");
		break;
	}
}

void QP_display(char* arr,int* arr1,int* arr2) //������ʾ����(AB����λ��)
//��������λ�ñ�Ϊ*   A����:o  B���ӣ�v
{
	int i = 0;
	int j = 0;
	//�ȳ�ʼ������
	QP_Init();
	for (i = 0; i < 3; i++) //������������µ�������
	{
		if (*(arr1 + 2 * i) != 0 && *(arr1 + 2 * i + 1) != 0) //A��������Ϸ�
		{
			*(arr + 4 * (*(arr1 + 2 * i)) + (*(arr1 + 2 * i + 1)) ) = 'o';
		}
		if (*(arr2 + 2 * i) != 0 && *(arr2 + 2 * i + 1) != 0) //A��������Ϸ�
		{
			*(arr + 4 * (*(arr2 + 2 * i)) + (*(arr2 + 2 * i + 1)) ) = 'v';
		}
	}
	//��ӡ����
	for (i = 0; i < 4; i++)
	{
		printf("%c %c %c %c\n",*(arr + 4 * i),*(arr + 4 * i + 1), *(arr + 4 * i + 2), *(arr + 4 * i + 3));
	}
}


int Scan(int a, int b, int c, int d,int *arr1,int *arr2,int sit)//��������ƶ��Ƿ���������ƶ����ֵ����ӣ�,�����Լ������Ӳ����ص� �Ϸ�����1 ���Ϸ�����0
// (a,b)���ӳ�ʼλ�ã�����ģʽ��Ϊ��0,0���� (c,d)Ϊ��������λ��   arr1��Aѡ������λ�ã������ƶ�δ��¼��  arr2��Bѡ������λ��  sit=1 ����ģʽ  sit=0�ƶ�ģʽ
{
	int i = 0;
	int j = 0;
	if (sit) //���ӺϷ��Լ���(�����������ӵ�λ���ص�)
	{
		if (c > 3 || c < 0 || d > 3 || d < 0) //���Ӳ��Ϸ�
		{
			Game_hint(0);
			return 0;
		}

	}
	else     //�ƶ��Ϸ��Լ���
	{
		if (a > 3 || a < 0 || b > 3 || b < 0 || c > 3 || c < 0 || d > 3 || d < 0) //���Ӳ��Ϸ�
		{
			Game_hint(0);
			return 0;
		}
			
		if (abs(c + d - a - b) != 1)  //�ƶ�����
		{
			Game_hint(1);
			return 0;
		}
			
	}
	// ����˴��������������Ƿ����������������ص���
	for (i = 0; i < 3; i++) //���������Ƿ�����������ص�
	{
		if (c == *(arr1 + 2 * i))
		{
			if (d == *(arr1 + 2 * i + 1)) //������A�����ص�
			{
				Game_hint(1);
				return 0;
			}
		}
		if (c == *(arr2 + 2 * i))
		{
			if (d == *(arr2 + 2 * i + 1)) //������B�����ص�
			{
				Game_hint(1);
				return 0;
			}
		}
	}
	return 1;  //�Ϸ�
}

void QP_Init(void) //���̳�ʼ��
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
void QZ_Init(void) //����λ�ó�ʼ��
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
int Victory_Judgment(void)  //ʤ���жϺ���(���ƶ�����������)   ����0��û��ʤ����  1��Aʤ��  2��Bʤ��
//Aʤ��������A��3ö�����ų�һ�� �� B�����ӱ�������Bû�п����ƶ������ӣ�
{
	int i = 0;
	/****************************
	              ���A B�Ƿ��ų�ֱ��
	***************************************************/
	//�ų�һ��ֱ�ߣ� ��A����ö����Ϊ�� ����1��x1,y1��  ����2(x2,y2)  ����3(x3,y3)
	//���A����ö������һ��ֱ���ϣ�һ�У�x��ͬ�� �� һ��(y��ͬ) �� �Խ��ߣ�2�������
	if ((arr_A[0][0] == arr_A[1][0]) && (arr_A[0][0] == arr_A[2][0]) && (arr_A[1][0] == arr_A[2][0])) //һ��
	{
		printf("A�����ų�һ��\n");
		return 1;
	}
	else if((arr_A[0][1] == arr_A[1][1]) && (arr_A[0][1] == arr_A[2][1]) && (arr_A[1][1] == arr_A[2][1]))
	{
		printf("A�����ų�һ��\n");
		return 1;
	}
	else if ((arr_A[0][0] == arr_A[0][1]) && (arr_A[1][0] == arr_A[1][1]) && (arr_A[2][0] == arr_A[2][1]))
	{
		if ((arr_A[0][0] != 0) && (arr_A[1][0] != 0) && (arr_A[2][0] != 0))
		{
			printf("A�����ųɶԽ���\n");
			return 1;
		}
	}

	if ((arr_B[0][0] == arr_B[1][0]) && (arr_B[0][0] == arr_B[2][0]) && (arr_B[1][0] == arr_B[2][0])) //һ��
	{
		printf("B�����ų�һ��\n");
		return 2;
	}
	else if ((arr_B[0][1] == arr_B[1][1]) && (arr_B[0][1] == arr_B[2][1]) && (arr_B[1][1] == arr_B[2][1]))
	{
		printf("B�����ų�һ��\n");
		return 2;
	}
	else if ((arr_B[0][0] == arr_B[0][1]) && (arr_B[1][0] == arr_B[1][1]) && (arr_B[2][0] == arr_B[2][1]))
	{
		if ((arr_B[0][0] != 0) && (arr_B[1][0] != 0) && (arr_B[2][0] != 0))
		{
			printf("B�����ųɶԽ���\n");
			return 2;
		}
	}
	return 0; //û����ʤ��
}

