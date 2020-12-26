#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	char a[20] = {'0'};
	int i = 0;
	while (scanf("%c", &a[i]) && a[i] != '\n')
	{
		i++;
	}
	printf("year=");
	for (i = 0; i < 4; i++)
	{
		printf("%c",a[i]);
	}
	printf("\nmonth=");
	for (i = 0; i < 2; i++)
	{
		printf("%c", a[i+4]);
	}
	printf("\ndate=");
	for (i = 0; i < 2; i++)
	{
		printf("%c", a[i + 6]);
	}
	return 0;
}