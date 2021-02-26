#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize);
int main()
{
    int A[2] = {1, 2};
    int K = 100;
    int resws = 0;
    int* pp = addToArrayForm(A,2,K,&resws);

    for (int i = 0; i < resws; i++)
    {
        printf("%d ",pp[i]);
    }
        printf("\n%d ", resws);

    return 0;
}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int* p = malloc(sizeof(int) * (ASize + 4));  //开辟空间(K<10000，则结果的位数<=ASize+4)
    int sum = 0;
    int i = 0;
    int data = 0; //反转数组时的中间变量
    *returnSize = 0; //记录结果的位数
    for (i = 0; i < ASize + 4; i++)  //以输出的位数 为循环次数（否则当 K较大时会出错）
    {
        if (i < ASize)
        {
            if (*(A + ASize - 1 - i) + K % 10 >= 10)  //进位
            {
                *(p + (*returnSize)) = (*(A + ASize - 1 - i) + K % 10) % 10;
                K = K / 10 + 1; //进位
                (*returnSize)++;
            }
            else  //不进位 直接赋值
            {
                *(p + (*returnSize)) = *(A + ASize - 1 - i) + K % 10;
                K = K / 10;  //不进位
                (*returnSize)++;
            }
        }
        else //此时 判断K还有没有残余
        {
            if (K != 0)
            {
                *(p + (*returnSize)) = K % 10;
                K = K / 10;
                (*returnSize)++;
            }
            else
                break;
        }
    }
    //反转输出数组
    for (i = 0; i < (*returnSize) / 2; i++)
    {
        data = *(p + i);
        *(p + i) = *(p + (*returnSize) - 1 - i);
        *(p + (*returnSize) - 1 - i) = data;
    }
    return p;
}