#include <iostream>
using namespace std;

int maxaftercut(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int *maxc=new int[length+1];
    maxc[0]=0;
    maxc[1]=1;
    maxc[2]=2;
    maxc[3]=3;
    int sum=0;
    for(int i=4; i<length+1; i++)
    {
        for(int j=1; j<=i; j++)
        {
            sum=maxc[j]*maxc[i-j]>sum?maxc[j]*maxc[i-j]:sum;
        }
        maxc[i]=sum;
    }
    sum=maxc[length];
    delete []maxc;
    return sum;
}

int maxaftercut2(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    switch(length%3)
    {
    case 0:
        return plot(3,length/3);
    case 1:
        return plot(3,(length-4)/3)*2*2;
    case 2:
        return plot(3,length/3)*2;
    }
}


