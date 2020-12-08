#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//输入一行 输出一列
int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)  //输入结尾返回EOF
    {
        printf("%d\n", 1<<a);
    }
    return 0;
}

