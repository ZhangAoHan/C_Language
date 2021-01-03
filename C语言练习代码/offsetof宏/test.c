#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明

#define PYL(s,name)  (int)&(((s*)0)->name)  //上课教的方法

#define PYL2(s1,name1,name2) (int)&(s1.name2) - (int)&(s1.name1)  //地址相减的方法
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