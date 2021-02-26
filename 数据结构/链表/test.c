#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
void MyListInit(SListNode**  list); //�����ʼ������
void MyListCreat(SListNode** list);
void ListShow(SListNode* list);
void SlistTest(SListNode** list);  //���Ժ���
void Value_Delete(SListNode** pplist, SLTDateType x); //ɾ����������ָ��������
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
//// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestory(SListNode** plist);

int main()
{
	SListNode* my_list;   //my_listͳ����������
	MyListInit(&my_list);
	MyListCreat(&my_list); //��ʼ����һ������1-10�����������
	SlistTest(&my_list);
	return 0;
}
void SlistTest(SListNode** list)  //���Ժ���
{
	int sit = 1; //���б�־λ
	int points = 0;
	int i = 0;
	SLTDateType data = 0;//���롢ɾ���Ͳ��ҵ�����
	SLTDateType point = 0; //���롢ɾ���Ͳ��ҵ�λ��
	do
	{
		printf("****************************************************************\n");
		printf("   0���˳�         1: ����������          2: �������ӡ         \n");
		printf("   3: ͷ��         4: ���                5��ɾ��ָ������       \n");
		printf("   6��ͷɾ         7��βɾ                8����������           \n");
		printf("   9��ָ���±��������                 10��ָ���±�ɾ������     \n");
		printf("****************************************************************\n");
		scanf("%d", &sit);
		switch (sit)
		{
		case 0: sit = 0; break;
		case 1: SListDestory(list); break;
		case 2: ListShow(*list); break;
		case 3:
			printf("������Ҫ��ӵ����ݣ�\n");
			scanf("%d", &data);
			SListPushFront(list, data);
			break;
		case 4:
			printf("������Ҫ��ӵ����ݣ�\n");
			scanf("%d", &data);
			SListPushBack(list, data); 
			break;
		case 5:
			printf("������Ҫɾ�������ݣ�\n");
			scanf("%d", &data);
			Value_Delete(list, data);
			break;
		case 6: SListPopFront(list); break;
		case 7: SListPopBack(list); break;
		case 8:
			printf("������Ҫ���ҵ����ݣ�\n");
			scanf("%d", &data);
			SListFind(*list, data);  //�ú������ض�Ӧ�ڵ��ָ��
			break;
		default: printf("��������������ʾ�������룡\n"); break; //���������ʾ
		}
	} while (sit);
}
void MyListInit(SListNode** list)  //�����ʼ������
{
	//�����ʼ�����������ʼָ�븳Ϊ��ָ��
	*list = NULL;  //��SListNode�ĵ�ַ��Ϊ��ָ��
}
//�������̣�
//�������ݹ�������SListNode** list   (����MyList,list=&&MyList)
//���ٵ�һ���ڵ㣬�����ýڵ���Ϊ�����һ���ڵ�ĵ�ַ(*list=&MyList)
//�����м�ָ�����p      p=*list;  (p=&MyList)��ͬʱ�������һ���ڵ��data���и�ֵ��(*list)->data=MyList-data=1��
//�����ṹ��ĵ�ַs
//ÿ�ν�����һ���ṹ��Ŀռ䣬ͬʱ�Ըýṹ����и�ֵ��s->data=i;s->next=NULL��
//p->next=s; (MyList->next=s,MyList->next->data=i;MyList->next->next=NULL)  
//p=s;  (p->data=i; p->next=NULL) //��p���г�ʼ��
//�������p���г�ʼ������ô��һ���ڵ㽫ֱ��ָ�����һ���ڵ�
void MyListCreat(SListNode** list) //����������
{
	//������һ���ڵ�
	*list = (SListNode*)malloc(sizeof(SListNode)); //��&MyList���и�ֵ�����ٿռ䣩
	//��MyList->data���и�ֵ
	(*list)->data = 1;//��һ���ڵ��dataֵ
	SListNode* p = *list; //p��ʼ�����һ���ڵ�
	for (int i = 2; i <= 10; i++) //һ��10���ڵ㣬������9���ڵ�
	{
		SListNode* s = (SListNode*)malloc(sizeof(SListNode)); //һ���ڵ�һ���ڵ�Ŀ���
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
void ListShow(SListNode* list)  //��ʾ����
{
	SListNode* p = list;
	if (p == NULL)
	{
		printf("�������Ѿ������٣����������ڣ�");
	}
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
SListNode* BuySListNode(SLTDateType x)  // ��̬����һ���ڵ�
{
	//����һ���ڵ�
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = x;//�Ըýڵ���и�ֵ
	p->next = NULL; //���ýڵ��next��ֵΪNULL����������NullΪ������־������ʹ��ǰ�壬��Ȼ��Ӱ����ǰ�庯����Ը�ֵ���в���
	return p; //���ظýڵ��ַ
}
void SListPrint(SListNode* plist)  //�������ӡ
{
	//����plist=&MyList ÿ�δ�ӡ��i���ڵ�data��ͬʱ��plistָ����һ�ڵ㣨plist=plist->next������
	while (plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	//β�壺
	//��1������һ���ڵ�
	//��2�����ýڵ�ĵ�ַ��ֵ�����������һ���ڵ��next����
	//��Ҫע����ǣ����ɶ�pplist���н����ò���������ֱ�Ӹı��һ���ڵ��ַ����������������
	SListNode* p = BuySListNode(x);
	assert(p != NULL); //��֤�����ɹ�
	//�����м�ָ������н�pplist 
	SListNode** pp = pplist;
	while ((*pp)->next != NULL)
	{
		pp = &((*pp)->next);  //�ҵ���������һ���ڵ�
	}
	(*pp)->next = p;
	//��̬����һ���ڵ��У��Ѿ���p->next=NULL; ���ﲻ���ٲ���

}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	//ͷ��
	//��1������һ���ڵ�p
	//��2�����������һ���ڵ��nextֵ��ֵ��p��next��
	//��3����󽫵�����ĵ�һ���ڵ�ĵ�ַ��Ϊp�ĵ�ַ
	SListNode* p = BuySListNode(x);
	assert(p != NULL); //��֤�����ɹ�
	p->next = *pplist;
	*pplist = p;
}
void Value_Delete(SListNode** pplist, SLTDateType x) //ɾ����������ָ��������
{ 
	SListNode* p = SListFind(*pplist, x); //���ҵ�ָ�����ݵ�λ��
	if (p == *pplist) //Ҫɾ����һ���ڵ�
	{
		*pplist = (*pplist)->next;
		free(p);
	}
	else if (p == NULL) //Ҫɾ���Ľڵ㲻����
	{
		printf("������û��%d���޷�����ɾ��������\n", x);
	}
	else
	{
		SListNode* p1 = p->next;
		while ((*pplist)->next != p)
		{
			pplist = &(*pplist)->next;
		}
		(*pplist)->next = p1;
		free(p);
	}
}

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	//������βɾ����
	//��1�������һ���ڵ�ĵ�ַ����ΪNULL����
	if (*pplist == NULL) //���ɶԿ��������β��ɾ������
	{
		printf("���ɶԿ��������βɾ������\n");
		return;
	}
	SListNode** p1 = pplist;    //p1=pplist=&&MyList
	SListNode* p2 = (*pplist)->next; //p2=&MyList ->next;
	while (p2 != NULL)
	{
		p1 = &(*p1)->next;//Ѱ�ҵ����һ���ڵ�
		p2 = (*p1)->next;  
	}
	free(*p1); //�ͷſռ�
	*p1 = NULL;
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	//������ͷɾ���̣�
	//��1�����ڶ����ڵ���Ϊ��һ���ڵ㼴�� &MyList=&MyList ->next
	//(2)������һ���ڵ�Ŀռ��ͷ�
	if (*pplist == NULL) //���ɶԿ��������β��ɾ������
	{
		printf("���ɶԿ��������βɾ������\n");
		return;
	}
	SListNode* p = (*pplist)->next; //p=&MyList ->next
	free(*pplist); //free(&MyList)
	*pplist = p;//&MyList=p  
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	// ��������� ����
	//��1��һ���ڵ�һ���ڵ�ĶԱ�
	int i = 1;
	while (plist != NULL)
	{
		if (plist->data == x)
		{
			printf("�ҵ��ˣ���%d���ڵ㣡\n", i);
			return plist;//���ؽڵ��ָ�룬�����ⲿ��������
		}
		else
		{
			i++;
			plist = plist->next;
		}
	}
	printf("������û��%d��û���ҵ���\n", x);
	return NULL;
}
//// ��������posλ��֮�����x
//// ����˼��Ϊʲô����posλ��֮ǰ���룿
//void SListInsertAfter(SListNode* pos, SLTDateType x)
//{
//	// ��������posλ��֮�����x
//
//}
//// ������ɾ��posλ��֮���ֵ
//// ����˼��Ϊʲô��ɾ��posλ�ã�
//void SListEraseAfter(SListNode* pos)
//{
//	// ������ɾ��posλ��֮���ֵ
//
//}
// �����������
void SListDestory(SListNode** plist)
{
	// �����������  ����������ռ��ͷ� ������ַ��ֵΪNULL
	////����1������ͷɾ��һֱɾ�����
	//while (*plist != NULL)   //plist=&MyList
	//{
	//	SListPopFront(plist);
	//}
	//����2������βɾ��һֱɾ����ʼλ��
	while (*plist != NULL)
	{
		SListPopBack(plist);
	}
}





/********************��������************************/
//void MyListCreat(SListNode** list) //����������
//{
//	*list = (SListNode*)malloc(sizeof(SListNode)); //������һ���ṹ��ĵ�ַ
//	assert(*list != NULL);//��֤��һ���ṹ�崴���ɹ�
//	(*list)->data = 1;//�Ե�һ���ṹ�帳ֵ
//	SListNode* p = *list; //��һ���ṹ��ĵ�ַ����p
//	for (int i = 2; i <= 10; i++)
//	{
//		SListNode* s = (SListNode*)malloc(sizeof(SListNode)); //���� ��9���ṹ��
//		assert(s != NULL);
//		s->data = i; //�ṹ�帳ֵ
//		s->next = NULL; //��һ���ṹ��ĵ�ַ��ʼ������Ϊ�յ�ַ��
//		p->next = s;   //p->next->data=i; p->next->next=NULL;
//		p = s;        //p->data=i; p->next=NULL; 
//		 //����p->data=i; p->next=NULL;  p->next->data=i; p->next->next=NULL;
//	}
//
//}