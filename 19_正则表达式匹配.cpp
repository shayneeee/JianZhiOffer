#include <iostream>
#include <cstring>
using namespace std;

bool match(char *str, char* pattern)
{
    if(!str||!pattern)
        throw new exception("error parameter!");

    int length1=strlen(str);
    int length2=strlen(pattern);

    char *pc1=str+length1;      //pc1指向str最后的'\0'
    char *pc2=pattern+length2;  //pc2指向pattern最后的'\0'
    bool result=true;

    while(pc1>=str&&pc2>=pattern)   //pc1,pc2均指向对应字符串内时
    {
        if(*pc2=='.')
        {
            pc2--;
            pc1--;
        }
        else if(*pc2=='*')
        {
            char tmp=*(--pc2);

            if(tmp=='.')
            {
                pc1=str-1;
                pc2--;
                break;
            }

            while(*(pc1)==tmp)
            {
                pc1--;
            }
            pc2--;
        }
        else
        {
            if(*pc1!=*pc2)
            {
                result=false;
                break;
            }
            pc1--;
            pc2--;
        }
    }

    if(pc1!=str-1||pc2!=pattern-1)  //判断两个指针是否都遍历完其对应字符串
        result=false;

    return result;
}


