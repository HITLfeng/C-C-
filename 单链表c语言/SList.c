#include"SList.h"

//void InitSList(psl phead)//��ʼ��,Ҫ��ͷ������⿴
//{
//	SLN* headnode = (SLN*)malloc(sizeof(SLN));
//	if (!newnode)
//	{
//		printf("���붯̬�ڴ�ʧ�ܣ�");
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
		printf("���붯̬�ڴ�ʧ�ܣ�");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
}

void PrintSList(psl phead)//������ӡ����
{
	psl flow = phead;
	while (flow != NULL)
	{
		printf("%d->", flow->data);
		flow = flow->next;
	}
	printf("NULL\n");
}

void PushBackSList(psl* pphead, datatype x)//β��,����ָ��
{
	//2��������գ��ǿ�
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

void PushFrontSList(psl* pphead, datatype x)//ͷ��
{
	//2��������գ��ǿ�
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

void PopFrontSList(psl* pphead)//ͷɾ
{
	//3�����
	if (*pphead == NULL)
	{
		printf("�������͵��");
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

void PopBackSList(psl* pphead)//βɾ
{
	//3�����
	if (*pphead == NULL)
	{
		printf("�������͵��");
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

SLN* FindNode(psl phead,datatype x)//�ҵ���һ���㣬�������ַ
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

void ModifyNode(psl* pphead, datatype x, datatype val)//��x�滻Ϊval
{
	psl pret = FindNode(*pphead, x);
	if (!pret)
	{
		printf("û�����ֵ���滻ʧ�ܣ�");
		return;
	}
	pret->data = val;
}

void InsertSList(psl phead, datatype x, datatype innum)//��x�������innum
{
	psl pret = FindNode(phead, x);
	if (!pret)
	{
		printf("û�����ֵ������λ�ò���,ʧ�ܣ�");
		return;
	}
	psl newp = GetNode(innum);
	newp->next = pret->next;
	pret->next = newp;
}

void DeleteSList(psl* pphead, datatype x)//ɾ��x
{
	psl pret = FindNode(*pphead, x);
	if (!pret)
	{
		printf("û�����ֵ������λ�ò���,ʧ�ܣ�");
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


void DestorySList(psl* pphead)//��������
{
	if (*pphead == NULL)
	{
		return;
	}
	//�ͷ��ڴ浥�����е��鷳��
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





