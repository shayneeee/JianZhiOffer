#include <iostream>
using namespace std;

int FindGreatSubarray(int *pdata, int length)
{
    if(pdata==nullptr || length<1)
        return 0;
    int sum=pdata[0];
    int greatsum=pdata[0];
    int index=1;

    while(index<length)
    {
        if(sum<0)
            sum=pdata[index];
        else
            sum+=pdata[index];

        if(sum>greatsum)
            greatsum=sum;

        index++;
    }
    return greatsum;
}

