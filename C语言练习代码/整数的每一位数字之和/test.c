#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
int DigitSum(int num, int sit); //����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
int main()
{
	int num;   //�����ַ������ȱ���С��100
	int sums = 0;
	scanf("%d",&num); //ȡ���ַ����׵�ַ
	printf("�ݹ���ͽ��Ϊ:  ",sums);
	sums = DigitSum(num, 1);
	printf(" = %d \r\n ",sums);
	printf("�ǵݹ���ͽ��Ϊ:  ",sums);
	sums = DigitSum(num, 0);
	printf(" = %d \n ", sums);
	return 0;
}
int DigitSum(int num, int sit)
{
	if (sit) //�ݹ�ķ�ʽ
	{
		if (num / 10 > 0)  //������ȡ+���
		{
			printf(" %d +", num % 10);
			return DigitSum(num/10,1) + num % 10;
			
		}
		else  
		{
			printf(" %d", num % 10);
			return num % 10;
		}
	}
	else  //�ǵݹ�ķ�ʽ
	{
		int sum = 0;
		while (num / 10 > 0)
		{
			printf(" %d +", num % 10);  //������ȡ+���
			sum = sum + num % 10;
			num = num / 10;
		}
		printf(" %d", num % 10);  //��ȡ���һλ
		sum = sum + num % 10;
		return sum;
	}
}