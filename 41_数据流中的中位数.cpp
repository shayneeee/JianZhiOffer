#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template<typename T>
class DynamicArray
{
public:
    void Insert(T num);
    T GetMedian();
private:
    vector<T> min;
    vector<T> max;
};

template<typename T>
void DynamicArray<T>::Insert(T num)
{
    if(((min.size()+max.size()) & 1) == 0)      //总数为偶数个
    {
        if(max.size()>0 && num<max[0])          //新插入的数值小于最大堆的最大值，将数值插入最大堆，再将最大堆的最大值弹出插入最小堆
        {
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<T>());

            num=max[0];

            pop_heap(max.begin(),max.end(),less<T>());
            max.pop_back();
        }
        
        min.push_back(num);
        push_heap(min.begin(),min.end(),greater<T>());
    }
    else                                        //总数为奇数个
    {
        if(min.size()>0 && num>min[0])
        {
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<T>());

            num=min[0];

            pop_heap(min.begin(),min.end(),greater<T>());
            min.pop_back();
        }

        max.push_back(num);
        push_heap(max.begin(),max.end(),less<T>());
    }

}
template<typename T>
T DynamicArray<T>::GetMedian()
{
    int size=max.size()+min.size();
    if(size==0)
        cerr<<"no numbers are available";

    T median=0;
    if((size & 1)== 0)      //偶数个时返回最大堆和最小堆堆顶之和除2
        median=(max[0]+min[0])/2;
    else                    //奇数个时返回最小堆堆顶
        median=min[0];

    return median;
}

