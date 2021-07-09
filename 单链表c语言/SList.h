#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef int datatype;

typedef struct SListNode
{
	datatype data;
	struct SListNode* next;
}SLN, * psl;

//����汾����ͷ��㣬��Ҫ����ָ��

//void InitSList(psl phead);//��ʼ��

void PrintSList(psl phead);//������ӡ����

void PushBackSList(psl* pphead, datatype x);//β��

void PushFrontSList(psl* pphead, datatype x);//ͷ��

void PopBackSList(psl* pphead);//βɾ

void PopFrontSList(psl* pphead);//ͷɾ

SLN* FindNode(psl phead,datatype x);//�ҵ���һ���㣬�������ַ

void ModifyNode(psl* pphead, datatype x ,datatype val);//��x�滻Ϊval

void InsertSList(psl phead, datatype x, datatype innum);//��x�������innum

void DeleteSList(psl* pphead, datatype x);//ɾ��x

void DestorySList(psl* pphead);//��������
