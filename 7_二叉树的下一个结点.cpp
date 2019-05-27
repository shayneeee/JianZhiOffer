#include <iostream>
using namespace std;

struct BtNode
{
    int value;
    BtNode *leftson;
    BtNode *rightson;
    BtNode *father;
};

void findnext(BtNode *pc)
{
    BtNode *pnext=nullptr;
    if(pc->rightson!=nullptr)//该节点有右儿子
    {
        pnext=pc->rightson;
        while(pnext->leftson)
            pnext=pnext->leftson;
        return pnext;
    }
    else
    {
        if(pc->father->leftson==pc)//该节点没有右儿子且是其父节点的左儿子
            return pc->father;
        else                        //该节点没有右儿子且是其父节点的右儿子
        {
            pnext=pc->father;
            while(pnext==pnext->father->rightson)
                pnext=pnext->father;
            return pnext;
        }

    }

}
