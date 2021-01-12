#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
#define uchar unsigned char
//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//提供方法：
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人

void Display_0(void);
char Call_display(struct Mycall* call, uint* num);
char Call_add(struct Mycall* call, uint* num);
char Call_play(struct Mycall* call, uint* num, int cz);
//通讯录结构体
struct Mycall
{
	char name[11]; //最多输入5个汉字
	char xb[5];//男 女 保密
	int age;
	char tel[12];  //11位的电话号码
	char adr[21];  //住址（最多10个汉字）
};
int main()
{
	struct Mycall my_call[100];
	uint num = 0;  //通讯录已有联系人的数量
	int cz = 7;//用户操作按键
	while (Call_play(my_call, &num, cz) == 'Y')
	{
		printf("程序正在运行！\n");
		scanf("%d", &cz);
	}
	return 0;
}
char Call_play(struct Mycall* call, uint* num, int cz) //返回S退出游戏 返回Y继续游戏
{
	switch (cz)
	{
	case 0:return 'S';
	case 1:Call_add(call, num);return  'Y';
	case 7:Call_display(call,num); return 'Y';
	default:printf("未知命令！请重新输入\n"); return  'Y';
	}
}
//通讯录显示函数 （仅显示已存储的信息）
char Call_display(struct Mycall* call, uint* num)  //显示成功返回 Y，显示识别返回 N
{
	printf("/****************通讯录****************/\n");
	printf("已有联系人： %d 个\n",*num);
	if (0 == *num) //还没有联系人
	{
		printf("目前还没有联系人！\n");
	}
	else
	{
		printf("/*姓名**性别**年龄**电话号码******地址*/\n");
		int i = 0;
		for (i = 0; i < *num; i++)
		{
			printf("%s  ",call->name);
			printf("  %s  ", call->xb);
			printf("  %d  ", call->age);
			printf("  %s  ", call->tel);
			printf("%s\n", call->adr);
			call++;
		}
	}
	Display_0();//操作提示函数
	printf("/****************通讯录****************/\n");
	return 'Y';
}
//通讯录操作函数（集合全部的子功能）

//通讯录排序（按名字排序）


//通讯录子功能-添加
char Call_add(struct Mycall* call, uint* num)
{
	char data = '\0';
	printf("请输入姓名：\n");
	int i = 0;
	getchar(); //必须将\n给取出来，否则 下一次调用scanf将直接取出\n
Scan_name:
	i = 0;
	while (scanf("%c", &((call + *num) ->name[i])) && (call + *num)->name[i] != '\n')
	{
		i++;
	}
	if (i >= 11)
	{
		printf("输入的名字太长了，请重新输入！\n");
		goto Scan_name;
	}
	(call + *num)->name[i] = '\0';
	printf("请输入性别：\n");
	//getchar(); //必须将\n给取出来，否则 下一次调用scanf将直接取出\n
Scan_xb:
	i = 0;
	while (scanf("%c", &((call + *num)->xb[i])) && (call + *num)->xb[i] != '\n')
	{
		i++;
	}
	if (i >= 5)
	{
		printf("输入的性别太长了，请重新输入！\n");
		goto Scan_xb;
	}
	(call + *num)->xb[i] = '\0';
	printf("请输入年龄：\n");
	scanf("%d", &((call + *num)->age));
	printf("请输入电话：\n");
	getchar(); //必须将\n给取出来，否则 下一次调用scanf将直接取出\n
Scan_tel:
	i = 0;
	while (scanf("%c", &((call + *num)->tel[i])) && (call + *num)->tel[i] != '\n')
	{
		i++;
	}
	if (i != 11)
	{
		printf("输入的电话号码长度不对，请重新输入！\n");
		goto Scan_tel;
	}
	(call + *num)->tel[i] = '\0';
	printf("请输入地址：\n");
	//getchar(); //必须将\n给取出来，否则 下一次调用scanf将直接取出\n
Scan_adr:
	i = 0;
	while (scanf("%c", &((call + *num)->adr[i])) && (call + *num)->adr[i] != '\n')
	{
		i++;
	}
	if (i >= 20)
	{
		printf("输入的地址长度不对，请重新输入！\n");
		goto Scan_adr;
	}
	(call + *num)->adr[i] = '\0';
	(*num) = (*num)++;
	return 'Y'; //正常返回1
}

//通讯录子功能-查找（按名字查找）

//通讯录子功能-修改

//通讯录子功能-清空

//通讯录子功能-删除


//通讯录显示函数-提示显示
void Display_0(void)
{
	printf("/*************通讯录操作始*************/\n");
	printf("/***0：退出通讯录******1：添加联系人***/\n");
	printf("/***2：删除联系人******3：查找联系人***/\n");
	printf("/***4：修改通讯录******5：清空联系人***/\n");
	printf("/***6：保存通讯录******7：显示通讯录***/\n");
	printf("/*************通讯录操作完*************/\n");
}