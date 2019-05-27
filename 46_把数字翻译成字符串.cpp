#include <iostream>
using namespace std;

int GetTransCount(const string &num)
{
    int length=num.length();
    int *counts=new int[length];    //counts[i]表示从第i位到末尾组成的数字的不同翻译个数
    int count=0;

    for(int i=length-1; i>=0; i--)
    {
        count=0;
        if(i<length-1)
            count=counts[i+1];
        else
            count=1;                //i=length-1最后一位单独计算

        if(i<length-1)
        {
            int a=(num[i]-'a')*10+num[i+1]-'a'; //如果第i位和第i+1位组成的数字在10和25之间，count[i]=count[i+1]+count[i+2]
            if(a>=10 && a<=25)
            {
                if(i==length-2)         //倒数第二位单独计算
                    count+=1;
                else
                    count+=counts[i+2];
            }
        }
        counts[i]=count;
    }

    delete[] counts;
    return count;
    
}
int GetTransCount(int number)
{
    if(number<0)
        return 0;

    string numinstr=to_string(number);
    return GetTransCount(numinstr);
}
