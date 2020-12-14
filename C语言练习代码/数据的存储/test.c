
//#include < stdio.h >
//int main()
//{
//	int a = 0x11223344;
//	int b = 0x01020304;
//	return 0;
//}

//#include < stdio.h >
//int main()
//{
//	int a = 0x11223344;
//	char b = 0x01020;
//	int c = 0x11223344;
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1

#include < stdio.h >
int main()
{
	char a[100] = {'0'};
	int i=0;
	while(scanf("%c",&a[i]) && a[i] != ';')
	{
		
		printf("%c",a[i]);
		i++;
	}
	printf("%d",i);
	return 0;
}