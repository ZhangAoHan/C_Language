#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct ListNode
{
	SLTDateType data;
	struct ListNode* next;
}ListNode;
void MyListCreat(ListNode** list);//����������;
void ListShow(ListNode* list);  //��ʾ����
ListNode* reverseList(ListNode* head);
ListNode* FindKthToTail(ListNode* pListHead, int k);
int main()
{
	ListNode* my_list;   //my_listͳ����������
	MyListCreat(&my_list); //��ʼ����һ������1-10�����������
	ListShow(my_list);
	//my_list = reverseList(my_list);
	//ListShow(my_list);
	ListNode* p = FindKthToTail(my_list, 10);
	printf("%d", p->data);
	return 0;
}
//1 2 3 4 5 NULL  5 4 3 2 1 NULL
//
//��������˫ָ�룬ʹÿ���ڵ��nextָ��ǰһ��ָ�룩
// ListNode* reverseList( ListNode* head) {
//	 ListNode* p = NULL;
//	p = head->next;
//	//����һ���ڵ��next����Ϊ��
//	head->next = NULL;
//	while (p != NULL)
//	{
//		 ListNode* p1 = NULL;
//		p1 = head;//������һ�ڵ�ĵ�ַ
//		head = p;
//		p = p->next;
//		head->next = p1;
//	}
//	return head;
//}
//�ݹ鷨 ʹÿ���ڵ��nextָ��ǰһ��ָ��
//1 2 3 4 5 6 7 8 9 10
//
ListNode* reverseList(ListNode* head) {
	if (head->next == NULL || head == NULL)
	{
		return head; //�������ֻ��һ���ڵ��ݹ鵽���һ���ڵ㣬���ش˽ڵ�ĵ�ַ
	}
	else//�����м�ڵ�
	{
		ListNode* p = reverseList(head->next); //������һ��ݹ鴫�����ĵ�ַ(������һ�ڵ�ĵ�ַ)
		head->next->next= head;//��һ�ڵ�ָ��˽ڵ�
		head->next = NULL;//���뽫�νڵ��next��NULL������ݹ��޷��ص���һ�ڵ�
		return p;  //ʼ�շ������ڵ��ַ�����ڵ��Ϊͷ��㣩
	}
}
void MyListCreat(ListNode** list) //����������
{
	//������һ���ڵ�
	*list = (ListNode*)malloc(sizeof(ListNode)); //��&MyList���и�ֵ�����ٿռ䣩
	//��MyList->data���и�ֵ
	(*list)->data = 1;//��һ���ڵ��dataֵ
	ListNode* p = *list; //p��ʼ�����һ���ڵ�
	for (int i = 2; i <= 10; i++) //һ��10���ڵ㣬������9���ڵ�
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode)); //һ���ڵ�һ���ڵ�Ŀ���
		//������ڵ㣺�Ըýڵ��data���и�ֵ��ͬʱ���ýڵ�ĵ�ַ������һ�ڵ��next���������ýڵ��nextֵ�ȸ�Ϊ�գ���ָ��Ϊ������Ľ�����־��
		s->data = i;//�Ըýڵ��data���и�ֵ
		s->next = NULL;//���ýڵ��nextֵ�ȸ�Ϊ�գ���ָ��Ϊ������Ľ�����־��
		//���ýڵ�ĵ�ַ������һ�ڵ��next��
		//��Ҫһ���м�ָ�����p(pʼ�մ�����һ�ڵ�)
		p->next = s; //����i���ڵ�ĵ�ַ������i-1���ڵ��next��
		//��ʱ�����p���и��£�����ʱpӦ�����i���ڵ㣨�������ӵĵ�һ���ڵ㽫ֱ��ָ�����һ���ڵ㣩
		p = s;//��p���и��£�������i���ڵ�ĵ�ַ��ֵ��p��
	}
}
void ListShow(ListNode* list)  //��ʾ����
{
	ListNode* p = list;
	if (p == NULL)
	{
		printf("�������Ѿ������٣����������ڣ�");
	}
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//���һ������ĵ�k���ڵ�
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
			 return NULL; //���ص���k���ڵ㣬��������û��k���ڵ㣬����NULL
		 }
	 }
	 while (pListHead != NULL)
	 {
		 p = p->next;
		 pListHead = pListHead->next;
	 }
	 return p;
}