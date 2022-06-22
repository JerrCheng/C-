#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX  10
#define TELE_MAX 12
#define ADDR_MAX 30


//枚举
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
	CLEAR

};




typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];

}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];          //创建1000个人信息
	int sz;                       //已存放通讯录的个数
}Contact;

void AddContact(Contact* pc);   //增加信息

void InitContact(Contact* pc); //初始化

void PrintContact(const Contact* pc);  //打印信息

void DelContact(Contact* pc);      //删除指定联系人


void SearchContact(const Contact* pc);   //查找联系人

void ModifyContact(Contact* pc);       //修改联系人信息

void ClearContact(Contact* pc);            //清空通讯录

void SortContact(Contact* pc);              //联系人排序