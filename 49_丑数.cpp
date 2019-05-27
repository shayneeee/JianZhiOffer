#include <iostream>
using namespace std;

int GetUglyNumber(int index)
{
    int *uglynum=new int[index-1];
    uglynum[0]=1;
    int indexofT2=0;
    int indexofT3=0;
    int indexofT5=0;

    for(int i=1; i<index; i++)
    {
        //当前最大丑数值
        int M=uglynum[i-1];
        //寻找T2，T3，T5在数组中位置
        while(uglynum[indexofT2]*2<M)
            indexofT2++;
        while(uglynum[indexofT3]*3<M)
            indexofT3++;
        while(uglynum[indexofT5]*5<M)
            indexofT5++;
        
        int M2=2*uglynum[indexofT2];
        int M3=3*uglynum[indexofT3];
        int M5=5*uglynum[indexofT5];
        //选择M2,M3,M5中最小的作为新的丑数加入数组。
        int min=M2<M3?M2:M3;
        min=min<M5?min:M5;
        uglynum[i]=min;
    }

    int num=uglynum[index-1];
    delete []uglynum;
    return num;
}
