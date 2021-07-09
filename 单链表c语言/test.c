#include"SList.h"




void test()
{
	psl phead;
	//InitSList(phead);//一般用来设置头结点，不设不需要
	phead = NULL;
	PushBackSList(&phead, 1);
	PushBackSList(&phead, 2);
	PushBackSList(&phead, 3);
	PushBackSList(&phead, 4);
	PushBackSList(&phead, 5);
	PushBackSList(&phead, 6);
	PrintSList(phead);
	//1->2->3->4->5->6->NULL
	PushFrontSList(&phead, 7);
	PrintSList(phead);
	//7->1->2->3->4->5->6->NULL

	PopBackSList(&phead);
	PrintSList(phead);
	//7->1->2->3->4->5->NULL
	PopFrontSList(&phead);
	PrintSList(phead);
	//2->3->4->5->NULL  ?
	//1->2->3->4->5->NULL  OK
	ModifyNode(&phead, 3, 6);
	PrintSList(phead);
	//1->2->6->4->5->NULL   6后面插入9
	InsertSList(phead, 6, 9);
	PrintSList(phead);
	//1->2->6->9->4->5->NULL
	DeleteSList(&phead, 4);
	PrintSList(phead);
	// 1->2->6->9->5->NULL

	DestorySList(&phead);
	PrintSList(phead);
}

int main()
{
	test();
	return 0;
}