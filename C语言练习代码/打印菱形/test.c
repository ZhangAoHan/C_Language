#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < math.h >
//��ӡ����
// 1 8  3 9  5 10  *����=13 - |�к�-7|*2 ���з�ʽΪ���м������߷�
int main()
{
	int i = 0;
	int j = 0;
	int num = 0; //��i��*������
	for (i = 1; i <= 13; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			num = 13 - abs(i - 7) * 2;  //��i��*������(����)  (13-num)/2
			if (j <= (13 - num) / 2 || j > 7 + num / 2)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}