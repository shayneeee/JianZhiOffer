#include <iostream>
using namespace std;

int GetMissingNumber(int *pdata, int length, int start, int end)
{
    if(pdata==nullptr || length<0)
        return -1;
    int mid=(start+end)/2;
    if(pdata[mid]==mid)
        start=mid+1;
    else 
    {
        if(pdata[mid-1]==mid-1)     //第一个下标与数值不相等的下标即为所求数
            return mid;
        else
            end=mid-1;
    }
    return GetMissingNumber(pdata,length,start,end);
}


int GetNumber(int *pdata, int length, int start, int end)
{
    if(pdata==nullptr || length<0)
        return -1;
    int mid=(start+end)/2;
    if(mid>pdata[mid])
        start=mid+1;
    else if(mid<pdata[mid])
        end=mid-1;
    else if(mid==pdata[mid])
        return mid;
    return GetNumber(pdata,length,start,end);
}
int main()
{
    /* int a[]={0,1,2,3,4,5,7,8,9}; */
    /* cout<<GetMissingNumber(a,9,0,8); */
    int a[]={-3,-1,1,3,5};
    cout<<GetNumber(a,5,0,4)<<endl;
}
