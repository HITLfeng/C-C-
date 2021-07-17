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
    //����Ҫ�����Ա���prev cur���������һ��ͷ���
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = sorthead;
    while (cur)
    {
        struct ListNode* c = phead->next, * p = phead;
        struct ListNode* next = cur->next;
        while (c)
        {
            //�ҵ�Ҫ���λ��
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
        //if (p == phead)//������������С�������������������ͷ��㣬û��Ҫ���������p->next p = NULL�����
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