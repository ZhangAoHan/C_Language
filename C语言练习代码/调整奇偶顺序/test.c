#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//����һ���������飬ʵ��һ��������
//
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//
//����ż��λ������ĺ�벿�֡�
void Sz(int* arr, int num);
int main()
{
	int num = 0;  //�����ַ���������
	int arr[200] = { 0 };
	int i = 0;
	printf("������һά����\n");
	printf("��������һ��������಻����200����\n");
	while (scanf("%d", &arr[num]) && getchar() != '\n')  //��ȡ�����int������
	{
		num++;
	}
	Sz(arr, num );
	for (i = 0; i <= num; i++)
	{
		printf("%d ",arr[i]);
	}
}

void Sz(int* arr, int num)  //������ż˳��
{
	int arr1[200] = {0};
	int* arr2 = arr;
	int i = 0;  
	int j = num ; //ż����ĩβ���
	int k = 0;  //������ͷ���
	while (i <= num)
	{
		if (*arr2 % 2 == 0) //ż��  �����
		{
			arr1[j] = *arr2;
			arr2++;
			j--;
		}
		else
		{
			arr1[k] = *arr2;
			arr2++;
			k++;
		}
		i++;
	}
	for (i = 0; i <= num; i++)
	{
		*(arr + i) = arr1[i];
	}
}