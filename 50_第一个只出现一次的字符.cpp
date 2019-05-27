#include <iostream>
using namespace std;

char FirstNotRepeating(char *pstr)
{
    if(pstr==nullptr)
        return '\0';

    int size=256;
    int hashtable[size];

    for(int i=0; i<size; i++)
    {
        hashtable[i]=0;
    }

    char *pc=pstr;
    while(*pc!='\0')
    {
        hashtable[(int)*pc]++;
        pc++;
    }
    pc=pstr;
    while(*pc!='\0')
    {
        if(hashtable[(int)*pc]==1)
            return *pc;
        pc++;
    }
    
    return '\0';

}

void DeleteChar(char *pstr1, char *pstr2)   //在pstr1中删除在pstr2中出现的字符
{
    int size=256;
    int hashtable[size];
    for(int i=0; i<256; i++)
        hashtable[i]=0;

    //将pstr2中出现的字符统计在hashtable中
    char *pc=pstr2;
    while(*pc!='\0')
    {
        hashtable[(int)*pc]++;
        pc++;
    }

    //在pstr1中删除pstr2中出现的字符
    pc=pstr1;
    int index=0;
    while(*pc!='\0')
    {
        if(hashtable[(int)*pc]>0)
            deletchar(pstr1,index);     //删除pstr1所指字符串中的第index个字符

        index++;
        pc++;
    }
}

class CharStatistic
{
public:
    CharStatistic():index(0)
    {
        for(int i=0; i<256; i++)
            occurrence[i]=-1;
    }
    //从流中读取一个字符，并更新统计数组occurrence
    void insert(char c)
    {
        if(occurrence[(int)c]==-1)       //如果该字符未出现过，保存第一次出现的索引
            occurrence[(int)c]=index;
        else                            //如果该字符出现过，将其标志位-2表示重复
            occurrence[(int)c]=-2;
    }
    //遍历统计数组occurrence[],找出大于0的最小值，并返回对应字符
    char FirstAppearingOnce()
    {
        int min=99999;  //用来存放最小的索引值，初值赋一个较大值
        char c='\0';    //用来存放最小索引值对应的字符
        for(int i=0; i<256; i++)
        {
            if(occurrence[i]>=0 && occurrence[i]<min)
            {
                min=occurrence[i];
                c=(char)i;
            }
        }
        return c;
    }

private:
    int occurrence[256];
    //occurrence[i]代表ASCII编码为i的字符在字符流中的位置
    //occurrence[i]=-1表示该字符未出现过，=-2表示该字符出现过多次，
    int index;  //表示当前插入的字符串在流中的位置。
};
