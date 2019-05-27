#include <iostream>
using namespace std;
//题目1
//通过duplication将重复的字传出函数，返回值为是否有重复
bool duplicate(int n[],int length,int &duplication)
{
    if(length>1&&n!=nullptr)        //判断数组是否有效
    {
        
        for(int i=0; i<length; i++)//遍历每个元素
        {
            if(n[i]<0||n[i]>length-1)    //判断元素值是否在范围内
            {
                cerr<<"error array.";
                return false;
            }
            while(n[i]!=i)          //若下标为i的元素值不为i
            {
                if(n[n[i]]==n[i])   //若第i个元素值m=n[m]则传出重复值并返回true
                {
                    duplication=n[i];
                    return true;
                }
                else                //否则交换n[i]和n[m]
                {
                    int tmp=n[i];
                    n[i]=n[tmp];
                    n[tmp]=tmp;
                }
            }
        }
        
    }
    return false;
}



//题目2
//在数组n中寻找重复数字并返回
int countrange(const int *n,int length,int start,int end);//函数前置声明
int getduplication(const int *n,int length)
{
    if(n==nullptr||length<1)
    {
        cerr<<"error array."<<endl;
        return 0;
    }
    int start=1;
    int end=length-1;
    while(start<=end)
    {
        int middle=(start+end)/2;
        int tmp=countrange(n,length,start,middle);
        if(end==start&&tmp>1)
            return start;

        if(tmp>(middle-start+1))
            end=middle;
        else
            start=middle+1;
    }
    return -1;
}
//在数组n中统计start到end出现的次数并返回
int countrange(const int *n,int length,int start,int end)
{
    int count=0;
    for(int i=0; i<length; i++)
    {
        if(n[i]>=start&&n[i]<=end)
            count++;
    }
    return count;
}



int main()
{
    /* int a1[4]={3,2,1,1}; */
    /* int a2[6]={5,4,3,2,1,0}; */
    /* int dup; */
    /* cout<<duplicate(a2,6,dup)<<endl; */
    /* cout<<dup<<endl; */
    int a3[8]={2, 3, 5, 4, 3, 2, 6, 7};
    cout<<getduplication(a3,8)<<endl;
}
