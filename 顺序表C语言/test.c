#include"SeqList.h"



void test()
{
	sq p;

	//����β��
	InitSeqList(&p);
	PushBackSeqList(&p, 1);
	PushBackSeqList(&p, 2);
	PushBackSeqList(&p, 3);
	PushBackSeqList(&p, 4);
	PushBackSeqList(&p, 5);
	PushBackSeqList(&p, 6);
	PushBackSeqList(&p, 7);
	PrintSeqList(&p);
	//����ǰ��
	PushFrontSeqList(&p, 12);
	PushFrontSeqList(&p, 13);
	PushFrontSeqList(&p, 11);
	PrintSeqList(&p);//11 13 12 1 2 3 4 5 6 7
	//����ͷɾβɾ
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
	//��������λ�ò���ɾ��
	InsertSeqList(&p,2,7);
	PrintSeqList(&p);
	//13 12 7 1 2 3 4 5 6

	DelSeqList(&p,7);
	PrintSeqList(&p);
	//13 12 7 1 2 3 4 6

	SortSeqList(&p);
	PrintSeqList(&p);
	//1 2 3 4 6 7 12 13

	//�����޸�
	ModifySeqList(&p, 4, 666);
	PrintSeqList(&p);
	ModifySeqList(&p, 5, 111);
	PrintSeqList(&p);
	//1 2 3 666 6 7 12 13
	//���޴�ֵ��1 2 3 666 6 7 12 13


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
//	p = (psq)malloc(sizeof(sq));//����Ĳ���
//	//����β��
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
		printf("��������Ҫ���õĹ���:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("������Ҫβ�������:");
				scanf("%d", &x);
				PushBackSeqList(&p,x);	
				printf("����ɹ������������");
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
			printf("������0-8!\n");
			break;
		}
		
		
		}


	} while (input != 0);
	
	
	printf("��̬˳������˳�����ӭ�´�ʹ�ã�");
	return 0;
}