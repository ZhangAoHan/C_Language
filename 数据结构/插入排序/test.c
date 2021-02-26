#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef int SLTDateType;
typedef struct ListNode
{
	SLTDateType data;
	struct ListNode* next;
}ListNode;
void ListShow(ListNode* list);
void MyListCreat(ListNode** list, int* arr, int length);
ListNode* insertionSortList(ListNode* head);
int main()
{
	int data[10] = { 10,8,6,1,2,4,9,7,5,5 };
	ListNode* my_list;   //my_list统领整个链表
	MyListCreat(&my_list, data, 10);
	ListShow(my_list);
	my_list = insertionSortList(my_list);
	ListShow(my_list);
	return 0;
}
ListNode* insertionSortList(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* p1 = head;  //p的前一个节点
	ListNode* p2 = NULL;  //插入位置的前一个节点
	ListNode* p = head->next; //取出待排节点
	while (p != NULL)
	{
		ListNode* pp = head;
		while (pp != p)
		{
			if (p->data < pp->data) //需要交换
			{
				break;
			}
			p2 = pp;
			pp = pp->next;
		}
		//找到待排的最终位置
		//按照地址交换二个节点
		if (p != pp) //自身和自身没有必要交换
		{
			//清除p节点的原位置
			p1->next = p->next;
			if (pp == head) //要和第一个节点互换
			{
				p->next = head;
				head = p;
			}
			else
			{
				p2->next = p;
				p->next = pp;
			}
		}
		p = p->next;
	}
	return head;
}
void ListShow(ListNode* list)  //显示链表
{
	ListNode* p = list;
	if (p == NULL)
	{
		printf("单链表已经被销毁，单链表不存在！");
	}
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void MyListCreat(ListNode** list,int *arr,int length) //创建单链表
{
	//创建第一个节点
	*list = (ListNode*)malloc(sizeof(ListNode)); //对&MyList进行赋值（开辟空间）
	//对MyList->data进行赋值
	(*list)->data = arr[0];//第一个节点的data值
	ListNode* p = *list; //p初始代表第一个节点
	for (int i = 2; i <= length; i++) //一个10个节点，创建后9个节点
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode)); //一个节点一个节点的开辟
		//开辟完节点：对该节点的data进行赋值，同时将该节点的地址赋给上一节点的next处，并将该节点的next值先赋为空（空指针为单链表的结束标志）
		s->data = arr[i - 1];//对该节点的data进行赋值
		s->next = NULL;//将该节点的next值先赋为空（空指针为单链表的结束标志）
		//将该节点的地址赋给上一节点的next处
		//需要一个中间指针变量p(p始终代表上一节点)
		p->next = s; //将第i个节点的地址赋给第i-1个节点的next处
		//此时必须对p进行更新，即此时p应代表第i个节点（否则单链接的第一个节点将直接指向最后一个节点）
		p = s;//对p进行更新（即将第i个节点的地址赋值给p）
	}
}