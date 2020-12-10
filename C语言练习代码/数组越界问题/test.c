#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
   
    int arr[] = { 1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    for (i = 9; i >= -3; i--)  //64位编译器  i的地址为arr[end]+3
    {
        arr[i] = 9;
        printf("hello bit\n");
    }
    return 0;
}