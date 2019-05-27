#include <iostream>
#include <queue>
using namespace std;

tamplate<typename T>
class StackByQueue
{
pubilic:
    void push(const T &node);
    T pop();
private:
    queue<T> q1;
    queue<T> q2;
    queue<T> *p;    //指向当前数据所在的queue
};
tamplate<typename T>
void StackByQueue::push(const T &node)
{
    p->push(node);
}
T StackByQueue::pop()
{
    int l=p->size();
    if(l=0)
        throw new exception("empty stack");
    if(l=1)
    {
        T tmp=p->front();
        p->pop();
        return tmp;
    }
    for(int i=0; i<l-1; i++)
    {
        if(p==&q1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        if(p==&q2)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    if(p==&q1)
    {
        p=&q2;
        T tmp=q1.front();
        q1.pop();
    }
    if(p==&q2)
    {
        p=&q1;
        T tmp=q2.front();
        q2.pop();
    }
    return tmp;
}
