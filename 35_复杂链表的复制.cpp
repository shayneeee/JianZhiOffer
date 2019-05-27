#include <iostream>
using namespace std;

struct ComplexListNode
{
    int m_nvalue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};
void CloneNodes(ComplexListNode *phead);
void ConnectSiblingNode(ComplexListNode *phead);
ComplexListNode* ReconnectNodes(ComplexListNode *phead);

ComplexListNode* CLone(ComplexListNode *phead)
{
    if(phead==nullptr)
        return nullptr;
    CloneNodes(phead);
    ConnectSiblingNode(phead);
    return ReconnectNodes(phead);
}

void CloneNodes(ComplexListNode *phead)
{
    if(phead==nullptr)
        return;
    while(phead!=nullptr)
    {
        ComplexListNode *pc=new ComplexListNode();
        pc->m_nvalue=phead->m_nvalue;
        pc->m_pNext=phead->m_pNext;
        phead->m_pNext=pc;
        phead=pc->m_pNext;
    }
}

void ConnectSiblingNode(ComplexListNode *phead)
{
    if(phead==nullptr)
        return;
    while(phead!=nullptr)
    {
        phead->m_pNext->m_pSibling=phead->m_pSibling->m_pNext;
        phead=phead->m_pNext->m_pNext;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode *phead)
{
    if(phead==nullptr)
        return nullptr;
    ComplexListNode *tmp=phead->m_pNext;
    while(phead!=nullptr)
    {
        if(phead->m_pNext->m_pNext!=nullptr)
        {
            phead->m_pNext->m_pNext=nullptr;
            phead->m_pNext=nullptr;
        }
        else
        {
            ComplexListNode *pnext=phead->m_pNext;
            phead->m_pNext=pnext->m_pNext;
            pnext->m_pNext=phead->m_pNext->m_pNext;
        }
    }
    return tmp;
}
