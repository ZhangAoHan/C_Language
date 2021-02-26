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
	ListNode* my_list;   //my_listͳ����������
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
	ListNode* p1 = head;  //p��ǰһ���ڵ�
	ListNode* p2 = NULL;  //����λ�õ�ǰһ���ڵ�
	ListNode* p = head->next; //ȡ�����Žڵ�
	while (p != NULL)
	{
		ListNode* pp = head;
		while (pp != p)
		{
			if (p->data < pp->data) //��Ҫ����
			{
				break;
			}
			p2 = pp;
			pp = pp->next;
		}
		//�ҵ����ŵ�����λ��
		//���յ�ַ���������ڵ�
		if (p != pp) //���������û�б�Ҫ����
		{
			//���p�ڵ��ԭλ��
			p1->next = p->next;
			if (pp == head) //Ҫ�͵�һ���ڵ㻥��
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
void MyListCreat(ListNode** list,int *arr,int length) //����������
{
	//������һ���ڵ�
	*list = (ListNode*)malloc(sizeof(ListNode)); //��&MyList���и�ֵ�����ٿռ䣩
	//��MyList->data���и�ֵ
	(*list)->data = arr[0];//��һ���ڵ��dataֵ
	ListNode* p = *list; //p��ʼ�����һ���ڵ�
	for (int i = 2; i <= length; i++) //һ��10���ڵ㣬������9���ڵ�
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode)); //һ���ڵ�һ���ڵ�Ŀ���
		//������ڵ㣺�Ըýڵ��data���и�ֵ��ͬʱ���ýڵ�ĵ�ַ������һ�ڵ��next���������ýڵ��nextֵ�ȸ�Ϊ�գ���ָ��Ϊ������Ľ�����־��
		s->data = arr[i - 1];//�Ըýڵ��data���и�ֵ
		s->next = NULL;//���ýڵ��nextֵ�ȸ�Ϊ�գ���ָ��Ϊ������Ľ�����־��
		//���ýڵ�ĵ�ַ������һ�ڵ��next��
		//��Ҫһ���м�ָ�����p(pʼ�մ�����һ�ڵ�)
		p->next = s; //����i���ڵ�ĵ�ַ������i-1���ڵ��next��
		//��ʱ�����p���и��£�����ʱpӦ�����i���ڵ㣨�������ӵĵ�һ���ڵ㽫ֱ��ָ�����һ���ڵ㣩
		p = s;//��p���и��£�������i���ڵ�ĵ�ַ��ֵ��p��
	}
}