#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>



struct ListNode {
     int val;
     struct ListNode *next;
};


struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next==NULL)
    {
        return head;
    }
    struct ListNode* sorthead = head;
    struct ListNode* cur = head->next; 
    
    sorthead->next = NULL;
    //这里要经常性保存prev cur，最好设置一个头结点
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = sorthead;
    while (cur)
    {
        struct ListNode* c = phead->next, * p = phead;
        struct ListNode* next = cur->next;
        while (c)
        {
            //找到要插的位置
            if (cur->val < c->val)
            {
                break;
            }
            else
            {
                c = c->next;
                p = p->next;
            }
        }
        //if (p == phead)//处理插入点是最小的那种情况，但这里有头结点，没必要，不会出现p->next p = NULL的情况
        //{
        //    cur->next = c;
        //    phead = cur;
        //}
        cur->next = p->next;
        p->next = cur;

        cur = next;
    }
    return phead->next;

}