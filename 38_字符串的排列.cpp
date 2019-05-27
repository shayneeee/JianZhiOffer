#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void permutation(char *pstr, char *start);
void permutation(char *pstr)
{
    if(pstr==nullptr)
        return;
    permutation(pstr,pstr);
    
}
 
void permutation(char *pstr, char *start)
{
    if(*(start+1)=='\0')    //如果start已经指向字符串最后一位，则打印字符串  递归终止条件
    {
        cout<<pstr<<endl;
        return;
    }
    
    for(char *pc=start;*pc!='\0';pc++)
    {
        //交换第一个字符和pc所指字符
        char tmp=*start;
        *start=*pc;
        *pc=tmp;
        //递归
        permutation(pstr,start+1);
        //注意要再将之前交换的两个元素交换回来
        tmp=*start;
        *start=*pc;
        *pc=tmp;
    }
}

void combination(char *pchar,vector<char> &v);
void combination(char *pstr)
{
    if(pstr==nullptr)
        return;
    vector<char> v;
    combination(pstr,v);
}
void combination(char *pchar,vector<char> &v)
{
    if(*(pchar)=='\0')
    {
        for(auto it:v)
            cout<<it;
        cout<<endl;
    }
    else
    {
        combination(pchar+1,v);
        v.push_back(*pchar);
        combination(pchar+1,v);
        v.pop_back();
    }
}


int main()
{
    char s[]="abc";
    /* permutation(s); */
    combination(s);
}
