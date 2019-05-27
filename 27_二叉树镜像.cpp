#include <iostream>
using namespace std;

struct BtNode
{
    int m_nvalue;
    BtNode *m_pleft;
    BtNode *m_pright;
};

void Mirror(BtNode *proot)
{
    if(proot==nullptr)
        return;
    if(proot->m_pleft==nullptr && proot->m_pright==nullptr)
        return;

    BtNode *tmp=proot->m_pleft;
    proot->m_pleft=proot->m_pright;
    proot->m_pright=tmp;

    Mirror(proot->m_pleft);
    Mirror(proot->m_pright);
}
