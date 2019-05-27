#include <iostream>
using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode *m_pnext;
}

int HasCircle(ListNode *head)   //如果有环返回环长度，如果没环返回-1
{
    if(head==0)
        return -1;

    ListNode *p1=head;
    ListNode *p2=head;
    while(p2->m_pnext!=nullptr)
    {
        if(p1==p2 && p1!=head)  //p1和p2在环内相遇则跳出循环
            break;

        p2+=2;
        p1++;
    }

    if(p2->m_pnext==nullptr)    //p2扫描到了链表末尾则无环
        return -1;

    //链表有环且现在p1和p2停在环内相遇位置
    int n=1;
    p1++;
    p2+=2;
    while(p1!=p2)
    {
        p1++;
        p2+=2;
        n++;
    }
    return n;
}

ListNode* EnterNodeOfLoop(ListNode* head)
{
    if(head==nullptr||head->m_pnext==nullptr)   //空链表或只有一个节点的链表
        return nullptr;

    int n=HasCircle(head);          //无环链表
    if(n<1)
        return nullptr;

    ListNode *p1=head;
    ListNode *p2=head;
    p2+=n;                          //p2先走环长步
    while(p1!=p2)
    {
        p1++;
        p2++;
    }
    return p1;
}
