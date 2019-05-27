#include <iostream>
using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode *m_pnext;
};

ListNode* Merge(ListNode *phead1, ListNode *phead2)
{
    if(phead1==nullptr || phead2==nullptr)
        return nullptr;
    
    ListNode *newphead=nullptr;         //设置一个空指针作为新链表的头指针

    void MergeCore(phead1, phead2, newphead);
}

void MergeCore(ListNode *&p1,ListNode *&p2, ListNode *&pn)     //将p1和p2所指的节点中较小的一个复制，并令pn指向该节点
{

    if(p1==nullptr && p2==nullptr)        //两个链表都已遍历完,递归结束
    {
        pn=nullptr;
        return;
    }
    else if(p1==nullptr && p2!=nullptr)   //第一个链表遍历完,将第二个链表剩余元素复制到新链表尾
    {
        pn=new ListNode;
        pn->m_nvalue=p2->m_nvalue;
        p2++;
        MergeCore(p1,p2,pn->m_pnext);
    }
    else if(p2==nullptr && p1!=nullptr)   //第二个链表遍历完,将第一个链表剩余元素复制到新链表尾
    {
        pn=new ListNode;
        pn->m_nvalue=p1->m_nvalue;
        p1++;
    }
    else if(p1!=nullptr && p2!=nullptr)   //两个链表都没遍历完,将两指针指向较小元素的节点复制到链表尾
    {
        pn=new ListNode;
        if(p1->m_nvalue > p2->m_nvalue)
        {
            pn->m_nvalue=p2->m_nvalue;
            p2++;
            MergeCore(p1,p2,pn->m_pnext);
        }
        else
        {
            pn->m_nvalue=p2->m_nvalue;
            p1++;
            MergeCore(p1,p2,pn->m_pnext);
        }
    }
}

ListNode* Merge1(ListNode *phead1, ListNode *phead2)
{
    if(phead1==nullptr && phead2==nullptr)
        return nullptr;
    else if(phead1==nullptr)
        return phead2;
    else if(phead2==nullptr)
        return phead1;

    ListNode *newphead=phead1->m_nvalue < phead2->m_nvalue ? phaed1 : phead2;   //为了保留头节点指针所以头节点单独计算
    ListNode *p1 = newphead==phead1 ? phead1+1 : phead1; 
    ListNode *p2 = newphead==phead2 ? phead2+1 : phead2; 
    ListNode *tmp = newphead;

    //tmp指向当前处理的节点，从p1和p2中选取值较小的作为tmp下一节点
    while(p1!=nullptr || p2!=nullptr)
    {
        if(p1==nullptr)     //当p1所在链表已经遍历完
        {
            tmp->m_pnext=p2;
            break;
        }
        if(p2==nullptr)     //当p2所在链表已经遍历完
        {
            tmp->m_pnext=p2;
            break;
        }
        
        if(p1->m_nvalue<p2->m_nvalue)
        {
            tmp->m_pnext=p1;
            p1++;
        }
        else
        {
            tmp->m_pnext=p2;
            p2++;
        }

    }
    return newphead;
}
