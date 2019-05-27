#include <iostream>
using namespace std;

struct BtNode
{
    int m_nvalue;
    BtNode *m_pleft;        //链表中指向该节点前一个节点（值小于该节点）
    BtNode *m_pright;       //链表中指向该节点后一个节点（值大于该节点）
};
void TransCore(BtNode *root,BtNode *&startoflist,BtNode *&endoflist);

BtNode* TransToList(BtNode *proot)
{
    BtNode *start=nullptr;
    BtNode *end=nullptr;
    TransCore(proot, start, end);
    return start;       //返回链表头指针

}

void TransCore(BtNode *root,BtNode *&startoflist,BtNode *&endoflist)     //将以root为根的树转换为链表，并将链表头尾分别放入startoflist和endoflist
{
    if(root==nullptr)
        return;

    BtNode *startofleft=nullptr;
    BtNode *endofleft=nullptr;
    BtNode *startofritht=nullptr;
    BtNode *endofright=nullptr;
    //递归对左右子树调用
    if(root->m_pleft)
    {
        TransCore(root->m_pleft,startofleft,endofleft);
    }
    if(root->m_pright)
    {
        TransCore(root->m_pright,startofritht,endofright);
    }
    //链接左链表，根，右链表
    if(endofleft)
    {
        endofleft->m_pright=root;
        root->m_pleft=endofleft;
    }
    if(startofritht)
    {
        root->m_pright=startofritht;
        startofritht->m_pleft=root;
    }
    //通过引用返回链表头尾指针
    if(startofleft)         //有左子树则返回左子树链表的头节点指针
        startoflist=startofleft;
    else                    //若节点无左子树，则该节点就是以该节点为根的树转换为链表的头节点
        startoflist=root;

    if(endofright)          //有右子树则返回右子树链表的尾节点指针
        endoflist=endofright;
    else                    //若节点无右子树，则该节点就是以该节点为根的树转换为链表的尾节点
        endoflist=root;
}
