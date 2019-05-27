#include <iostream>
#include <queue>
using namespace std;

struct BTNode
{
    int     data;
    BTNode *pLeft;
    BTNode *pright;
};

int GetLevelNum(BTNode *phead)
{
    if(phead==nullptr)
        return 0;
    int cnum=1;     //当前层节点个数
    int nnum=0;     //下一层节点个数
    int k=1;        //层数

    queue<BTNode*> q1;
    q1.push(phead);
    while(!q1.empty())      //一次循环处理一行
    {
        nnum=0;     //清空下一层节点个数
        for(int i=0; i<cnum; i++)   //计算下一层节点个数
        {
            if(q1.front()->pLeft!=nullptr)
            {
                nnum++;
                q1.push(q1.front()->pLeft);
            }
            if(q1.front()->pright!=nullptr)
            {
                nnum++;
                q1.push(q1.front()->pright);
            }
            q1.pop();
        }
        if(nnum>0)          //如果下一行还有元素，层数+1
            k++;
        cnum=nnum;          
    }
    return k;
}

int GetLevelNum1(BTNode *phead)
{
    if(phead==nullptr)      //递归结束条件
        return 0;

    int leftl=GetLevelNum1(phead->pLeft);
    int rightl=GetLevelNum1(phead->pright);
    //深度为1+左右两子树深度较大的一个
    int level=leftl>rightl?leftl:rightl;
    level++;

    return level;
}


bool IsBalanceTree(BTNode *phead)   
{
    if(phead==nullptr)
        return true;
    
    //判断以phead为根节点左右两子树深度差是否大于1
    bool jud=false;                 
    int leftl=GetLevelNum1(phead->pLeft);
    int rightl=GetLevelNum1(phead->pright);

    if(leftl-rightl<2 && leftl-rightl>-2)
        jud=true;
    else
        jud=false;
    //递归的判断树中的所有节点
    return jud && IsBalanceTree(phead->pright) && IsBalanceTree(phead->pright); 
}

bool IsBalanceTree1(BTNode *phead, int &d)
{
    //判断以phead为根节点的左右两子树深度差是否大于1，并返回以phead为根的子树的深度
    if(phead==nullptr)
    {
        d=0;
        return true;
    }

    int leftl=0;        //记录左子树长度
    int rightl=0;       //记录右子树长度

    //后根遍历，并保存每个节点到叶子的深度
    bool leftb=IsBalanceTree1(phead->pLeft,leftl);
    bool rightb=IsBalanceTree1(phead->pright,rightl);

    bool jud=(leftl-rightl>-2 && leftl-rightl<2);

    d=leftl>rightl?leftl+1:rightl+1;
    return jud && leftb && rightb;
}
