#define _CRT_SECURE_NO_WARNINGS 1
//��һ���ַ���str�����ݵߵ��������������str�ĳ��Ȳ�����100���ַ���
#include <stdio.h>
void DX_str(char* arr, int num);
int main()
{
	char arr[100] = { '0' };
	int num = 0;
	while (scanf("%c",&arr[num]) && arr[num] != '\n') ////��ȡ�����char������
	{
		num++;
	}
	DX_str(arr,num);
}
void DX_str(char *arr,int num)
{
	while (num --)
	{
		printf("%c",*(arr + num));
	}
}