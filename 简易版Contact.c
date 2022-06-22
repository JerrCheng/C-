#include"Contact.h"

//初始化
void InitContact(Contact* pc)
{
	assert(pc);
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
}

//录入信息
void AddContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入姓名：>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}

//打印信息
void PrintContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录为空，打印没必要\n");
		return;
	}

	printf("%20s %40s %5s %12s %30s\n", "姓名" "年龄" "性别" "电话" "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s %5d %5s %12s %30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}


//查找联系人
//找到返回下标，找不到返回-1
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

//删除指定联系人
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录已空，无法删除\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	//删除
	//1.查找
	printf("请输入要查找的姓名\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除
	int j = 0;
	for (j = pos; j < pc->sz - 1; j++)  //这里的-1是为了防止删除时越界访问
	{
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

//查找联系人
void SearchContact(Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的姓名\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	printf(" % 15s\t % 5s\t % 5s\t % 12s\t % 20s\n", "名字", "年龄", "性别", "电话", "地址");

	printf(" % 15s\t % 5s\t % 5s\t % 12s\t % 20s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
}



//修改联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	int i = 0;

	if (pc->sz == 0)                      //空的就无法找到
	{
		printf("通讯录已空，无法修改\n");
		return;
	}


	//修改
	printf("请输入要修改的姓名\n");
	scanf("%s", name);

	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入要修改的信息（1-名字，2-年龄，3-性别，4-电话，5-住址）:>");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("请输入新的姓名:>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("请输入新的年龄:>");
		scanf("%d", &pc->data[pos].age);
		break;
	case 3:
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("输入有误，修改失败\n");
		return;
	}
	printf("修改成功\n");
}


//清空通讯录
void ClearContact(Contact* pc)
{
	InitContact(pc);
	printf("通讯录已清空\n");
}


//联系人排序
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
	printf("排序已完成\n");
}