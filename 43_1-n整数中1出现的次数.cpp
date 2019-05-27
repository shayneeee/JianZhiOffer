#include <iostream>
#include <cmath>
using namespace std;

int Numof1(int n)
{
    int sum=0;
    while(n>0)
    {
        if(n%10==1)
            sum++;
        n/=10;
    }
    return sum;
}
int Num1Between1andn(int n)
{
    if(n<1)
        return 0;
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        sum+=Numof1(i);
    }
    return sum;
}

int Num1Between1andN(int n)
{
    int sum=0;
    int num=n;  //用来计算n的位数
    int i=0;    //表示n是几位数
    while(num>0)
    {
        num/=10;
        i++;
    }

    for(int index=0; index<i; index++)      //从个位开始依次计算1在index位出现的次数,index从0开始（个位）
    {
        //例如对12134 index=2（百位）时m=1 h=12 l=34
        int p=(int)pow(10,index);           //不同位的权值，个位为1，十位为10，百位为100...
        int m=(n/p)%10;    //得到第index位的数值
        int h=n/(p*10);       //得到第index位的高位数
        int l=0;
        if(m==1 && index!=0)
            l=n%p;         //当第index位数值为1时，需要计算其低位数，个位（index=0）低位数为0
        
        //计算每一位上1出现的次数分三类，m==0,m==1,m>1
        if(m==0)
        {
            sum+=h*p;
        }
        else if(m==1)
        {
            sum+=h*p+l+1;
        }
        else
        {
            sum+=(h+1)*p;
        }

    }

    return sum;
}
int main()
{
    cout<<Num1Between1andn(10110)<<endl;
}
