#include <iostream>
using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode *m_pnext;
};

ListNode* ReverseList(ListNode *phead)
{
    if(phead==nullptr)          //空链表
        return nullptr;
    if(phead->m_pnext==nullptr) //只有一个节点的链表
        return phead;

    ListNode *p1=phead;
    ListNode *p2=phead->m_pnext;
    p1->m_pnext=nullptr;        //头节点单独处理

    while(p2!=nullptr)          //从第二个节点开始使其指向上一个节点
    {
        ListNode *tmp=p2->m_pnext;
        p2->m_pnext=p1;
        p1=p2;
        p2=tmp;
    }
    return p1;
}

ListNode* ReverseList_recursion(ListNode *phead)
{
    if(phead==nullptr)          //空链表
        return nullptr;
    if(phead->m_pnext==nullptr) //只有一个节点的链表
        return phead;
    
    ListNode *pl=recursion_core(phead,phead->m_pnext);
    phead->m_pnext=nullptr;     //头节点单独处理
    
    return pl;
}

ListNode* recursion_core(ListNode *p, ListNode *pn)   //使p的下一个节点pn指向p
{
    if(pn=nullptr)          //处理完毕
        return p;

    ListNode *tmp=pn->m_pnext;
    pn->m_pnext=p;
    
    return recursion_core(pn , tmp);
}
