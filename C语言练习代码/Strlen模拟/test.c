#define _CRT_SECURE_NO_WARNINGS 1
//strlen ģ��
#include <stdio.h>



int main()
{
	char arr[] = "abscjdksuslaj asdl";
	int num = 0;//�ַ�������

	num = Str_len(arr);
	printf("%d",num);
	return 0;
}
int Str_len(const char *arr)
{
	char* p = arr;
	while (*(p++) != '\0');
	return p - arr - 1;
}
//int Str_len(char *str,int sit); //strlen
//int main()
//{
//	char str[100];   //�����ַ������ȱ���С��100
//	int len = 0;
//	scanf("%s",str); //ȡ���ַ����׵�ַ
//	len = Str_len(str,1);
//	printf("�ݹ������Ϊ�� %d\n",len);
//	len = Str_len(str, 0);
//	printf("ѭ�������Ϊ�� %d\n", len);
//	return 0;
//}
//
//int Str_len(char* strs,int sit)
//{
//	if (sit)  //�ݹ����
//	{
//		if (*strs == '\0')
//		{
//			return 0;
//		}
//		else
//		{
//			return 1 + Str_len(strs + 1,1);
//		}
//	}
//	else  //�ǵݹ����
//	{
//		int len = 0;
//		while (*strs != '\0')
//		{
//			len++;
//			strs++;
//		}
//		return len;
//	}
//
//}




