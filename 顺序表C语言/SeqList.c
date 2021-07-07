#include"SeqList.h"

void InitSeqList(psq p)//初始化我的顺序表
{
	assert(p);
	p->arr = (datatype*)malloc(sizeof(datatype)*3);
	p->capacity = 3;
	p->size = 0;
}

void DestorySeqList(psq p)//销毁我的顺序表
{
	free(p->arr);
	p->arr = NULL;
	p->capacity = p->size = 0;
}


void PrintSeqList(psq p)//打印我的顺序表
{
	if (p->size == 0)
	{
		printf("顺序表为空！");
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

void ExpandCapacity(psq p)//扩容
{
	p->capacity *= 2;
	datatype* newp =(datatype*) realloc(p->arr,sizeof(datatype) * (p->capacity));//成功
	//datatype* newp = realloc(p->arr,sizeof(datatype) * (p->capacity));为什么一直失败呢
	// 	   找到原因了，capacity一直为零
	//p->arr = realloc(p->arr, p->capacity);
	//用malloc记得循环赋值
	if (!newp)
	{
		printf("申请动态内存失败");
		exit(-1);
	}
	p->arr = newp;
}

void PushBackSeqList(psq p, datatype x)//顺序表尾插
{
	//1.先判断顺序表满了没有
	if (p->capacity == p->size)
	{
		//进行扩容
		//进行拷贝原始数值 建议单毒拎出去
		ExpandCapacity(p);
	}
	p->arr[p->size] = x;
	p->size++;
}

void PushFrontSeqList(psq p,datatype x)//顺序表前插
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

void PopBackSeqList(psq p)//顺序表尾删
{
	assert(p);
	if (p->size == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		p->size--;
	}
}

void PopFrontSeqList(psq p)//顺序表前删
{
	assert(p);
	if (p->size == 0)
	{
		printf("顺序表为空\n");
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


void InsertSeqList(psq p, int pos, datatype x)//顺序表任意位置插入
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	if (p->capacity == p->size)
	{
		ExpandCapacity(p);
	}
	for (int i = p->size - 1; i >= pos;i--)//i>=pos是pos前插
	{
		p->arr[i + 1] = p->arr[i];
	}
	p->arr[pos] = x;
	p->size++;
}

void DelSeqList(psq p, int pos)//顺序表任意位置删除
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	for (int i = pos; i < p->size - 1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->size--;
}

void SortSeqList(psq p)//我的顺序表排序主要用于int类型
{
	assert(p);
	if (p->size == 0)
	{
		printf("顺序表为空\n");
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

int SearchSeqList(psq p, datatype x)//我的顺序表查找
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

void ModifySeqList(psq p, datatype x, datatype val)//我的顺序表修改
{
	assert(p);
	int ret = SearchSeqList(p, x);
	if (ret == -1)
	{
		printf("查无此值！");
		return;
	}
	else
		p->arr[ret] = val;
}


void menu()
{
	printf("****************************\n");
	printf("*****     1.尾插数据   *****\n");
	printf("*****     2.头插数据   *****\n");
	printf("*****     3.任插数据   *****\n");
	printf("*****     4.尾删数据   *****\n");
	printf("*****     5.头删数据   *****\n");
	printf("*****     6.任删数据   *****\n");
	printf("*****     7.排序数据   *****\n");
	printf("*****     8.打印数据   *****\n");
	printf("*****     0.退出程序   *****\n");
	printf("****************************\n");
}








