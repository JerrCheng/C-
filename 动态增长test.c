#include"Contact.h"

void menu()
{
	printf("*************************************\n");
	printf("******* 1.add      2.del    *********\n");
	printf("******* 3.search   4.modify *********\n");
	printf("******* 5.sort     6.print  **********\n");
	printf("******* 7.clear    0.exit    *******  \n");
	printf("*************************************\n");
	printf("*************************************\n");

}


void test()
{
	//创建通讯录
	Contact con;       //通讯录
	InitContact(&con); // 初始化通讯录
	int input = 0;

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case EXIT:
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}



int main()
{
	test();
	return 0;
}