#pragma once
#include "sysutil.h"
#define Elemtype int //元素类型
#define SEQ_SIZE 8



typedef struct SeqList
{
	Elemtype* base; //数据起始位置
	size_t capacity; //数据容量
	size_t size; //数据个数
}SeqList;

void SeqListInit(SeqList* ps); //顺序表初始化
bool IsFull(SeqList* pst);
bool IsEmpty(SeqList* pst);
void SeqListPushBack(SeqList* ps, Elemtype x);
void SeqListShow(SeqList* ps);
void SeqListPushFront(SeqList* ps, Elemtype x);
void SeqListPushFront2(SeqList* ps, Elemtype* data,size_t num);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);
int SeqListFind(SeqList* ps, Elemtype x);
void SeqListInsert(SeqList* ps, size_t pos, Elemtype x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
void SeqListInit(SeqList* ps)
{
	ps->base = (Elemtype*)malloc(sizeof(Elemtype) * SEQ_SIZE);
	assert(ps->base != NULL); //开辟空间成功
	memset(ps->base,0, sizeof(Elemtype) * SEQ_SIZE);
	ps->capacity = SEQ_SIZE;
	ps->size = 0;
}
bool IsFull(SeqList* pst)  //满了返回1 否则返回0
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}
void SeqListPushBack(SeqList* ps, Elemtype x) //后插
{
	if (IsFull(ps))
	{
		printf("顺序表满了，%d不能插入！\n",x);
		return;
	}
	ps->base[ps->size++] = x;
}
void SeqListShow(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->base[i]);
	}
	printf("\n");
}
////输入1 2 3  结果 3 2 1   （原因：数据是一个一个导入的，每次导入都把之前的数据右移）
void SeqListPushFront(SeqList* ps, Elemtype x) //前插      
{
	int i = 0;
	if (IsFull(ps))
	{
		printf("顺序表满了，%d不能插入！\n", x);
		return;
	}
	for (i = 0; i < ps->size; i++)  //移动数据
	{
		ps->base[ps->size - i] = ps->base[ps->size - i - 1];
	}
	ps->base[0] = x;
	ps->size++;
}
//一次输入多个数据时，保持前后顺序
void SeqListPushFront2(SeqList* ps, Elemtype* data, size_t num)
{
	int i = 0;
	if (ps->size + num >= SEQ_SIZE)
	{
		printf("顺序表满了,不能插入！\n");
		return;
	}
	for (i = 0; i < ps->size; i++)  //移动数据
	{
		ps->base[ps->size - i + ( num - 1 )] = ps->base[ps->size - i - 1];
	}
	for (i = 0; i < num; i++)
	{
		ps->base[i] = *data++;
	}
	ps->size = ps->size + num;
}

void SeqListPopBack(SeqList* ps)  //数据删除  后删
{
	if (IsEmpty(ps))
	{
		printf("没有数据，无法删除！\n");
		return;
	}
	ps->size--;
}
void SeqListPopFront(SeqList* ps)  //前删数据（数据覆盖即可）
{
	int i = 0;
	if (IsEmpty(ps))
	{
		printf("没有数据，无法删除！\n");
		return;
	}
	for (i = 0; i < ps->size; i++)
	{
		ps->base[i] = ps->base[i + 1];
	}
	ps->size--;
}
int SeqListFind(SeqList* ps, Elemtype x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->base[i] == x)
		{
			printf("找到了！位置为第%d个数！\n",i + 1);
			return;
		}
	}
	printf("要查找的数据不存在！\n");
}
void SeqListInsert(SeqList* ps, size_t pos, Elemtype x)
{
	int i = 0;
	if (pos >= ps->size)
	{
		printf("要插入的位置过大！\n");
		return;
	}
	if (pos < 0)
	{
		printf("要插入的位置过小！\n");
		return;
	}
	if (IsFull(ps))
	{
		printf("数据已满，不可增加！\n");
		return;
	}
	for (i = 0; i < ps->size - pos; i++)
	{
		ps->base[ps->size - i] = ps->base[ps->size - 1 - i];
	}
	ps->base[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	int i = 0;
	if (pos < 0)
	{
		printf("要插入的位置过小！\n");
		return;
	}
	if (pos >= ps->size)
	{
		printf("要插入的位置过大！\n");
		return;
	}
	if (IsFull(ps))
	{
		printf("数据已满，不可增加！\n");
		return;
	}
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->base[i] = ps->base[i + 1];
	}
	ps->size--;
}