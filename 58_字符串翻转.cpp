#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

void ReverseStr(char *pdata)
{
    char *p=pdata;
    stack<vector<char>> s;
    while(*p!='\0')
    {
        vector<char> v;
        while(*p!=' ' && *p!='\0')      //注意需要再次判断p是否到字符串结尾
            v.push_back(*(p++));
        s.push(v);
        v.clear();
        p++;
    }

    while(!s.empty())
    {
        vector<char> v=s.top();
        for(auto i:v)
            cout<<i;
        cout<<' ';
        s.pop();
    }
}

void Reverse(char *begin, char *end)    //翻转以begin为起点end为终点的字符串
{
    if(begin==nullptr || end==nullptr)
        return;

    while(begin<end)
    {
        char tmp=*begin;
        *begin=*end;
        *end=tmp;
        begin++;
        end--;
    }
}
void ReverseStr1(char *pdata)           //通过两次翻转实现
{
    //翻转整个字符串
    char *end=pdata;
    while(*(end+1)!='\0')               //定位到字符串最后一个字符
        end++;
    Reverse(pdata,end);                 

    //翻转每个单词
    char *start=pdata;                  //指向单词首字符
    end=pdata;                          //指向分隔符' 'or'\0'
    while(*end!='\0')
    {
        while(*end!=' ' && *end!='\0')
            end++; 
        Reverse(start,end-1);
        if(*end!='\0')
        {
            start=end+1;
            end++;
        }
    }
}

void LeftRotate1bit(char *pdata)    //将字符串左移1位
{
    int length=0;
    char *pc=pdata;
    while(*pc!='\0')
    {
        pc++;
        length++;
    }
    char tmp=*pdata;                //第一个字符临时储存下来，最后放在字符串尾
    pc=pdata;
    while(*(pc+1)!='\0')
    {
        *pc=*(pc+1);                //所有字符前移一位
        pc++;
    }
    *pc=tmp;                        //将首字符放在最后
}
void LeftRotateString(char *pdata, int n)
{
    if(pdata==nullptr || n<0)
        return;

    while(n-->0)
        LeftRotate1bit(pdata);
}


void LeftRotateString1(char *pdata, int n)
{
    if(pdata==nullptr || n<0)
        return;
    int length=strlen(pdata);
    Reverse(pdata,pdata+length-1);          //翻转整个字符串
    Reverse(pdata,pdata+length-n-1);        //翻转前length-n位
    Reverse(pdata+length-n,pdata+length-1); //翻转后n位
}
int main()
{
    char str[]="i am a student.";
    /* ReverseStr1(str); */
    LeftRotateString1(str,5);
    cout<<str;
}
