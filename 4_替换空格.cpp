#include <iostream>
using namespace std;

void ReplaceBlank(char *s,int length)
{
    if(s==nullptr||length<1)
    {
        cerr<<"error input."<<endl;
        return;
    }
    int n=0;    //统计空格个数
    for(int i=0; i<length; i++)
    {
        if(s[i]==' ')
            n++;
    }
    int newlength=length+2*n;
    char *p1=s+length;
    char *p2=s+newlength;

    while(p1!=p2)
    {
        if(*p1==' ')
        {
            p1--;
            *(p2--)='0';
            *(p2--)='2';
            *(p2--)='%';
        }
        else
        {
            *(p2--)=*(p1--);
        }
    }
}

int main()
{
    char a[]="how are you";
    ReplaceBlank(a,11);
    cout<<a<<endl;
}
