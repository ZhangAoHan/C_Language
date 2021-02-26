  #define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

int main()
{
	int sit = 0;
	int run = 1;
	int data = 0;
	int i = 0;
	int data2[SEQ_SIZE] = {0};
	SeqList my_list;
	SeqListInit(&my_list);
	do
	{
		printf("**********************************************          \n");
		printf("   0���˳�       1��ɾ������(��ɾ)   2:ɾ������(ǰɾ)   \n");
		printf("   3:��ʾ����    4:�������          5��ǰ������(1)     \n");
		printf("   6��ǰ������(2)                    7����������        \n");
		printf("   8��ָ���±��������  9��ָ���±�ɾ������             \n");
		printf("**********************************************          \n");
		scanf("%d",&sit);
		switch (sit)
		{
		case 0: run = 0; break;   //�˳�
		case 1:SeqListPopBack(&my_list); break;
		case 2:SeqListPopFront(&my_list); break;
		case 3:SeqListShow(&my_list); break;
		case 4:
			printf("������Ҫ��������ݣ�(��-1����)\n");
			while (scanf("%d", &data), data != -1)
			{
				SeqListPushBack(&my_list, data);
			}
			break;
		case 5:
			printf("������Ҫ��������ݣ�(��-1����)\n");
			while (scanf("%d", &data), data != -1) 
			{
				SeqListPushFront(&my_list, data);
			}
			break;
		case 6:
			printf("������Ҫ��������ݣ�(��-1����)\n");
			i = 0;
			while (scanf("%d", &data2[i]), data2[i] != -1)
			{
				i++;
			}
			SeqListPushFront2(&my_list, data2,i);
			break;
		case 7:
			printf("������Ҫ���ҵ����ݣ�\n");
			scanf("%d", &i);
			SeqListFind(&my_list,i);
			break;
		case 8:
			printf("������Ҫ���ӵ����ݣ�\n");
			scanf("%d", &i);
			printf("������Ҫ����λ�õ��±꣡\n");
			scanf("%d", &data);
			SeqListInsert(&my_list, data, i);
		break;
		case 9:
			printf("������Ҫɾ��λ�õ��±꣡\n");
			scanf("%d", &data);
			SeqListErase(&my_list, data);
			break;
		default: printf("��������������ʾ�������룡\n"); break; //���������ʾ
		}
		system("pause");
		system("cls");
	} while (run);
	return 0;
}

