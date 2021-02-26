#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void rotate(int* nums, int numsSize, int k);
int main()
{
    //int A[1] = {-1};
    //int K = 1;
    //rotate(A,1,K);

    //for (int i = 0; i < 1; i++)
    //{
    //    printf("%d ", A[i]);
    //}
    int A[7] = { 1,2,3,4,5,6,7};
    int K = 3;
    rotate(A, 7, K);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}
////方法1              //leetcode结果------通过
////首先建立一个数组a，用于存放后K个元素
////然后将前numsSize-K个元素分别右移K个位置
////最后将数组a中的元素放到前k个位置
void rotate(int* nums, int numsSize, int k) {
    int i = 0;
    if (numsSize - k <= 0)//特殊情况 
    {
        k = k % numsSize;
    }
    int* Data = malloc(sizeof(int) * numsSize);
    //提取后K个元素
    for ( i = 0; i < k; i++)
    {
        *(Data + i) = *(nums + numsSize - k + i);
    }
    //移动前numsSize-K个元素
    for ( i = 0; i < numsSize - k; i++)
    {
        *(nums + numsSize - 1 - i) = *(nums + numsSize - 1 - k -i);
    }
    //数组组装
    for (i = 0; i < k; i++)
    {
        *(nums + i) = *(Data + i);
    }
}
////方法2 一位一位右移（每次仅右移一个元素）  //leetcode结果------运行超出时间限制
//void rotate(int* nums, int numsSize, int k) {
//    int i = 0;
//    int j = 0;
//    int data = 0; //中间变量
//    for (i = 0; i < k; i++)
//    {
//        data = *(nums + numsSize - 1);//取出最后一个元素
//        for (j = 0; j < numsSize - 1; j++)
//        {
//            *(nums + numsSize - 1 - j) = *(nums + numsSize - 1 - j - 1);//从后往前替换
//        }
//        *nums = data; //把最后一个元素放到起始位置
//    }
//}


