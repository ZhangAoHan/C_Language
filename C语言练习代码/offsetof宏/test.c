#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��

#define PYL(s,name)  (int)&(((s*)0)->name)  //�Ͽν̵ķ���

#define PYL2(s1,name1,name2) (int)&(s1.name2) - (int)&(s1.name1)  //��ַ����ķ���
struct  Struct
{
	char a;
	int b;
	char c;
};
int main()
{
	printf("%d %d %d\n", PYL(struct  Struct, a),PYL(struct  Struct, b),PYL(struct  Struct, c));
	struct  Struct ss = {'a',5,'b'};
	printf("%d %d %d\n", PYL2(ss, a, a), PYL2(ss, a, b), PYL2(ss, a, c));
	return 0;
}