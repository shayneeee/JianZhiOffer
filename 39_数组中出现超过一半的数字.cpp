#include <iostream>
using namespace std;

int Partition(int *num, int start, int end);
int MoreThanHalfNum(int *num, int length)
{
    if(num==nullptr || length<1)
    {
        cerr<<"error parameter.";
        exit(-1);
    }
    int start=0;
    int end=length-1;
    int index=Partition(num,start,end);

    while(index!=length>>1)
    {
        if(index>length>>1)
        {
            end=index-1;
            index=Partition(num,start,end);
        }
        else
        {
            start=index+1;
            index=Partition(num,start,end);
        }
    }
    return num[index];
}

void Swap(int *a,int *b){}

int Partition(int *num, int start, int end)     //快排核心函数
{
    if(start==end)
        return start;
    int mid=(start+end)/2;
    if(num[start]>num[mid])
        Swap(num+start,num+mid);
    if(num[start]>num[end])
        Swap(num+start,num+end);
    if(num[mid]>num[end])
        Swap(num+mid,num+end);
    
    Swap(num+mid,num+end-1);
    int i=start;
    int j=end-1;
    while(1)
    {
        while(i<end && *(num+(++i))<*(num+end-1));
        while(j>start && *(num+(--j))>*(num+end-1));
        if(i<j)
            Swap(num+i,num+j);
        else
            break;
    }
    Swap(num+i,num+end-1);
    return i;
}



int MoreThanHalfNum1(int *num, int length)
{
    if(num==nullptr || length<1)
    {
        cerr<<"error parameter.";
        exit(-1);
    }

    int n=num[0];   //数值
    int m=1;        //次数
    for(int i=1;i<length;i++)
    {
        if(n!=num[i])
            m--;
        else
            m++;

        if(m==0)
        {
            n=num[i];
            m=1;
        }
    }
    return n;
}
