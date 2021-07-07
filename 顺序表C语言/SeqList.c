#include"SeqList.h"

void InitSeqList(psq p)//��ʼ���ҵ�˳���
{
	assert(p);
	p->arr = (datatype*)malloc(sizeof(datatype)*3);
	p->capacity = 3;
	p->size = 0;
}

void DestorySeqList(psq p)//�����ҵ�˳���
{
	free(p->arr);
	p->arr = NULL;
	p->capacity = p->size = 0;
}


void PrintSeqList(psq p)//��ӡ�ҵ�˳���
{
	if (p->size == 0)
	{
		printf("˳���Ϊ�գ�");
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			printf("%d ", p->arr[i]);
		}
		printf("\n");
	}
}

void ExpandCapacity(psq p)//����
{
	p->capacity *= 2;
	datatype* newp =(datatype*) realloc(p->arr,sizeof(datatype) * (p->capacity));//�ɹ�
	//datatype* newp = realloc(p->arr,sizeof(datatype) * (p->capacity));Ϊʲôһֱʧ����
	// 	   �ҵ�ԭ���ˣ�capacityһֱΪ��
	//p->arr = realloc(p->arr, p->capacity);
	//��malloc�ǵ�ѭ����ֵ
	if (!newp)
	{
		printf("���붯̬�ڴ�ʧ��");
		exit(-1);
	}
	p->arr = newp;
}

void PushBackSeqList(psq p, datatype x)//˳���β��
{
	//1.���ж�˳�������û��
	if (p->capacity == p->size)
	{
		//��������
		//���п���ԭʼ��ֵ ���鵥�����ȥ
		ExpandCapacity(p);
	}
	p->arr[p->size] = x;
	p->size++;
}

void PushFrontSeqList(psq p,datatype x)//˳���ǰ��
{
	if (p->capacity == p->size)
	{
		ExpandCapacity(p);
	}
	for (int i = p->size - 1; i >= 0; i--)
	{
		p->arr[i + 1] = p->arr[i];
	}
	p->arr[0] = x;
	p->size++;
}

void PopBackSeqList(psq p)//˳���βɾ
{
	assert(p);
	if (p->size == 0)
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		p->size--;
	}
}

void PopFrontSeqList(psq p)//˳���ǰɾ
{
	assert(p);
	if (p->size == 0)
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			p->arr[i] = p->arr[i + 1];
		}
		p->size--;
	}
}


void InsertSeqList(psq p, int pos, datatype x)//˳�������λ�ò���
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	if (p->capacity == p->size)
	{
		ExpandCapacity(p);
	}
	for (int i = p->size - 1; i >= pos;i--)//i>=pos��posǰ��
	{
		p->arr[i + 1] = p->arr[i];
	}
	p->arr[pos] = x;
	p->size++;
}

void DelSeqList(psq p, int pos)//˳�������λ��ɾ��
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	for (int i = pos; i < p->size - 1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->size--;
}

void SortSeqList(psq p)//�ҵ�˳���������Ҫ����int����
{
	assert(p);
	if (p->size == 0)
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			for (int j = 0; j < p->size - 1 - i; j++)
			{
				if (p->arr[j] > p->arr[j + 1])
				{
					int tmp = p->arr[j];
					p->arr[j] = p->arr[j + 1];
					p->arr[j + 1] = tmp;
				}
			}
		}
	}
}

int SearchSeqList(psq p, datatype x)//�ҵ�˳������
{
	assert(p);
	for (int i = 0; i < p->size; i++)
	{
		if (p->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void ModifySeqList(psq p, datatype x, datatype val)//�ҵ�˳����޸�
{
	assert(p);
	int ret = SearchSeqList(p, x);
	if (ret == -1)
	{
		printf("���޴�ֵ��");
		return;
	}
	else
		p->arr[ret] = val;
}


void menu()
{
	printf("****************************\n");
	printf("*****     1.β������   *****\n");
	printf("*****     2.ͷ������   *****\n");
	printf("*****     3.�β�����   *****\n");
	printf("*****     4.βɾ����   *****\n");
	printf("*****     5.ͷɾ����   *****\n");
	printf("*****     6.��ɾ����   *****\n");
	printf("*****     7.��������   *****\n");
	printf("*****     8.��ӡ����   *****\n");
	printf("*****     0.�˳�����   *****\n");
	printf("****************************\n");
}








