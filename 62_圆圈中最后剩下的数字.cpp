#include <iostream>
#include <list>
using namespace std;

int LastRemaining(int n, int m) //圆圈长度为n，每次删第m个数字
{
    if(n<0 || m<0)
        return -1;

    list<int> l;
    list<int>::iterator iter;
    for(int i=0; i<n; i++)
        l.push_back(i);

    while(l.size()>1)
    {
        for(int i=0; i<m; i++)      //list的迭代器不支持随机访问，所以需要累加m次
        {
            iter++;
            if(iter==l.end())       //如果到链表尾则将其指向链表头
                iter=l.begin();
        }
        list<int>::iterator iter1=iter++;
        if(iter1==l.end())
            iter1=l.begin();
        l.erase(iter);              
        iter=iter1;                 //删除一个节点之后将迭代器指向下一个节点
    }
    return *iter;
}


