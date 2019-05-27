#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class StackWithMin
{
public:
    T s_min()const;
    void pop();
    void push(const T &value);
private:
    stack<T> data;
    stack<T> d_min;
};

template<typename T>
T StackWithMin<T>::s_min()const
{
    if(data.size()==0||d_min.size()==0)
        cerr<<"empty stack"<<endl;

    return d_min.front();
}

template<typename T>
void StackWithMin<T>::push(const T &value)
{
    data.push(value);
    if(value>d_min.front())
        d_min.push(d_min.front());
    else
        d_min.push(value);
}

template<typename T>
void StackWithMin<T>::pop()
{
    if(data.size()==0||d_min.size()==0)
        cerr<<"empty stack"<<endl;

    data.pop();
    d_min.pop();
}
