#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < assert.h >
void YH(int a);
int main()
{ 
	int a;
	printf("������һ����a��a<200),����a���������\n");
	scanf("%d",&a);
	YH(a);
	return 0;
}
void YH(int a)
{
	int i = 0;
	int j = 0;
	int arr1[200] = { 1 }; //��ʾ����
	int arr[200] = { 1 }; //��һ�е�����
	arr1[0] = 1;
	arr1[1] = 1;
	arr[0] = 1;
	arr[1] = 1;
	for (i = 0; i < a; i++) //һ����ʾa��
	{
		if (i == 0) //��һ��
		{
			printf("1");
		}
		else if (i == 1) //�ڶ���
		{
			printf("1 1");
		}
		else  //
		{

			printf("1 ");
			for (j = 1; j <= i - 1; j++)  //��i+1�� ����ʾi+1����
			{
				printf("%d ",arr1[j - 1] + arr1[j]);
				arr[j] = arr1[j - 1] + arr1[j];
			}
			arr[i] = 1;
			printf("1");
			for (j = 0; j <= i; j++) //���ݵ���
			{
				arr1[j] = arr[j];
			}
		}
		printf("\n");
	}

}