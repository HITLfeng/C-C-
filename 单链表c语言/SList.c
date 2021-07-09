#include"SList.h"

//void InitSList(psl phead)//初始化,要设头结点往这看
//{
//	SLN* headnode = (SLN*)malloc(sizeof(SLN));
//	if (!newnode)
//	{
//		printf("申请动态内存失败！");
//		exit(-1);
//	}
//	phead = headnode;
//	headnode->next = NULL;
//}

SLN* GetNode(datatype x)
{
	SLN* newnode = (SLN*)malloc(sizeof(SLN));
	if (!newnode)
	{
		printf("申请动态内存失败！");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
}

void PrintSList(psl phead)//遍历打印链表
{
	psl flow = phead;
	while (flow != NULL)
	{
		printf("%d->", flow->data);
		flow = flow->next;
	}
	printf("NULL\n");
}

void PushBackSList(psl* pphead, datatype x)//尾插,二级指针
{
	//2种情况，空，非空
	psl newp = GetNode(x);
	if (*pphead == NULL)
	{
		//*pphead = GetNode(x);
		*pphead = newp;
	}
	else
	{
		//find tail
		psl tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newp;
	}

}

void PushFrontSList(psl* pphead, datatype x)//头插
{
	//2种情况，空，非空
	psl newp = GetNode(x);
	if (*pphead == NULL)
	{
		//*pphead = GetNode(x);
		*pphead = newp;
	}
	else
	{
		newp->next = *pphead;
		*pphead = newp;
	}
}

void PopFrontSList(psl* pphead)//头删
{
	//3种情况
	if (*pphead == NULL)
	{
		printf("无余岁可偷！");
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		psl tmp = *pphead;
		*pphead = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}

void PopBackSList(psl* pphead)//尾删
{
	//3种情况
	if (*pphead == NULL)
	{
		printf("无余岁可偷！");
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		psl flow1 = *pphead;
		psl flow2 = (*pphead)->next;
		while (flow2->next != NULL)
		{
			flow1 = flow1->next;
			flow2 = flow2->next;
		}
		free(flow2);
		flow2 = NULL;
		flow1->next = NULL;

	}

}

SLN* FindNode(psl phead,datatype x)//找到第一个点，返回其地址
{
	psl flow = phead;
	while (flow != NULL)
	{
		if (flow->data == x)
		{
			return flow;
		}
		else
		{
			flow = flow->next;
		}
	}
	return NULL;
}

void ModifyNode(psl* pphead, datatype x, datatype val)//将x替换为val
{
	psl pret = FindNode(*pphead, x);
	if (!pret)
	{
		printf("没有这个值，替换失败！");
		return;
	}
	pret->data = val;
}

void InsertSList(psl phead, datatype x, datatype innum)//在x后面插入innum
{
	psl pret = FindNode(phead, x);
	if (!pret)
	{
		printf("没有这个值，任意位置插入,失败！");
		return;
	}
	psl newp = GetNode(innum);
	newp->next = pret->next;
	pret->next = newp;
}

void DeleteSList(psl* pphead, datatype x)//删除x
{
	psl pret = FindNode(*pphead, x);
	if (!pret)
	{
		printf("没有这个值，任意位置插入,失败！");
		return;
	}
	psl flow = *pphead;
	while (flow->next != pret)
	{
		flow = flow->next;
	}
	flow->next = pret->next;
	free(pret);
	pret = NULL;
}


void DestorySList(psl* pphead)//销毁链表
{
	if (*pphead == NULL)
	{
		return;
	}
	//释放内存单链表有点麻烦啊
	while ((*pphead)->next != NULL)
	{
		psl flow1 = (*pphead)->next;
		psl flow2 = *pphead;
		while (flow1->next != NULL)
		{
			flow1 = flow1->next;
			flow2 = flow2->next;
		}
		free(flow1);
		flow1 = NULL;
		flow2->next = NULL;
	}
	free(*pphead);
	*pphead = NULL;
}





