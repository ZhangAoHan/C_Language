#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define uint unsigned int
#define uchar unsigned char
//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//�ṩ������
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��

void Display_0(void);
char Call_display(struct Mycall* call, uint* num);
char Call_add(struct Mycall* call, uint* num);
char Call_play(struct Mycall* call, uint* num, int cz);
//ͨѶ¼�ṹ��
struct Mycall
{
	char name[11]; //�������5������
	char xb[5];//�� Ů ����
	int age;
	char tel[12];  //11λ�ĵ绰����
	char adr[21];  //סַ�����10�����֣�
};
int main()
{
	struct Mycall my_call[100];
	uint num = 0;  //ͨѶ¼������ϵ�˵�����
	int cz = 7;//�û���������
	while (Call_play(my_call, &num, cz) == 'Y')
	{
		printf("�����������У�\n");
		scanf("%d", &cz);
	}
	return 0;
}
char Call_play(struct Mycall* call, uint* num, int cz) //����S�˳���Ϸ ����Y������Ϸ
{
	switch (cz)
	{
	case 0:return 'S';
	case 1:Call_add(call, num);return  'Y';
	case 7:Call_display(call,num); return 'Y';
	default:printf("δ֪�������������\n"); return  'Y';
	}
}
//ͨѶ¼��ʾ���� ������ʾ�Ѵ洢����Ϣ��
char Call_display(struct Mycall* call, uint* num)  //��ʾ�ɹ����� Y����ʾʶ�𷵻� N
{
	printf("/****************ͨѶ¼****************/\n");
	printf("������ϵ�ˣ� %d ��\n",*num);
	if (0 == *num) //��û����ϵ��
	{
		printf("Ŀǰ��û����ϵ�ˣ�\n");
	}
	else
	{
		printf("/*����**�Ա�**����**�绰����******��ַ*/\n");
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
	Display_0();//������ʾ����
	printf("/****************ͨѶ¼****************/\n");
	return 'Y';
}
//ͨѶ¼��������������ȫ�����ӹ��ܣ�

//ͨѶ¼���򣨰���������


//ͨѶ¼�ӹ���-���
char Call_add(struct Mycall* call, uint* num)
{
	char data = '\0';
	printf("������������\n");
	int i = 0;
	getchar(); //���뽫\n��ȡ���������� ��һ�ε���scanf��ֱ��ȡ��\n
Scan_name:
	i = 0;
	while (scanf("%c", &((call + *num) ->name[i])) && (call + *num)->name[i] != '\n')
	{
		i++;
	}
	if (i >= 11)
	{
		printf("���������̫���ˣ����������룡\n");
		goto Scan_name;
	}
	(call + *num)->name[i] = '\0';
	printf("�������Ա�\n");
	//getchar(); //���뽫\n��ȡ���������� ��һ�ε���scanf��ֱ��ȡ��\n
Scan_xb:
	i = 0;
	while (scanf("%c", &((call + *num)->xb[i])) && (call + *num)->xb[i] != '\n')
	{
		i++;
	}
	if (i >= 5)
	{
		printf("������Ա�̫���ˣ����������룡\n");
		goto Scan_xb;
	}
	(call + *num)->xb[i] = '\0';
	printf("���������䣺\n");
	scanf("%d", &((call + *num)->age));
	printf("������绰��\n");
	getchar(); //���뽫\n��ȡ���������� ��һ�ε���scanf��ֱ��ȡ��\n
Scan_tel:
	i = 0;
	while (scanf("%c", &((call + *num)->tel[i])) && (call + *num)->tel[i] != '\n')
	{
		i++;
	}
	if (i != 11)
	{
		printf("����ĵ绰���볤�Ȳ��ԣ����������룡\n");
		goto Scan_tel;
	}
	(call + *num)->tel[i] = '\0';
	printf("�������ַ��\n");
	//getchar(); //���뽫\n��ȡ���������� ��һ�ε���scanf��ֱ��ȡ��\n
Scan_adr:
	i = 0;
	while (scanf("%c", &((call + *num)->adr[i])) && (call + *num)->adr[i] != '\n')
	{
		i++;
	}
	if (i >= 20)
	{
		printf("����ĵ�ַ���Ȳ��ԣ����������룡\n");
		goto Scan_adr;
	}
	(call + *num)->adr[i] = '\0';
	(*num) = (*num)++;
	return 'Y'; //��������1
}

//ͨѶ¼�ӹ���-���ң������ֲ��ң�

//ͨѶ¼�ӹ���-�޸�

//ͨѶ¼�ӹ���-���

//ͨѶ¼�ӹ���-ɾ��


//ͨѶ¼��ʾ����-��ʾ��ʾ
void Display_0(void)
{
	printf("/*************ͨѶ¼����ʼ*************/\n");
	printf("/***0���˳�ͨѶ¼******1�������ϵ��***/\n");
	printf("/***2��ɾ����ϵ��******3��������ϵ��***/\n");
	printf("/***4���޸�ͨѶ¼******5�������ϵ��***/\n");
	printf("/***6������ͨѶ¼******7����ʾͨѶ¼***/\n");
	printf("/*************ͨѶ¼������*************/\n");
}