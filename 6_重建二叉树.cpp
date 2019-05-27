#include <iostream>
using namespace std;

struct BTNode
{
    int m_nValue;
    BTNode *m_pleft=nullptr;
    BTNode *m_pright=nullptr;
};


BTNode* BuildTree(int *preorder, int *inorder, int mlength)
{
    if(preorder==nullptr||inorder==nullptr||mlength<0)
        return nullptr;

    //当数组只剩一个数字时直接建立结点并返回。
    if(mlength==1)
    {
        BTNode *root=new BTNode();
        root->m_nValue=preorder[0];
        root->m_pleft=nullptr;
        root->m_pright=nullptr;
    }
    
    //在中序遍历数组中寻找根结点的位置
    int lengthofleft;
    int lengthofright;
    for(int i=0; i<mlength; i++)
    {
        if(preorder[0]==inorder[i])
        {
            lengthofleft=i;
            lengthofright=mlength-i-1;
            break;
        }
    }

    //创建根节点，其左右儿子的指针通过递归调用函数获得
    BTNode *root=new BTNode();
    root->m_nValue=preorder[0];
    if(lengthofleft>0)
        root->m_pleft=BuildTree(preorder+1, inorder, lengthofleft);
    if(lengthofright>0)
        root->m_pright=BuildTree(preorder+lengthofleft+1, inorder+lengthofleft+1, lengthofright);
    return root;
}

void postorder_travelsal(BTNode *root)
{
    if(root==nullptr)
        return;
    postorder_travelsal(root->m_pleft);
    postorder_travelsal(root->m_pright);
    cout<<root->m_nValue<<" ";
}


int main()
{
    int preorder[]={5,4,3,1};
    int inorder[]={1,3,4,5};
    BTNode *root=BuildTree(preorder,inorder,4);
    postorder_travelsal(root);

}
