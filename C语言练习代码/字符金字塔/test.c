#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	char a = '0';
//	scanf("%c",&a);
//	printf("    %c    \n",a);
//	printf("   %c %c   \n",a,a);
//	printf("  %c %c %c  \n",a,a,a);
//	printf(" %c %c %c %c \n",a,a,a,a);
//	printf("%c %c %c %c %c\n",a,a,a,a,a);
//	return 0;
//}
#include <stdio.h>
int main()
{
	char a[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
	int i = 12;
	for (i = 0; i < 12; i++)
	{
		printf("%c", a[i]);
	}
	return 0;
}