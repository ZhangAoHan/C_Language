#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void sz_init(int* num, int len);  //�����ʼ��
void sz_print(int* num, int len);  //��ӡ����
void sz_reverse(int* num, int len); //�������
int main()
{
	int arr[10] = {1,2,3,5,7,8,9,6,4,10};
	sz_reverse(arr,10);//�������
	printf("���������ӡ");
	sz_print(arr, 10);//��ӡ����
	printf("\n");
	printf("�����ʼ����ӡ");
	sz_init(arr,10);//�����ʼ��
	sz_print(arr,10);//��ӡ����
	return 0;
}

void sz_init(int *num, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		*num = 0;
		num++;
	}
}

void sz_print(int *num, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ",*num);
		num++;
	}
}
void sz_reverse(int* num, int len) //�ݹ��������
{
	int d = 0; //�м����
	if (len / 2 > 0)
	{
		d = *num;
		*num = *(num+len-1);
		*(num + len-1) = d;
		sz_reverse(num+1,len-2);
	}
}