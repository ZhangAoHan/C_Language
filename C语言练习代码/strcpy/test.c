#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
char* my_strcpy(char* arr2, const char* arr1);
int main()
{
	char arr1[200] = { '0' };
	char arr2[200] = { '0' };
	int i = 0;
	int j = 0;
	printf("������һ���ַ���\n");
	while (scanf("%c", &arr1[i]) && arr1[i] != '\n')//��������ַ�����ŵ�arr��
	{
		i++;
	}
	printf("������%d���ַ�\n",i);
	printf("ճ��ǰ��arr2��ǰ%d���ַ�Ϊ��\n", i);
	for (j = 0; j <= i; j++)
	{
		printf("%c", arr2[j]);
	}
	printf("\nճ����arr2��ǰ%d���ַ�Ϊ��\n", i);
	my_strcpy(arr2,arr1);
	for (j = 0; j <= i; j++)
	{
		printf("%c",arr2[j]);
	}
}
char* my_strcpy(char *arr2,const char *arr1)
{
	while (*( arr2 ++) = *( arr1 ++));
	return arr2;
}