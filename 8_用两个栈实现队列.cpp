#include <iostream>
#include <stack>
using namespace std;

tamplate<typename T>
class QueueByStack
{
public:
    void appendTail(const T &node);
    T deleteHead();
private:
    stack<T> s1;   //负责输入
    stack<T> s2;   //负责输出
};
tamplate<typename T>
void QueueByStack::appendTail(const T &node)
{
    s1.push(node);
}
tamplate<typename T>
T QueueByStack::deleteHead()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(s2.empty())
        throw new exception("queue is empty");

    T tmp=s2.top();
    s2.pop();
    return tmp;

}
