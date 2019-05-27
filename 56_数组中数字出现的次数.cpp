#include <iostream>
#include <vector>
using namespace std;

void FindNumAppearOnce(int *pdata, int length, int &num1, int &num2)
{
    if(pdata==nullptr || length<0)
        return;
    //异或数组中所有数
    int tmp=0;
    for(int i=0; i<length; i++)
    {
        tmp^=pdata[i];
    }
    //找出由低到高第一个位1的位记为n
    int n=0;    //从低到高第n位为1,n从0开始
    while(1)
    {
        if((tmp & 1)==1)
            break;
        else
            tmp>>=1;
        n++;
    }
    //将数组元素分为两个子数组
    vector<int> v1;             //存放第n位是1的数
    vector<int> v2;             //存放第n位是0的数
    for(int i=0; i<length; i++)
    {
        if((pdata[i]>>n) & 1)     //第n位是1
            v1.push_back(pdata[i]);
        else
            v2.push_back(pdata[i]);
    }
    //分别找出两个子数组内只出现一次的元素
    num1=0;
    num2=0;
    for(auto i:v1)
    {
        num1^=i;
    }
    for(auto i:v2)
    {
        num2^=i;
    }
}


int FindNumAppearOnce1(int *pdata, int length)
{
    if(pdata==nullptr || length<0)
        return -1;
    int times[32];          //存放每一位出现1的总次数
    for(int i=0; i<32; i++)
        times[i]=0;
    //将数组中所有数字第i位的和放入times[i]
    for(int i=0; i<32; i++)
    {
        for(int j=0; j<length; j++)
        {
            if(pdata[j]>>i & 1)
                times[i]++;
        }
    }
    //times[i]的第i位不能被3整除，则只出现一次的数在该位值为1
    int num=0;
    for(int i=0; i<32; i++)
    {
        if(times[i]%3 != 0)
            num|=1<<i;
    }
    return num;
}
int main()
{
    /* int a[]={2,4,3,6,3,2,5,5}; */
    /* int n1=0; */
    /* int n2=0; */
    /* FindNumAppearOnce(a,8,n1,n2); */
    /* cout<<n1<<" "<<n2<<endl; */

    int a1[]={1,9,3,1,3,3,1};
    cout<<FindNumAppearOnce1(a1,7)<<endl;
}
