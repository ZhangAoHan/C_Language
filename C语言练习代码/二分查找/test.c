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