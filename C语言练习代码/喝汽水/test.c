#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >

int Qs(int a);  //a:Ǯ��
int main()
{
	printf("%dԪǮ���Ժ�%dƿ��ˮ",20,Qs(20));
	return 0;
}
int Qs(int a)  //a:Ǯ��
{
	int b = 0;//ƿ������
	int num = 0; //���Ժȵ���ˮ����
	while (a > 0)
	{
		num++;
		a--;
		b++;
		if (b == 2) //2��ƿ�� �൱��1ԪǮ
		{
			a++;
			b = 0;
		}
	}
	return num;
}