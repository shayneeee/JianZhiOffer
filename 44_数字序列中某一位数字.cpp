#include <iostream>
#include <cmath>
using namespace std;

int mofn(int n, int b, int m)  //返回数字n中从高到低第m位数字,n为b位数
{
    n=n/pow(10,b-m);
    return n%10;

}
int digitAtIndex(int index)
{
    if(index==0)
        return 0;

    int b=1;    //位数
    int num=9; //不同位数的数字个数
    //1位数10个，2位数90个，3位数900个。。。
    while(index>b*num)
    {
        index-=b*num;
        b++;
        num*=10;
    }

    int start=pow(10,b-1);  //不同位数的第一个数，1位数为0，2位数为10，3位数为100。。。

    //index所指为b位数cnum中由高到低第m个数字
    int m=index%b;
    int cnum=0;
    if(m==0)
    {
        cnum=start+index/b-1;
        return mofn(cnum,b,b);
    }
    else
    {
        cnum=start+index/b;
        return mofn(cnum,b,m);
    }

}

int main ()
{
    cout<<digitAtIndex(19)<<endl;
}


