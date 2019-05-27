#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

vector<int> MaxInWindows(const vector<int> &num, int size)
{
    int length=num.size();
    vector<int> Max;
    if(length>size && size>1)
    {
        deque<int> index;   //储存可能作为窗口最大值的下标，index.front()为当前窗口最大值
        for(int i=0; i<size; i++)
        {
            //将新元素与indx内的对应元素 依次 从后back向前front比较，如果以index.back()为下标的元素小于新元素则index.pop_back()
            while(!index.empty() || num[i]>num[index.back()])                   
                index.pop_back();
            //当index空了(首元素或者新元素大于index内所有对应的元素)，或新元素小于index内对应元素则将新元素的下标插入index
            index.push_back(i);
        }

        for(int i=size; i<length-1; i++)
        {
            Max.push_back(num[index.front()]);
            
            if(i-(size-1)>index.front())    //如果当前最大值不在新的窗口内，将其下标弹出
                index.pop_front();
            while(!index.empty() && num[i]>num[index.back()])
                index.pop_back();

            index.push_back(i);
        }
        Max.push_back(num[index.front()]);
    }
    return Max;
}

template<typename T>
class QueueWithMax
{
public:
    QueueWithMax():currentIndex(0){}
    void push_back(T d);    
    void pop_front();
    T max();
private:
    struct DataWithIndex                //同时保存一个元素的值和下标
    {
        T data;
        int index;
    };
    queue<DataWithIndex> dataqueue;     //用来存放队列元素
    deque<DataWithIndex> maxdata;       //用来存放可能成为队列最大元素的元素，头尾都要删元素，所以用双向队列
    int currentIndex;                   //当新插入一个元素时对应的下标，队列尾部加入元素时新元素坐标为原来尾部元素下标+1，队列头部删除元素时队列内元素下标不变
};
template<typename T>
void QueueWithMax<T>::push_back(T d)
{
    //插入元素时先将新元素与maxdata内元素比较，删除小于新元素的元素,再将新元素分别插入dataqueue和maxdata尾部，更新currentIndex
    while(!maxdata.empty() && d>maxdata.back().data)
        maxdata.pop_back();
    DataWithIndex di={d,currentIndex};
    maxdata.push_back(di);
    dataqueue.push(di);
    currentIndex++;
}
template<typename T>
void QueueWithMax<T>::pop_front()
{
    //如果队列要删除的元素是当前队列的最大元素，则更新maxdata
    if(maxdata.front().index==dataqueue.front().index)
        maxdata.pop_front();
    
    dataqueue.pop();
}
template<typename T>
T QueueWithMax<T>::max()
{
    //队列最大元素即为maxdata的首元素
    if(maxdata.empty())
        cerr<<"error";
    return maxdata.front().data;
}
