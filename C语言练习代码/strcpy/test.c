#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
char* my_strcpy(char* arr2, const char* arr1);
int main()
{
	char arr1[200] = { '0' };
	char arr2[200] = { '0' };
	int i = 0;
	int j = 0;
	printf("请输入一个字符串\n");
	while (scanf("%c", &arr1[i]) && arr1[i] != '\n')//将键入的字符串存放到arr中
	{
		i++;
	}
	printf("共键入%d个字符\n",i);
	printf("粘贴前，arr2的前%d个字符为：\n", i);
	for (j = 0; j <= i; j++)
	{
		printf("%c", arr2[j]);
	}
	printf("\n粘贴后，arr2的前%d个字符为：\n", i);
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