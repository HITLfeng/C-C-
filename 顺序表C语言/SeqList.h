#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef int datatype;
#include<stdlib.h>
#include<assert.h>


typedef struct SeqList
{
	datatype* arr;//��̬˳���      /    ��ֱ̬�� int arr[100]��
	int capacity;
	int size;
}sq,*psq;

void InitSeqList(psq p);//��ʼ���ҵ�˳���

void DestorySeqList(psq p);//�����ҵ�˳���

void PrintSeqList(psq p);//��ӡ�ҵ�˳���

void ExpandCapacity(psq p);//����

void PushBackSeqList(psq p, datatype x);//˳���β��

void PopBackSeqList(psq p);//˳���βɾ

void PopFrontSeqList(psq p);//˳���ǰɾ

void PushFrontSeqList(psq p, datatype x);//˳���ǰ��

void InsertSeqList(psq p,int pos,datatype x);//˳�������λ�ò���

void DelSeqList(psq p,int pos);//˳�������λ��ɾ��

void SortSeqList(psq p);//�ҵ�˳���������Ҫ����int����

int SearchSeqList(psq p, datatype x);//�ҵ�˳������

void ModifySeqList(psq p, datatype x, datatype val);//�ҵ�˳����޸�

void menu();