#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX  10
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 3


//ö��
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


////��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];          //����1000������Ϣ
//	int sz;                       //�Ѵ��ͨѶ¼�ĸ���
//}Contact;

//��̬�����汾
typedef struct Contact
{
	PeoInfo* data;          //�ɴ��1000������Ϣ
	int sz;                       //�Ѵ��ͨѶ¼�ĸ���
	int capacity;                //��¼ͨѶ¼�������
}Contact;

void AddContact(Contact* pc);   //������Ϣ

void InitContact(Contact* pc); //��ʼ��

void PrintContact(const Contact* pc);  //��ӡ��Ϣ

void DelContact(Contact* pc);      //ɾ��ָ����ϵ��


void SearchContact(const Contact* pc);   //������ϵ��

void ModifyContact(Contact* pc);       //�޸���ϵ����Ϣ

void ClearContact(Contact* pc);            //���ͨѶ¼

void SortContact(Contact* pc);              //��ϵ������

void DestoryContact(Contact* pc);          //����ͨѶ¼