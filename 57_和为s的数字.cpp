#include <iostream>
using namespace std;

bool FindTowNum(int *pdata, int length, int &num1, int &num2, int s)
{
    if(pdata==nullptr || length<0)
        return false;

    int i=0;
    int j=length-1;
    bool found=false;

    while(i<j)
    {
        if(pdata[i]+pdata[j]>s)
            j--;
        else if(pdata[i]+pdata[j]<s)
            i++;
        else
        {
            found=true;
            num1=pdata[i];
            num2=pdata[j];
            break;          
        }
    }
    return found;

}

void PrintNumS(int s)
{
    if(s<3)
        return;

    int start=1;
    int end=2;
    int sum=start+end;
    while(start<(s+1)/2)    
    {
        if(sum<s)
        {
            end++;
            sum+=end;
        }
        else if(sum>s)
        {
            sum-=start;
            start++;
        }
        else
        {
            for(int i=start; i<=end; i++)
                cout<<i<<" ";
            cout<<endl;

            end++;
            sum+=end;
        }

    }
}
int main()
{
    /* int a[]={1,2,4,7,11,15}; int n1=0; */
    /* int n2=0; */
    /* FindTowNum(a,6,n1,n2,15); */
    /* cout<<n1<<" "<<n2<<endl; */

    PrintNumS(9);
}
