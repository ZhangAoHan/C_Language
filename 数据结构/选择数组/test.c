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
////����1              //leetcode���------ͨ��
////���Ƚ���һ������a�����ڴ�ź�K��Ԫ��
////Ȼ��ǰnumsSize-K��Ԫ�طֱ�����K��λ��
////�������a�е�Ԫ�طŵ�ǰk��λ��
void rotate(int* nums, int numsSize, int k) {
    int i = 0;
    if (numsSize - k <= 0)//������� 
    {
        k = k % numsSize;
    }
    int* Data = malloc(sizeof(int) * numsSize);
    //��ȡ��K��Ԫ��
    for ( i = 0; i < k; i++)
    {
        *(Data + i) = *(nums + numsSize - k + i);
    }
    //�ƶ�ǰnumsSize-K��Ԫ��
    for ( i = 0; i < numsSize - k; i++)
    {
        *(nums + numsSize - 1 - i) = *(nums + numsSize - 1 - k -i);
    }
    //������װ
    for (i = 0; i < k; i++)
    {
        *(nums + i) = *(Data + i);
    }
}
////����2 һλһλ���ƣ�ÿ�ν�����һ��Ԫ�أ�  //leetcode���------���г���ʱ������
//void rotate(int* nums, int numsSize, int k) {
//    int i = 0;
//    int j = 0;
//    int data = 0; //�м����
//    for (i = 0; i < k; i++)
//    {
//        data = *(nums + numsSize - 1);//ȡ�����һ��Ԫ��
//        for (j = 0; j < numsSize - 1; j++)
//        {
//            *(nums + numsSize - 1 - j) = *(nums + numsSize - 1 - j - 1);//�Ӻ���ǰ�滻
//        }
//        *nums = data; //�����һ��Ԫ�طŵ���ʼλ��
//    }
//}


