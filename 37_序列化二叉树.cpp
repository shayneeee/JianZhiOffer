#include <iostream>
using namespace std;

struct BtNode
{
    int m_nvalue;
    BtNode *m_pleft;
    BtNode *m_pright;
};

void Serialize(BtNode *phead,ostream &stream)
{
    if(phead==nullptr)
    {
        stream<<"$"<<",";
        return;
    }

    stream<<phead->m_nvalue<<",";
    Serialize(phead->m_pleft,stream);
    Serialize(phead->m_pright,stream);
}

void Deserialize(BtNode *&proot,istream &stream)
{
    int num;
    if(ReadStream(stream,num))
    {
        proot=new BtNode();
        proot->m_nvalue=num;
        proot->m_pleft=nullptr;
        proot->m_pright=nullptr;

        Deserialize(proot->m_pleft,stream);
        Deserialize(proot->m_pright,stream);

    }
}
