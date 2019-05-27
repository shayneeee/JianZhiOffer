#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};

ListNode* FirstCommonNode(ListNode *phead1,ListNode *phead2)
{
    stack<ListNode*> s1;
    stack<ListNode*> s2;
    ListNode *p1=phead1;
    ListNode *p2=phead2;
    while(p1!=nullptr)      //将链表1数据压入栈1
    {
        s1.push(p1);
        p1=p1->m_pNext;
    }
    while(p2!=nullptr)      //将链表2数据压入栈2
    {
        s2.push(p2);
        p2=p2->m_pNext;
    }
    
    ListNode *p=nullptr;
    while(s1.top()==s2.top())//从栈顶开始比较两栈，最后一个相同的即是第一个公共节点
    {
        p=s1.top();
        s1.pop();
        s2.pop();
    }
    return p;
}

ListNode* FirstCommonNode1(ListNode *phead1,ListNode *phead2)
{
    int l1=0;
    int l2=0;
    ListNode *p1=phead1;
    ListNode *p2=phead2;
    while(p1!=nullptr)      //计算链表1长度
    {
        l1++;
        p1=p1->m_pNext;
    }
    while(p2!=nullptr)      //计算链表2长度
    {
        l2++;
        p2=p2->m_pNext;
    }
    //对齐指针，使两个指针到两个链表尾距离相等
    p1=phead1;
    p2=phead2;
    if(l1>l2)
    {
        for(int i=0; i<l1-l2; i++)
            p1=p1->m_pNext;
    }
    else
    {
        for(int i=0; i<l2-l1; i++)
            p2=p2->m_pNext;
    }
    //比较两个指针所指元素并递增，第一个相等的即为公共节点
    while(p1!=p2)
    {
        p1=p1->m_pNext;
        p2=p2->m_pNext;
    }
    return p1;
}
