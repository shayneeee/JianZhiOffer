#include <iostream>
using namespace std;

int numberof1(int n)
{
    int num=0;
    while(n)
    {
        if(n%2==1)
            num++;
        n/=2;
    }
    return num;
}

int numberof1_(int n)
{
    int num=0;
    int flag=1;
    while(flag)
    {
        if(n&flag)
            num++;
        flag=flag<<1;
    }
    return num;
}

int main()
{
    cout<<numberof1_(9);
}


