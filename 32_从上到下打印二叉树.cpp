#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct BtNode
{
    int m_nvalue;
    BtNode *m_pleft;
    BtNode *m_pright;

    BtNode(int v,BtNode *l=nullptr, BtNode *r=nullptr):m_nvalue(v),m_pleft(l),m_pright(r){}
};

void levelprint(BtNode *phead)
{
    if(phead==nullptr)
        return;
    queue<BtNode*> q1;
    q1.push(phead);
    while(!q1.empty())
    {
        cout<<q1.front()->m_nvalue<<" ";
        if(q1.front()->m_pleft!=nullptr)
            q1.push(q1.front()->m_pleft);
        if(q1.front()->m_pright!=nullptr)
            q1.push(q1.front()->m_pright);
        q1.pop();

    }
}

void levelprint1(BtNode *phead)
{
    if(phead==nullptr)
        return;
    queue<pair<BtNode*,int>> q;
    q.push(make_pair(phead,1));
    while(!q.empty())
    {
        auto tmp=q.front();
        q.pop();
        cout<<tmp.first->m_nvalue<<" ";

        if(tmp.first->m_pleft!=nullptr)
            q.push(make_pair(tmp.first->m_pleft,tmp.second+1));
        if(tmp.first->m_pright!=nullptr)
            q.push(make_pair(tmp.first->m_pright,tmp.second+1));

        if(!q.empty() && tmp.second!=q.front().second)
            cout<<endl;
    }
}

void levelprint11(BtNode *phead)
{
    if(phead==nullptr)
        return;
    int n1=1;   //表示该行剩余点数
    int n2=0;   //表示下一行节点数
    queue<BtNode*> q;
    q.push(phead);
    while(!q.empty())
    {
        BtNode *tmp=q.front();
        q.pop();
        cout<<tmp->m_nvalue<<" ";
        n1--;           //出栈一个数当前行剩余点数-1
        if(tmp->m_pleft!=nullptr)
        {
            q.push(tmp->m_pleft);
            n2++;       //下一行点数+1
        }
        if(tmp->m_pright!=nullptr)
        {
            q.push(tmp->m_pright);
            n2++;       //下一行点数+1
        }
        if(n1==0)       //进入下一行,调整点数值
        {
            cout<<endl;
            n1=n2;
            n2=0;
        }
    }

}

void levelprint2(BtNode *phead)
{
    if(phead==nullptr)
        return;
    
    stack<BtNode*> s1;
    stack<BtNode*> s2;
    int flag=0;             //标签 flag为0表示待出栈的数据在s1中并且先左儿子先入栈，为1表示待出栈的数据在s2中并且右儿子先入栈
    stack<BtNode*> *ps=&s1; //ps指向当前存有待出栈数据的stack

    s1.push(phead);
    while(!ps->empty())
    {
        switch(flag) 
        {
        case 0:         //待处理数据在s1中，先左儿子后右儿子入栈s2
            {
                while(!s1.empty())
                {
                    cout<<s1.top()->m_nvalue<<" ";
                    if(s1.top()->m_pleft!=nullptr)
                        s2.push(s1.top()->m_pleft);
                    if(s1.top()->m_pright!=nullptr)
                        s2.push(s1.top()->m_pright);
                    s1.pop();
                }
                cout<<endl;     //输出完一行换行
                ps=&s2;         //该栈处理完毕，指针指向另一个栈
                flag=1;         //更改具体数据栈以及入栈顺序
                break;
            }
        case 1:         //待处理数据在s2中，先右儿子后左儿子入栈s1
            {
                while(!s2.empty())
                {
                    cout<<s2.top()->m_nvalue<<" ";
                    if(s2.top()->m_pright!=nullptr)
                        s1.push(s2.top()->m_pright);
                    if(s2.top()->m_pleft!=nullptr)
                        s1.push(s2.top()->m_pleft);
                    s2.pop();
                }
                cout<<endl;     //输出完一行换行
                ps=&s1;         //该栈处理完毕，指针指向另一个栈
                flag=0;         //更改具体数据栈以及入栈顺序
                break;
            }
        }
    }
}


int main()
{
    BtNode b15(15),b14(14),b13(13),b12(12),b11(11),b10(10),b9(9),b8(8);
    BtNode b7(7,&b14,&b15),b6(6,&b12,&b13),b5(5,&b10,&b11),b4(4,&b8,&b9);
    BtNode b2(2,&b4,&b5),b3(3,&b6,&b7);
    BtNode b1(1,&b2,&b3);
    levelprint2(&b1);

}
