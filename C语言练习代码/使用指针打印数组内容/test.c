#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//ʹ��ָ���ӡ��������
void sz_printf(int* arr, int num);
int main()
{
	int num = 0;  //�����ַ���������
	int arr[200] = {0};
	printf("������һά����\n");
	printf("��������һ��������಻����200����\n");
	while (scanf("%d",&arr[num]) && getchar() != '\n')  //��ȡ�����int������
	{
		num++;
	}

	sz_printf(arr,num + 1);
}

void sz_printf(int *arr,int num)
{
	int i = 0;
	while ( num --)
	{
		printf("%d ",*(arr ++));
	}
}