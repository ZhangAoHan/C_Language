#define _CRT_SECURE_NO_WARNINGS 1

//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
#include <stdio.h>
int Gs(int a, int b);
int main()
{
	int a = 0;
	int b = 0;
	printf("�����������\n");
	scanf("%d %d",&a,&b);
	printf("���� %d ����ͬ��λ",Gs(a,b));
	return 0;
}
//��λ���  ��ͬΪ0 ��ͬΪ1��������1�ĸ���
int Gs(int a,int b)
{
	int i = 0;
	int sum = 0;
	int c = a^ b;
	for(i = 0; i < 32; i++)
	{
		sum += c & 1;
		c =c >> 1;
	}
	return sum;
}