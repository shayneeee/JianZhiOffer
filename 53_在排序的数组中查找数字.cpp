#include <iostream>
using namespace std;

int GetFirstK(int *pdata,int length, int start, int end, int k)
{
    if(start>end)
        return -1;
    
    int mid=(start+end)/2;
    if(pdata[mid]>k)
        end=mid-1;
    else if(pdata[mid]<k)
        start=mid+1;
    else if(pdata[mid]==k)
    {
        if(mid==0 || (mid>0 && pdata[mid-1]!=k))
            return mid;     //找到第一个k
        else
            end=mid-1;
    }
    return GetFirstK(pdata,length,start,end,k);
}

int GetLastK(int *pdata, int length, int start, int end, int k)
{
    if(start>end)
        return -1;
    int mid=(start+end)/2;
    
    if(pdata[mid]>k)
        end=mid-1;
    else if(pdata[mid]<k)
        start=mid+1;
    else if(pdata[mid]==k)
    {
        if(mid==length-1 || (mid<length-1 && pdata[mid+1]!=k))
            return mid;      //找到最后一个k
        else
            start=mid+1;
    }
    return GetLastK(pdata,length,start,end,k);
}

int GetNumOfK(int *pdata, int length, int k)
{
    if(pdata==nullptr || length<0)
        return 0;

    int first=GetFirstK(pdata,length,0,length-1,k);
    int last=GetLastK(pdata,length,0,length-1,k);
    return last-first+1;
}


int main()
{
    int a[]={2,2,3,3,3,3,4,4,4};
    cout<<GetNumOfK(a,9,3)<<endl;
}
