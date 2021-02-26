#pragma once
#include "sysutil.h"
#define Elemtype int //Ԫ������
#define SEQ_SIZE 8



typedef struct SeqList
{
	Elemtype* base; //������ʼλ��
	size_t capacity; //��������
	size_t size; //���ݸ���
}SeqList;

void SeqListInit(SeqList* ps); //˳����ʼ��
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
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
void SeqListInit(SeqList* ps)
{
	ps->base = (Elemtype*)malloc(sizeof(Elemtype) * SEQ_SIZE);
	assert(ps->base != NULL); //���ٿռ�ɹ�
	memset(ps->base,0, sizeof(Elemtype) * SEQ_SIZE);
	ps->capacity = SEQ_SIZE;
	ps->size = 0;
}
bool IsFull(SeqList* pst)  //���˷���1 ���򷵻�0
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}
void SeqListPushBack(SeqList* ps, Elemtype x) //���
{
	if (IsFull(ps))
	{
		printf("˳������ˣ�%d���ܲ��룡\n",x);
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
////����1 2 3  ��� 3 2 1   ��ԭ��������һ��һ������ģ�ÿ�ε��붼��֮ǰ���������ƣ�
void SeqListPushFront(SeqList* ps, Elemtype x) //ǰ��      
{
	int i = 0;
	if (IsFull(ps))
	{
		printf("˳������ˣ�%d���ܲ��룡\n", x);
		return;
	}
	for (i = 0; i < ps->size; i++)  //�ƶ�����
	{
		ps->base[ps->size - i] = ps->base[ps->size - i - 1];
	}
	ps->base[0] = x;
	ps->size++;
}
//һ������������ʱ������ǰ��˳��
void SeqListPushFront2(SeqList* ps, Elemtype* data, size_t num)
{
	int i = 0;
	if (ps->size + num >= SEQ_SIZE)
	{
		printf("˳�������,���ܲ��룡\n");
		return;
	}
	for (i = 0; i < ps->size; i++)  //�ƶ�����
	{
		ps->base[ps->size - i + ( num - 1 )] = ps->base[ps->size - i - 1];
	}
	for (i = 0; i < num; i++)
	{
		ps->base[i] = *data++;
	}
	ps->size = ps->size + num;
}

void SeqListPopBack(SeqList* ps)  //����ɾ��  ��ɾ
{
	if (IsEmpty(ps))
	{
		printf("û�����ݣ��޷�ɾ����\n");
		return;
	}
	ps->size--;
}
void SeqListPopFront(SeqList* ps)  //ǰɾ���ݣ����ݸ��Ǽ��ɣ�
{
	int i = 0;
	if (IsEmpty(ps))
	{
		printf("û�����ݣ��޷�ɾ����\n");
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
			printf("�ҵ��ˣ�λ��Ϊ��%d������\n",i + 1);
			return;
		}
	}
	printf("Ҫ���ҵ����ݲ����ڣ�\n");
}
void SeqListInsert(SeqList* ps, size_t pos, Elemtype x)
{
	int i = 0;
	if (pos >= ps->size)
	{
		printf("Ҫ�����λ�ù���\n");
		return;
	}
	if (pos < 0)
	{
		printf("Ҫ�����λ�ù�С��\n");
		return;
	}
	if (IsFull(ps))
	{
		printf("�����������������ӣ�\n");
		return;
	}
	for (i = 0; i < ps->size - pos; i++)
	{
		ps->base[ps->size - i] = ps->base[ps->size - 1 - i];
	}
	ps->base[pos] = x;
	ps->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	int i = 0;
	if (pos < 0)
	{
		printf("Ҫ�����λ�ù�С��\n");
		return;
	}
	if (pos >= ps->size)
	{
		printf("Ҫ�����λ�ù���\n");
		return;
	}
	if (IsFull(ps))
	{
		printf("�����������������ӣ�\n");
		return;
	}
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->base[i] = ps->base[i + 1];
	}
	ps->size--;
}