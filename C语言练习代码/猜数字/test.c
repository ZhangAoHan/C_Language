//��������Ϸ
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randn_num(void)
{
	int a = 0;
	srand((unsigned int)time(NULL));
	a = rand();
	a = a % 100;  //��֤a��0-100֮��
	return a;
}
void Game_play(int i)
{
	if (i == 1) //����Ϸ
	{
		printf("******************************\n");
		printf("**********��������Ϸ**********\n");
		printf("********���ַ�Χ��0-100*******\n");
		printf("******************************\n");
	}
	else if (i == 2)  //��ʾ���� //�´���
	{

		printf("���´��ˣ�\n");
	}
	else if (i == 3)      //��С��
	{
		printf("����С�ˣ�\n");
	}

	else       //��ʼѡ�����
	{
		printf("******************************\n");
		printf("**********��������Ϸ**********\n");
		printf("***********1:��ʼ��Ϸ*********\n");
		printf("***********0:�˳���Ϸ*********\n");
		printf("******************************\n");
	}
}
void Game_plays(void) //��Ϸ������
{
	int p_set = 0;
	int p_data = 0;
	int num = randn_num(); //���������
	Game_play(1);//������Ϸ
	do
	{
		p_set = 1;
		printf("����������");
		scanf("%d", &p_data);
		if (p_data > num) //�´���
		{
			Game_play(2);
		}
		else if (p_data < num)//��С��
		{
			Game_play(3);
		}
		else
		{
			printf("������");
			p_set = 0;
		}
	} while (p_set != 0);    //��Ϸ�ɹ����Ƴ�
}
int main()
{
	int num = randn_num();  //���������
	int set = 1;
	int data = 0;
	do
	{
		Game_play(5); //��ʼѡ�����  >3����������
		scanf("%d", &data);
		if (data == 1)//ѡ������Ϸ
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
