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

//这个版本不设头结点，需要二级指针

//void InitSList(psl phead);//初始化

void PrintSList(psl phead);//遍历打印链表

void PushBackSList(psl* pphead, datatype x);//尾插

void PushFrontSList(psl* pphead, datatype x);//头插

void PopBackSList(psl* pphead);//尾删

void PopFrontSList(psl* pphead);//头删

SLN* FindNode(psl phead,datatype x);//找到第一个点，返回其地址

void ModifyNode(psl* pphead, datatype x ,datatype val);//将x替换为val

void InsertSList(psl phead, datatype x, datatype innum);//在x后面插入innum

void DeleteSList(psl* pphead, datatype x);//删除x

void DestorySList(psl* pphead);//销毁链表
