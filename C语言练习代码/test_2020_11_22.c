
//#include <stdio.h>
////��ӡ���꣨�ܱ�4���������ܱ�100������
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
//��ӡ���������ܱ���1������֮�����������
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = i-1;
//		for (j = i-1; j > 1; j--)
//		{
//			if (i % j == 0)//������Ϊ����
//			{
//				break;
//			}
//		}
//		if (j == 1) //������Ϊ����
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}
//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;//����9���ֵĸ���
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			sum = sum + 1;
//		}
//	}
//	printf("һ����%d�������а���9��",sum);
//	return 0;
//}

////����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ����ӡ�����
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0;//���
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
//	printf("���Ϊ��%f", sum);
//	return 0;
//}
////��10 �����������ֵ
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	int max = 0;//�����
//	printf("������10������");
////������������С��10ʱ���ȴ�����. ������������10��ʱ��ֻȡǰ10��
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d",&arr[i]);
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("���Ϊ��%d", max);
//	return 0;
//}

//����Ļ�����9*9�˷��ھ���
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	printf("�˷��ھ���");
//	for (i = 1; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			sum = i * j;
//			printf("%d x %d = %d  ",i,j,sum);
//		}
//		printf("\n");//����
//	}
//	return 0;
//}
////��������Ϸ
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
//	a = a % 100;  //��֤a��0-100֮��
//	return a;
//}
//void Game_play(int i)
//{
//	if (i == 1) //����Ϸ
//	{
//		printf("******************************\n");
//		printf("**********��������Ϸ**********\n");
//		printf("********���ַ�Χ��0-100*******\n");
//		printf("******************************\n");
//	}
//	else if (i == 2)  //��ʾ���� //�´���
//	{
//
//		printf("���´��ˣ�\n");
//	}
//	else if(i == 3 )      //��С��
//	{
//		printf("����С�ˣ�\n");
//	}
//	
//	else       //��ʼѡ�����
//	{
//		printf("******************************\n");
//		printf("**********��������Ϸ**********\n");
//		printf("***********1:��ʼ��Ϸ*********\n");
//		printf("***********0:�˳���Ϸ*********\n");
//		printf("******************************\n");
//	}
//}
//void Game_plays(void) //��Ϸ������
//{
//	int p_set = 0;
//	int p_data = 0;
//	int num = randn_num(); //���������
//	Game_play(1);//������Ϸ
//	do  
//	{
//		p_set = 1;
//		printf("����������");
//		scanf("%d", &p_data);
//		if (p_data > num) //�´���
//		{
//			Game_play(2);
//		}
//		else if (p_data < num)//��С��
//		{
//			Game_play(3);
//		}
//		else
//		{
//			printf("������");
//			p_set = 0;
//		}
//	} while (p_set != 0);    //��Ϸ�ɹ����Ƴ�
//}
//int main()
//{
//	int num = randn_num();  //���������
//	int set = 1;
//	int data=0;
//	do
//	{
//		Game_play(5); //��ʼѡ�����  >3����������
//		scanf("%d", &data);
//		if (data == 1)//ѡ������Ϸ
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
//���ֲ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };//ģ������
int xb = -1;//�±�
void Find_num(int len,int num)
{
	int left = 0;
	int right = len;
	int Success = 0;
	do
	{
		int sit = (left + right) / 2;//Ѱ�������±�
		if (arr[sit] > num) //num�����
		{
			right = sit - 1;
		}
		else if (arr[sit] < num) //num���ұ�
		{
			left = sit + 1;
		}
		else //�Ѿ��ҵ�
		{
			xb = sit;
			Success = 1;
		}
		if ( left == right )
		{
			if (arr[sit] == num) //�������һ���жϣ���ֹ©��
			{
				xb = sit;
			}
			Success = 1;
		
		}
	} while (!Success);
}

int main()
{
	int len = sizeof(arr) / sizeof(arr[0]) - 1;//����±�
	printf("������һ����");
	int num = 0;
	scanf("%d",&num);
	Find_num(len, num);
	if (xb == -1)//û���ҵ�
	{
		printf("û���ҵ�");
	}
	else
	{
		printf("�±�Ϊ��%d", xb);
	}
	

	return 0;
}