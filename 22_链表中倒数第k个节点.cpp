#include <iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
}

ListNode* FindKthToTail(ListNode *head, int k)
{
    if(head==nullptr||k<1)
        return nullptr;

    ListNode *p1=head;
    ListNode *p2=head;
    for(int i=0; i<k-1; i++)
    {
        if(p1->m_pNext==nullptr)
            throw new exception("eror k.");

        p1++;
    }
    while(p1->m_pNext)
    {
        p1++;
        p2++;
    }
    return p2;
}
