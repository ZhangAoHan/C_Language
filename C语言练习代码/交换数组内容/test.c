#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void sz_print(int* num, int len);  //��ӡ����
void sz_cxchange(int* num, int* num2, int len); //�������
int main()
{
	int arr[10] = {1,2,3,5,7,8,9,6,4,10};
	int arr1[10] = {6,8,7,5,1,2,3,9,4,10};
	printf("����1����ǰ��");
	sz_print(arr, 10);//��ӡ����
	printf("\n");
	printf("����2����ǰ��");
	sz_print(arr1, 10);//��ӡ����
	printf("\n");
	sz_cxchange(arr,arr1,10);//��ɽ���
	printf("����1������");
	sz_print(arr, 10);//��ӡ����
	printf("\n");
	printf("����2������");
	sz_print(arr1, 10);//��ӡ����
	return 0;
}
void sz_print(int* num, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *num);
		num++;
	}
}
void sz_cxchange(int* num, int *num2, int len) //�ݹ���ɽ�����������
{
	int d = 0; //�м����
	if (len > 0)
	{
		d = *num;
		*num = *num2;
		*num2 = d;
		sz_cxchange(num + 1,num2 + 1, len - 1);
	}
}