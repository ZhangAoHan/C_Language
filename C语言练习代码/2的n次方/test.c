#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int JS(int n);
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d\n%d", &a,&b);
    printf("%d\n%d",JS(a), JS(b));
    return 0;
}

//int JS(int n)
//{
//    int i = 0;
//    int res = 1;
//    for (i = 0; i < 32; i++)
//    {
//        if ((n & 1) == 1)
//        {
//            res = res * pow(2,pow(2,i));
//        }
//        n = n >> 1;
//    }
//    return res;
//}
int JS(int n)
{
    int i = 0;
    int a = 1;
    int res = 1;
    for (i = 0; i < 32; i++)
    {
        if ((a & n) != 0)
        {
            res = res * pow(2, (a & n));
        }
        a = a << 1;
    } 
    return res;
}