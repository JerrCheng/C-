#include"Contact.h"

//��ʼ��
void InitContact(Contact* pc)
{
	assert(pc);
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
}

//¼����Ϣ
void AddContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("������������>");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}

//��ӡ��Ϣ
void PrintContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ���ӡû��Ҫ\n");
		return;
	}

	printf("%20s %40s %5s %12s %30s\n", "����" "����" "�Ա�" "�绰" "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s %5d %5s %12s %30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}


//������ϵ��
//�ҵ������±꣬�Ҳ�������-1
int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ָ����ϵ��
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	//ɾ��
	//1.����
	printf("������Ҫ���ҵ�����\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2.ɾ��
	int j = 0;
	for (j = pos; j < pc->sz - 1; j++)  //�����-1��Ϊ�˷�ֹɾ��ʱԽ�����
	{
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

//������ϵ��
void SearchContact(Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���ҵ�����\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	printf(" % 15s\t % 5s\t % 5s\t % 12s\t % 20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	printf(" % 15s\t % 5s\t % 5s\t % 12s\t % 20s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
}



//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	int i = 0;

	if (pc->sz == 0)                      //�յľ��޷��ҵ�
	{
		printf("ͨѶ¼�ѿգ��޷��޸�\n");
		return;
	}


	//�޸�
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", name);

	//����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("������Ҫ�޸ĵ���Ϣ��1-���֣�2-���䣬3-�Ա�4-�绰��5-סַ��:>");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("�������µ�����:>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("�������µ�����:>");
		scanf("%d", &pc->data[pos].age);
		break;
	case 3:
		printf("�������µ��Ա�:>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("�������µĵ绰:>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("�������µĵ�ַ:>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("���������޸�ʧ��\n");
		return;
	}
	printf("�޸ĳɹ�\n");
}


//���ͨѶ¼
void ClearContact(Contact* pc)
{
	InitContact(pc);
	printf("ͨѶ¼�����\n");
}


//��ϵ������
void SortContact(Contact* pc)
{
	int i, j;
	PeoInfo tmp;
	for (i = 0; i < pc->sz - 1; i++)
	{
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (0 < strcmp(pc->data[j].name, pc->data[j + 1].name))
			{
				tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
			}
		}
	}
	printf("���������\n");
}