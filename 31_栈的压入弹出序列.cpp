#include <iostream>
#include <stack>
using namespace std;


bool IsPopOrder(int *input, int *poporder, int Length)
{
    if(input==nullptr || poporder==nullptr)
        return false;

    stack<int> stmp;
    int n1=0;       //输入序列的偏移量
    int n2=0;       //待测序列偏移量

    while(n1<Length && n2<Length)  
    {
        while(stmp.empty() || stmp.top()!=*(poporder+n2))   //当辅助栈为空或者栈顶元素不等于待测元素时将输入序列继续入栈
        {
            if(n1==Length-1)    //输入序列已经全入栈
                break;

            stmp.push(*(input+(++n1)));
        }
        if(stmp.top()!=*(poporder+n2))  //当输入序列全部入栈并且栈顶元素 不等于待检测序列的待检测位
            break;

        stmp.pop();
        n2++;
    }

    if(n1==Length-1 && stmp.empty())    //只有将输入序列全部压入栈并且栈内元素为空时返回true
        return true;
    else
        return false;

}

int main()
{
    int a[]={1,2,3,4,5};
    int b[]={4,5,3,2,1};
    int c[]={4,3,5,1,2};

    cout<<IsPopOrder(b,c,5)<<endl;

}
