#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
void MyListInit(SListNode**  list); //链表初始化函数
void MyListCreat(SListNode** list);
void ListShow(SListNode* list);
void SlistTest(SListNode** list);  //测试函数
void Value_Delete(SListNode** pplist, SLTDateType x); //删除单链表中指定的数据
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
//// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SListNode** plist);

int main()
{
	SListNode* my_list;   //my_list统领整个链表
	MyListInit(&my_list);
	MyListCreat(&my_list); //初始创建一个链表（1-10），方便测试
	SlistTest(&my_list);
	return 0;
}
void SlistTest(SListNode** list)  //测试函数
{
	int sit = 1; //运行标志位
	int points = 0;
	int i = 0;
	SLTDateType data = 0;//插入、删除和查找的数据
	SLTDateType point = 0; //插入、删除和查找的位置
	do
	{
		printf("****************************************************************\n");
		printf("   0：退出         1: 单链表销毁          2: 单链表打印         \n");
		printf("   3: 头插         4: 后插                5：删除指定数据       \n");
		printf("   6：头删         7：尾删                8：查找数据           \n");
		printf("   9：指定下标插入数据                 10：指定下标删除数据     \n");
		printf("****************************************************************\n");
		scanf("%d", &sit);
		switch (sit)
		{
		case 0: sit = 0; break;
		case 1: SListDestory(list); break;
		case 2: ListShow(*list); break;
		case 3:
			printf("请输入要添加的数据！\n");
			scanf("%d", &data);
			SListPushFront(list, data);
			break;
		case 4:
			printf("请输入要添加的数据！\n");
			scanf("%d", &data);
			SListPushBack(list, data); 
			break;
		case 5:
			printf("请输入要删除的数据！\n");
			scanf("%d", &data);
			Value_Delete(list, data);
			break;
		case 6: SListPopFront(list); break;
		case 7: SListPopBack(list); break;
		case 8:
			printf("请输入要查找的数据！\n");
			scanf("%d", &data);
			SListFind(*list, data);  //该函数返回对应节点的指针
			break;
		default: printf("输入错误！请根据提示重新输入！\n"); break; //输入错误提示
		}
	} while (sit);
}
void MyListInit(SListNode** list)  //链表初始化函数
{
	//链表初始化：将链表初始指针赋为空指针
	*list = NULL;  //将SListNode的地址赋为空指针
}
//创建过程：
//函数传递过来的是SListNode** list   (链表MyList,list=&&MyList)
//开辟第一个节点，并将该节点作为链表第一个节点的地址(*list=&MyList)
//构建中间指针变量p      p=*list;  (p=&MyList)，同时对链表第一个节点的data进行赋值（(*list)->data=MyList-data=1）
//后续结构体的地址s
//每次仅开辟一个结构体的空间，同时对该结构体进行赋值（s->data=i;s->next=NULL）
//p->next=s; (MyList->next=s,MyList->next->data=i;MyList->next->next=NULL)  
//p=s;  (p->data=i; p->next=NULL) //对p进行初始化
//如果不对p进行初始化：那么第一个节点将直接指向最后一个节点
void MyListCreat(SListNode** list) //创建单链表
{
	//创建第一个节点
	*list = (SListNode*)malloc(sizeof(SListNode)); //对&MyList进行赋值（开辟空间）
	//对MyList->data进行赋值
	(*list)->data = 1;//第一个节点的data值
	SListNode* p = *list; //p初始代表第一个节点
	for (int i = 2; i <= 10; i++) //一个10个节点，创建后9个节点
	{
		SListNode* s = (SListNode*)malloc(sizeof(SListNode)); //一个节点一个节点的开辟
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
void ListShow(SListNode* list)  //显示链表
{
	SListNode* p = list;
	if (p == NULL)
	{
		printf("单链表已经被销毁，单链表不存在！");
	}
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
SListNode* BuySListNode(SLTDateType x)  // 动态申请一个节点
{
	//创建一个节点
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = x;//对该节点进行赋值
	p->next = NULL; //将该节点的next赋值为NULL（单链表以Null为结束标志）。即使是前插，依然不影响在前插函数里对该值进行操作
	return p; //返回该节点地址
}
void SListPrint(SListNode* plist)  //单链表打印
{
	//由于plist=&MyList 每次打印第i个节点data，同时将plist指向下一节点（plist=plist->next）即可
	while (plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	//尾插：
	//（1）创建一个节点
	//（2）将该节点的地址赋值给单链表最后一个节点的next处，
	//需要注意的是：不可对pplist进行解引用操作，否则将直接改变第一个节点地址（单链表将不完整）
	SListNode* p = BuySListNode(x);
	assert(p != NULL); //保证创建成功
	//创建中间指针变量承接pplist 
	SListNode** pp = pplist;
	while ((*pp)->next != NULL)
	{
		pp = &((*pp)->next);  //找到链表的最后一个节点
	}
	(*pp)->next = p;
	//动态申请一个节点中，已经令p->next=NULL; 这里不用再操作

}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	//头插
	//（1）创建一个节点p
	//（2）将单链表第一个节点的next值赋值给p的next处
	//（3）最后将单链表的第一个节点的地址改为p的地址
	SListNode* p = BuySListNode(x);
	assert(p != NULL); //保证创建成功
	p->next = *pplist;
	*pplist = p;
}
void Value_Delete(SListNode** pplist, SLTDateType x) //删除单链表中指定的数据
{ 
	SListNode* p = SListFind(*pplist, x); //先找到指定数据的位置
	if (p == *pplist) //要删除第一个节点
	{
		*pplist = (*pplist)->next;
		free(p);
	}
	else if (p == NULL) //要删除的节点不存在
	{
		printf("链表中没有%d，无法进行删除操作！\n", x);
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

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	//单链表尾删流程
	//（1）将最后一个节点的地址设置为NULL即可
	if (*pplist == NULL) //不可对空链表进行尾部删除工作
	{
		printf("不可对空链表进行尾删操作！\n");
		return;
	}
	SListNode** p1 = pplist;    //p1=pplist=&&MyList
	SListNode* p2 = (*pplist)->next; //p2=&MyList ->next;
	while (p2 != NULL)
	{
		p1 = &(*p1)->next;//寻找到最后一个节点
		p2 = (*p1)->next;  
	}
	free(*p1); //释放空间
	*p1 = NULL;
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	//单链表头删流程：
	//（1）将第二个节点作为第一个节点即可 &MyList=&MyList ->next
	//(2)并将第一个节点的空间释放
	if (*pplist == NULL) //不可对空链表进行尾部删除工作
	{
		printf("不可对空链表进行尾删操作！\n");
		return;
	}
	SListNode* p = (*pplist)->next; //p=&MyList ->next
	free(*pplist); //free(&MyList)
	*pplist = p;//&MyList=p  
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	// 单链表查找 流程
	//（1）一个节点一个节点的对比
	int i = 1;
	while (plist != NULL)
	{
		if (plist->data == x)
		{
			printf("找到了，第%d个节点！\n", i);
			return plist;//返回节点的指针，方便外部函数调用
		}
		else
		{
			i++;
			plist = plist->next;
		}
	}
	printf("链表中没有%d，没有找到！\n", x);
	return NULL;
}
//// 单链表在pos位置之后插入x
//// 分析思考为什么不在pos位置之前插入？
//void SListInsertAfter(SListNode* pos, SLTDateType x)
//{
//	// 单链表在pos位置之后插入x
//
//}
//// 单链表删除pos位置之后的值
//// 分析思考为什么不删除pos位置？
//void SListEraseAfter(SListNode* pos)
//{
//	// 单链表删除pos位置之后的值
//
//}
// 单链表的销毁
void SListDestory(SListNode** plist)
{
	// 单链表的销毁  即将单链表空间释放 并将地址赋值为NULL
	////方法1：进行头删，一直删到最后
	//while (*plist != NULL)   //plist=&MyList
	//{
	//	SListPopFront(plist);
	//}
	//方法2：进行尾删，一直删到初始位置
	while (*plist != NULL)
	{
		SListPopBack(plist);
	}
}





/********************代码例程************************/
//void MyListCreat(SListNode** list) //创建单链表
//{
//	*list = (SListNode*)malloc(sizeof(SListNode)); //创建第一个结构体的地址
//	assert(*list != NULL);//保证第一个结构体创建成功
//	(*list)->data = 1;//对第一个结构体赋值
//	SListNode* p = *list; //第一个结构体的地址赋给p
//	for (int i = 2; i <= 10; i++)
//	{
//		SListNode* s = (SListNode*)malloc(sizeof(SListNode)); //创建 后9个结构体
//		assert(s != NULL);
//		s->data = i; //结构体赋值
//		s->next = NULL; //下一个结构体的地址初始化（赋为空地址）
//		p->next = s;   //p->next->data=i; p->next->next=NULL;
//		p = s;        //p->data=i; p->next=NULL; 
//		 //最终p->data=i; p->next=NULL;  p->next->data=i; p->next->next=NULL;
//	}
//
//}