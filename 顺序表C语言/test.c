#include"SeqList.h"



void test()
{
	sq p;

	//测试尾插
	InitSeqList(&p);
	PushBackSeqList(&p, 1);
	PushBackSeqList(&p, 2);
	PushBackSeqList(&p, 3);
	PushBackSeqList(&p, 4);
	PushBackSeqList(&p, 5);
	PushBackSeqList(&p, 6);
	PushBackSeqList(&p, 7);
	PrintSeqList(&p);
	//测试前插
	PushFrontSeqList(&p, 12);
	PushFrontSeqList(&p, 13);
	PushFrontSeqList(&p, 11);
	PrintSeqList(&p);//11 13 12 1 2 3 4 5 6 7
	//测试头删尾删
	PopFrontSeqList(&p);
	PopBackSeqList(&p);
	PrintSeqList(&p);
	//13 12 1 2 3 4 5 6
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PopBackSeqList(&p);
	//PrintSeqList(&p);
	//测试任意位置插入删除
	InsertSeqList(&p,2,7);
	PrintSeqList(&p);
	//13 12 7 1 2 3 4 5 6

	DelSeqList(&p,7);
	PrintSeqList(&p);
	//13 12 7 1 2 3 4 6

	SortSeqList(&p);
	PrintSeqList(&p);
	//1 2 3 4 6 7 12 13

	//测试修改
	ModifySeqList(&p, 4, 666);
	PrintSeqList(&p);
	ModifySeqList(&p, 5, 111);
	PrintSeqList(&p);
	//1 2 3 666 6 7 12 13
	//查无此值！1 2 3 666 6 7 12 13


	DestorySeqList(&p);
}
//void test2()
//{
//	//psq p=NULL;
//	//p->arr = NULL;
//	//p->capacity = 0;
//	//p->size = 0;
//
//    sq* p;
//	p = (psq)malloc(sizeof(sq));//神奇的操作
//	//测试尾插
//	InitSeqList(p);
//	PushBackSeqList(p, 1);
//	PushBackSeqList(p, 2);
//	PushBackSeqList(p, 3);
//	PushBackSeqList(p, 4);
//	PushBackSeqList(p, 5);
//	PushBackSeqList(p, 6);
//
//	PrintSeqList(p);
//	free(p);
//	p = NULL;
//}

int main()
{
	//test();
	//test2();
	sq p;
	InitSeqList(&p);
	int input = 0;

	int x = 0;

	do 
	{
		menu();
		printf("请输入您要调用的功能:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("请输入要尾插的数据:");
				scanf("%d", &x);
				PushBackSeqList(&p,x);	
				printf("插入成功！任意键返回");
				system("pause");
				system("cls");
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
            PrintSeqList(&p);
			break;
		}
		default:
		{
			printf("请输入0-8!\n");
			break;
		}
		
		
		}


	} while (input != 0);
	
	
	printf("动态顺序表已退出，欢迎下次使用！");
	return 0;
}