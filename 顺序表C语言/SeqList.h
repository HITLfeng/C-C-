#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef int datatype;
#include<stdlib.h>
#include<assert.h>


typedef struct SeqList
{
	datatype* arr;//动态顺序表      /    静态直接 int arr[100]；
	int capacity;
	int size;
}sq,*psq;

void InitSeqList(psq p);//初始化我的顺序表

void DestorySeqList(psq p);//销毁我的顺序表

void PrintSeqList(psq p);//打印我的顺序表

void ExpandCapacity(psq p);//扩容

void PushBackSeqList(psq p, datatype x);//顺序表尾插

void PopBackSeqList(psq p);//顺序表尾删

void PopFrontSeqList(psq p);//顺序表前删

void PushFrontSeqList(psq p, datatype x);//顺序表前插

void InsertSeqList(psq p,int pos,datatype x);//顺序表任意位置插入

void DelSeqList(psq p,int pos);//顺序表任意位置删除

void SortSeqList(psq p);//我的顺序表排序主要用于int类型

int SearchSeqList(psq p, datatype x);//我的顺序表查找

void ModifySeqList(psq p, datatype x, datatype val);//我的顺序表修改

void menu();