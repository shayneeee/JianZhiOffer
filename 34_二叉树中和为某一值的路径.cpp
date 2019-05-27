#include <iostream>
#include <vector>
using namespace std;

struct BtNode
{
    int m_nvalue;
    BtNode *m_pleft;
    BtNode *m_pright;
};

void FindPathCore(BtNode *pnode, int n, vector<int> &v);      
void FindPath(BtNode *phead, int n)
{
    if(phead==nullptr)
        return;
    vector<int> v;
    FindPathCore(phead, n-phead->m_nvalue, v);
}

void FindPathCore(BtNode *pnode, int n, vector<int> &v)      //n为输入值减去已经走过的路径节点值，v存放已经走过的路径节点值
{
    v.push_back(pnode->m_nvalue);

    if(pnode->m_pleft!=nullptr || pnode->m_pright!=nullptr) //该节点不是叶节点
    {
            if(pnode->m_pleft!=nullptr)
                FindPathCore(pnode->m_pleft, n-pnode->m_nvalue, v);
            if(pnode->m_pright!=nullptr)
                FindPathCore(pnode->m_pright, n-pnode->m_nvalue, v);
    }
    else                                                    //该节点是叶节点
    {
        if(pnode->m_nvalue==n)
        {
            for(auto i:v)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    v.pop_back();        //因为vector是引用，返回上层时应该弹出该节点
}
