#include <iostream>
#include <cstring>
using namespace std;

bool add1(char *num);
void printnum(char *num);
void PrintToMaxOfN(int n)
{
    if(n<1)
        return;

    char num[n+1];
    for(int i=0; i<n; i++)
        num[i]='0';
    num[n]='\0';

    while(!add1(num))
        printnum(num);

    delete []num;

}

bool add1(char *num)
{
    bool overflow=false;
    int length=strlen(num);
    bool flag=true;
    for(int i=length-1; i>=0; i--)
    {
        if(flag&&i>0)
        {
            if(num[i]=='9')
                num[i]='0';
            else
            {
                num[i]+=1;
                flag=false;
                break;
            }
        }
        if(flag&&i==0)
        {
            if(num[i]=='9')
                overflow=true;
            else
                num[i]++;
        }
    }
    return overflow;
}
 void printnum(char *num)
{
    int length=strlen(num);
    bool p=false;
    for(int i=0; i<length; i++)
    {
        if(p)
            cout<<num[i];
        else
            if(num[i]!='0')
            {
                cout<<num[i];
                p=true;
            }
    }
    cout<<endl;
}



void printcore(char *num, int index);
void PrintToMaxOfN_r(int n)
{
    if(n<1)
        return;

    char num[n+1];
    for(int i=0; i<n; i++)
        num[i]='0';
    num[n]='\0';

    printcore(num, 0);
    
    delete []num;

}
void printcore(char *num, int index)
{
    if(index==strlen(num))
    {
        printnum(num);
        return;
    }
    for(int i=0; i<10; i++)
    {
        num[index]='0'+i;
        printcore(num, index+1);
    }
}




int main()
{
    PrintToMaxOfN_r(3);
}
