//��10 �����������ֵ
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int arr[10] = {0};
	int i = 0;
	int max = 0;//�����
	printf("������10������\n");
//������������С��10ʱ���ȴ�����. ������������10��ʱ��ֻȡǰ10��
	for (i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("���Ϊ��%d", max);
	return 0;
}