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
    int* p = malloc(sizeof(int) * (ASize + 4));  //���ٿռ�(K<10000��������λ��<=ASize+4)
    int sum = 0;
    int i = 0;
    int data = 0; //��ת����ʱ���м����
    *returnSize = 0; //��¼�����λ��
    for (i = 0; i < ASize + 4; i++)  //�������λ�� Ϊѭ������������ K�ϴ�ʱ�����
    {
        if (i < ASize)
        {
            if (*(A + ASize - 1 - i) + K % 10 >= 10)  //��λ
            {
                *(p + (*returnSize)) = (*(A + ASize - 1 - i) + K % 10) % 10;
                K = K / 10 + 1; //��λ
                (*returnSize)++;
            }
            else  //����λ ֱ�Ӹ�ֵ
            {
                *(p + (*returnSize)) = *(A + ASize - 1 - i) + K % 10;
                K = K / 10;  //����λ
                (*returnSize)++;
            }
        }
        else //��ʱ �ж�K����û�в���
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
    //��ת�������
    for (i = 0; i < (*returnSize) / 2; i++)
    {
        data = *(p + i);
        *(p + i) = *(p + (*returnSize) - 1 - i);
        *(p + (*returnSize) - 1 - i) = data;
    }
    return p;
}