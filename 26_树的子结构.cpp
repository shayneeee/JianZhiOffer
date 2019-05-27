#include <iostream>
using namespace std;

struct BTNode
{
    double m_dbvalue;
    BTNode *m_pleft;
    BTNode *m_pright;
};

bool HasSubtree(BTNode *proot1, BTNode *proot2)
{
    if(proot1==nullptr || proot2==nullptr)              //输入空树，或者A遍历完递归结束
        return false;

    bool result=false;
    if(equal(proot1->m_dbvalue, proot2->m_dbvalue))     //如果根节点相等，调用DoseTree1haveTree2判断左右子树是否相等
        result=DoseTree1HaveTree2(proot1,proot2);
    if(!result)
        result=HasSubtree(proot1->m_pleft, proot2);     //根节点不相等，递归用其左儿子当作新的根节点调用
    if(!result)
        result=HasSubtree(proot1->m_pright, proot2);    //左儿子也不相等，递归用其右儿子当新的根节点调用

    return result;
}

bool DoseTree1HaveTree2(BTNode *proot1, BTNode *proot2) //当根节点相同时，判断左右子树是否都相同
{
    //因为要递归的调用，所以设置边界条件：a和b同时遍历完，a没遍历完b遍历完，a遍历完b没遍历完
    if(proot2==nullptr) //表示树b被匹配完，即在此之前a和b相应节点都相等
        return true;
    if(proot1==nullptr) //表示还未将b匹配完，a就没有了
        return false;

    if(!equel(proot1->m_dbvalue, proot2->m_dbvalue))    //a和b中当前对应的节点不相同
        return false;
    else
        return DoseTree1HaveTree2(proot1->m_pleft, proot2->m_pleft) && DoseTree1HaveTree2(proot1->m_pright, proot2->m_pright); //当前节点相同时递归的检测左右子节点是否相同
}

bool equel(double d1, double d2)
{
    if(d1-d2<0.0000001 && d2-d1<0.0000001)
        return true;
    else
        return false;
}
