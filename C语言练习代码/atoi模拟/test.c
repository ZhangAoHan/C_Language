#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int my_atoi(const char* string);
int main()
{
	char a[] = "av-1524b23";
	char b[] = "a125-321s";
	char c[] = "+125s23";
	printf("�����ַ���1��%s\nת�����Ϊ��%d\n", a,my_atoi(a));
	printf("�����ַ���2��%s\nת�����Ϊ��%d\n", b, my_atoi(b));
	printf("�����ַ���3��%s\nת�����Ϊ��%d\n", c, my_atoi(b));
	return 0;
}

int my_atoi(const char *string)//�������ַ���ת��Ϊ���ͣ�����λ��������ֽ����ţ������пո�
{
	int sit = 0;//����λ  1Ϊ��  -1Ϊ��
	int rest = 0;//���
	do
	{
		if (*string - '0' <= 9 && *string - '0' >= 0) //����0-9�ڵ���ֵ
		{
			if (sit == 0) //��һ���������֣�����ȡ����λ
			{
				if (*(string - 1) == '-')
				{
					sit = -1; //����λΪ��
				}
				else
				{
					sit = 1; //����λΪ��
				}
			}
			//��ȡ���
			rest = rest * 10 + (*string - '0');
		}
		else
		{
			//�ַ����У�����ֱ�Ӳ������κη������ַ�������ֻ����ǰһ�������ַ�
			if (sit != 0 || *string == '\n') //û���������ֲ���sit��Ϊ0������Ϊ������ȡ�Ѿ�����
			{
				return rest * sit;
			}
		}
		string++;
	} while (1);
}