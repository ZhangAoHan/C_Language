#define _CRT_SECURE_NO_WARNINGS 1
//ð������
#include <stdio.h>


int main()
{
	int arr[] = {1, 5, 3, 2, 9, 4, 6, 7, 8, 0}; //����10����
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int k = 0;
	//ð��������
	for (i = 1; i < len ; i++)
	{
		for (j = 0; j < len - i; j++) //��n�� ֻ�ñȽ�len-n��������
		{
			if (arr[j] > arr[j + 1])  //����ұ���С����ߣ�����λ��
			{
				k = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = k;
			}
		}
	}
	for (i = 0; i <= len - 1; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
