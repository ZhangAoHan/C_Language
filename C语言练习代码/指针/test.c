//#define _CRT_SECURE_NO_WARNINGS 1
//#include < stdio.h >
//int main()
//{
//	int arr[10] = {0};
//	int* p = &arr;
//	printf("%d\n",sizeof(arr)/sizeof(arr[0]));
//	printf("%p\n",&arr[0]);
//	printf("%p\n", arr);
//	printf("%p\n", p);
//	printf("%p\n",&arr[1]);
//	printf("%p\n", arr + 1);
//	printf("%p\n", p+1);
//	printf("%p\n", &arr + 1);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
void SZZZ(int (*p)[]);
int main()
{
	int arr[3] = { 1,2,3 };
	int (* p)[3] = &arr;
	int* p1 = &arr;
	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	SZZZ(&arr);
	return 0;
}
void SZZZ(int (*p)[])
{
	printf("%d\n", (*p)[0]);
	printf("%d\n", (*p)[1]);
}