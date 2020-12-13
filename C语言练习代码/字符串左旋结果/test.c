#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include < string.h >
void ZX( char* arr,  int k, int num);
void ZAH_ZX(const char* arr1, int num1, const char* arr2, int num2);
int main()
{
	char arr1[100] = { '0' };
	char arr2[100] = { '0' };
	int num1 = 0;
	int num2 = 0;
	printf("请输入第一个字符串，以换行结束\n");
	while (scanf("%c", &arr1[num1]) && arr1[num1] != '\n')
	{
		num1++;
	}
	printf("请输入第二个字符串，以换行结束\n");
	while (scanf("%c", &arr2[num2]) && arr2[num2] != '\n')
	{
		num2++;
	}
	ZAH_ZX(arr1,num1,arr2,num2);
	return 0;
}
void ZAH_ZX(const char* arr1, int num1, const char* arr2, int num2)
{
	int k1 = 0;
	int k2 = 0;
	int i = 0;
	if (num1 == num2)
	{
		for (i = 0; i < num1; i++)
		{
			ZX(arr1, 1, num1);
			if (strcmp(arr1, arr2) == 0)
			{
				printf("左旋结果为=%d",i+1);
				break;
			}
		}
	}
	else
	{
		printf("二个字符串长度都不相等!!!");
	}

}
void ZX( char* arr, int k, int num)
{
	int i = 0;
	char arr2[100] = {'0'};
	for (i = k; i < num; i++)
	{
		arr2[i - k] = *(arr + i);
		//printf("%c", *(arr + i));
	}
	for (i = 0; i < k; i++)
	{
		arr2[num - k + i] = *(arr + i);
		//printf("%c", *(arr + i));
	}
	for (i = 0; i < num; i++)
	{
		*(arr + i) = arr2[i];
	}
}