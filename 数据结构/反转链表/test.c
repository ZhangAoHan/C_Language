#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct ListNode
{
	SLTDateType data;
	struct ListNode* next;
}ListNode;
void MyListCreat(ListNode** list);//创建单链表;
void ListShow(ListNode* list);  //显示链表
ListNode* reverseList(ListNode* head);
ListNode* FindKthToTail(ListNode* pListHead, int k);
int main()
{
	ListNode* my_list;   //my_list统领整个链表
	MyListCreat(&my_list); //初始创建一个链表（1-10），方便测试
	ListShow(my_list);
	//my_list = reverseList(my_list);
	//ListShow(my_list);
	ListNode* p = FindKthToTail(my_list, 10);
	printf("%d", p->data);
	return 0;
}
//1 2 3 4 5 NULL  5 4 3 2 1 NULL
//
//迭代法（双指针，使每个节点的next指向前一个指针）
// ListNode* reverseList( ListNode* head) {
//	 ListNode* p = NULL;
//	p = head->next;
//	//将第一个节点的next设置为空
//	head->next = NULL;
//	while (p != NULL)
//	{
//		 ListNode* p1 = NULL;
//		p1 = head;//保存上一节点的地址
//		head = p;
//		p = p->next;
//		head->next = p1;
//	}
//	return head;
//}
//递归法 使每个节点的next指向前一个指针
//1 2 3 4 5 6 7 8 9 10
//
ListNode* reverseList(ListNode* head) {
	if (head->next == NULL || head == NULL)
	{
		return head; //如果链表只有一个节点或递归到最后一个节点，返回此节点的地址
	}
	else//处于中间节点
	{
		ListNode* p = reverseList(head->next); //接收下一层递归传回来的地址(返回下一节点的地址)
		head->next->next= head;//下一节点指向此节点
		head->next = NULL;//必须将次节点的next置NULL，否则递归无法回到上一节点
		return p;  //始终返回最后节点地址（最后节点变为头结点）
	}
}
void MyListCreat(ListNode** list) //创建单链表
{
	//创建第一个节点
	*list = (ListNode*)malloc(sizeof(ListNode)); //对&MyList进行赋值（开辟空间）
	//对MyList->data进行赋值
	(*list)->data = 1;//第一个节点的data值
	ListNode* p = *list; //p初始代表第一个节点
	for (int i = 2; i <= 10; i++) //一个10个节点，创建后9个节点
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode)); //一个节点一个节点的开辟
		//开辟完节点：对该节点的data进行赋值，同时将该节点的地址赋给上一节点的next处，并将该节点的next值先赋为空（空指针为单链表的结束标志）
		s->data = i;//对该节点的data进行赋值
		s->next = NULL;//将该节点的next值先赋为空（空指针为单链表的结束标志）
		//将该节点的地址赋给上一节点的next处
		//需要一个中间指针变量p(p始终代表上一节点)
		p->next = s; //将第i个节点的地址赋给第i-1个节点的next处
		//此时必须对p进行更新，即此时p应代表第i个节点（否则单链接的第一个节点将直接指向最后一个节点）
		p = s;//对p进行更新（即将第i个节点的地址赋值给p）
	}
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

//输出一个链表的第k个节点
 ListNode* FindKthToTail( ListNode* pListHead, int k) {
	// write code here
	 ListNode* p = pListHead;
	 while (k > 0)
	 {
		 if (pListHead != NULL)
		 {
			 pListHead = pListHead->next;
			 k--;
		 }
		 else
		 {
			 return NULL; //返回倒数k个节点，但链表中没有k个节点，返回NULL
		 }
	 }
	 while (pListHead != NULL)
	 {
		 p = p->next;
		 pListHead = pListHead->next;
	 }
	 return p;
}