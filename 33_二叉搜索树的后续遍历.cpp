#include <iostream>
using namespace std;

struct BtNode
{
    int m_nvalue;
    BtNode *m_pleft;
    BtNode *m_pright;
};

bool isPostOrder(int *a, int Length)
{
    if(a==nullptr)
        return false;
    if(Length<2)        //递归终止条件
        return true;
    
    bool result=true;
    int flag=0;             //为0表示向前所指元素应该小于根元素，为1表示当前所指元素应该大于根元素
    int root=*(a+Length-1);
    int LengthOfLeftSon=0;  //左子树长度
    while(a<a+Length-1)
    {
        if(flag==0)
        {
            if(*a<root)     //从头遍历数组，数值小于根时左子树加长
            {
                LengthOfLeftSon++;
                a++;
            }
            else            //遇见第一个大于根的数值，调整flag，后续元素都大于根result才为true
            {
                flag=1;
                a++;
            }
        }
        else
        {
            if(*a>root)
            {
                a++;
            }
            else            //flag为1时所指元素小于根，result为false
            {
                result=false;
                break;
            }
        }
    }
    return result && isPostOrder(a, LengthOfLeftSon) && isPostOrder(a+LengthOfLeftSon,Length-LengthOfLeftSon-1); 
}

