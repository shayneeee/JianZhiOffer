#include <iostream>
#include <cmath>
using namespace std;

//n为还未计算的骰子个数，N为骰子总个数，sum为面向上点数之和，p数组内的值是点数和为N加上下标出现的次数
void SumCore(int n, int N, int sum, int *p)     
{
    if(n<1)         //递归结束条件，所有骰子都计算完，更新出现次数的数组
    {
        p[sum-N]++;
        return;
    }
    for(int i=1; i<=6; i++)
    {
        SumCore(n-1,N,sum+i,p);
    }
}

void PrintProbality(int n)
{
    //创建数组存放点数和出现次数
    int *pint=new int[6*n-n+1];
    //递归计算
    SumCore(n,n,0,pint);
    //打印数组
    for(int i=0; i<=6*n-n; i++)
    {
        double probability;
        probability=pint[i]/pow(6,n);
        cout<<i+n<<" probability: "<<probability<<endl;
    }
    delete[] pint;
}


void PrintProbality1(int n)
{
    if(n<1)
        return;
    int *pProbality[2];
    pProbality[0]=new int[n*6+1];       //为了方便下标为0的元素无效，下标i对应元素表示点数和为i出现的次数
    pProbality[1]=new int[n*6+1];
    for(int i=0; i<n*6; i++)
    {
        pProbality[0][i]=0;
        pProbality[1][i]=0;
    }
    int flag=0;                 //标志当前使用的数组

    for(int i=1; i<=6; i++)     //第一个骰子单独计算
        pProbality[flag][i]=1;
    
    for(int k=2; k<=n; k++)
    {
        for(int i=0; i<6*k; i++)      //计算k个骰子点数和，通过flag所指数组计算另一个数组,先将待存放数据的数组清0
            pProbality[1-flag][i]=0;

        for(int i=k; i<=6*k; i++)   //k个骰子点数和应该为k到6*k
        {
            for(int j=1; j<=6; j++) //每加入一个筛子，点数和s出现次数应该为加入新骰子之前点数和为s-1到s-6出现次数之和
                if(i-j>0)
                    pProbality[1-flag][i]+=pProbality[flag][i-j];
        }
        flag=1-flag;                    //切换当前所用的数组
    }

    //打印点数和的概率
    for(int i=n; i<=6*n; i++)
    {
        cout<<i<<" probality: "<<pProbality[flag][i]/pow(6,n)<<endl;
    }
}

int main()
{
    PrintProbality1(3);
}
