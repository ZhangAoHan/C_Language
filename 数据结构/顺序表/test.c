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
		printf("   0：退出       1：删除数据(后删)   2:删除数据(前删)   \n");
		printf("   3:显示数据    4:后插数据          5：前插数据(1)     \n");
		printf("   6：前插数据(2)                    7：查找数据        \n");
		printf("   8：指定下标插入数据  9：指定下标删除数据             \n");
		printf("**********************************************          \n");
		scanf("%d",&sit);
		switch (sit)
		{
		case 0: run = 0; break;   //退出
		case 1:SeqListPopBack(&my_list); break;
		case 2:SeqListPopFront(&my_list); break;
		case 3:SeqListShow(&my_list); break;
		case 4:
			printf("请输入要插入的数据！(以-1结束)\n");
			while (scanf("%d", &data), data != -1)
			{
				SeqListPushBack(&my_list, data);
			}
			break;
		case 5:
			printf("请输入要插入的数据！(以-1结束)\n");
			while (scanf("%d", &data), data != -1) 
			{
				SeqListPushFront(&my_list, data);
			}
			break;
		case 6:
			printf("请输入要插入的数据！(以-1结束)\n");
			i = 0;
			while (scanf("%d", &data2[i]), data2[i] != -1)
			{
				i++;
			}
			SeqListPushFront2(&my_list, data2,i);
			break;
		case 7:
			printf("请输入要查找的数据！\n");
			scanf("%d", &i);
			SeqListFind(&my_list,i);
			break;
		case 8:
			printf("请输入要增加的数据！\n");
			scanf("%d", &i);
			printf("请输入要增加位置的下标！\n");
			scanf("%d", &data);
			SeqListInsert(&my_list, data, i);
		break;
		case 9:
			printf("请输入要删除位置的下标！\n");
			scanf("%d", &data);
			SeqListErase(&my_list, data);
			break;
		default: printf("输入错误！请根据提示重新输入！\n"); break; //输入错误提示
		}
		system("pause");
		system("cls");
	} while (run);
	return 0;
}

