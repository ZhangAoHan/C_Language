#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//����һ�� ���һ��
int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)  //�����β����EOF
    {
        printf("%d\n", 1<<a);
    }
    return 0;
}

