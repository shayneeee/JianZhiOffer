#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void ReorderOddEven(int *pData, int length)
{
    if(pData==nullptr||length<=1)
        return;

    int *p1=pData;
    int *p2=pData;
    for(int i=0; i<length; i++)
    {
        if(*p2%2==1)
        {
            if(*p2!=*p1)
                Swap(p1, p2);
            p1++;
        }
        p2++;
    }
}

void ReorderOddEven1(int *pData, int length)
{
    if(pData==nullptr||length<=1)
        return;

    //为了使后面p1，p2遍历时方便使用前++和前--，将p1指向数组头前一位，p2指向数组尾后一位
    int p1=pData-1;
    int p2=pData+length;
    while(p1<p2)
    {
        while(++p1<p2 && *p1%2==0);  //p1停在从前向后第一个偶数
        while(p1<--p2 && *p2%2==1);  //p2停在从后向前第一个奇数
        
        if(p1<p2)
            Swap(p1,p2);
    
    }
}
