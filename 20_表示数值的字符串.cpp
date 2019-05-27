#include <iostream>
using namespace std;

bool isNum(const char *str)
{
    if(str==nullptr||*str=='\0')
        return false;

    bool result=scanInteger(str);       //先扫描整数部分，有整数返回true
    
    if(str=='.')                        //如果有.则扫描小数部分
    {
        str++;
        result=result||scanUnsignedInteger(str);    //小数部分不能有符号，小数点前或后有一部分有数字即可
    }
    if(str=='e'||str=='E')              //如果有e或者E则扫描指数部分
    {
        str++;
        result=result&&scanInteger(str);            //指数前后都应该有数字
    }
    return result;
}

bool scanUnsignedInteger(char *&str)    //扫描无符号整数：判断str所指字符串也没有若干0到9数字，有则返回true
{
    char *start=str;
    while(*str>='0'&&*str<='9')
        str++;
    return str>start;
}

bool scanInteger(char *&str)            //扫描可以有符号的整数
{
    if(*str=='-'||*str=='+')
        str++;
    return scanUnsignedInteger(str);
}


