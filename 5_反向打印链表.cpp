#include <iostream>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
}

void PrintListReservingly_Recursively(ListNode *pHead)
{
    if(pHead==nullptr)
        return;

    if(pHead->m_pNext!=nullptr)
        PrintListReservingly_Recursively(pHead->m_pNext);
    cout<<pHead->m_nKey<<" ";
}
