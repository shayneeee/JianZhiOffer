#include <iostream>
using namespace std;

struct BtNode
{
    int value;
    BtNode *pleft;
    BtNode *pright;
};

bool isMirror(BtNode *proot)
{
    if(proot==nullptr)
        return false;
    bool result=isMirror_core(proot->pleft, proot->pright);
}

bool isMirror_core(BtNode *p1, BtNode *p2)  //输入两个在树中镜像位置的节点
{
    //设置递归结束条件
    if(p1==nullptr && p2==nullptr)      //都是空节点表示相等
        return true;
    if(p1==nullptr || p2==nullptr)      //只有一个空节点表示不相等
        return false;

    //两个节点值不相等返回false
    if(p1->value!=p2->value)
        return false;
    else            //节点值相等则递归比较后续对应节点 p1左节点对应p2右节点，p1右节点对应p2左节点
        return isMirror_core(p1->pleft, p2->pright)&&isMirror_core(p1->pright, p2->pleft);
}


