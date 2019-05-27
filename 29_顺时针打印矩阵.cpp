#include <iostream>
using namespace std;

void print(int *a, int row, int column)
{
    if(a==nullptr)
        return;
    if(row<1 || column<1)
        return;
    
    //思路：每次for循环顺时针打印一圈,从外向里打印
    //先计算总圈数 row/2+row%2 表示向上取整
    int times= (row/2+row%2) < (column/2) ? (row/2+row%2) : (column/2+column%2);    
    for(int k=0; k<times; k++)
    {
        //以a[i][j]为起点顺时针输出矩阵的一圈 从a[0][0]开始到a[times-1][times-1] 
        //a[i][j]表示为*(a+i*column+j)
        int i;
        int j;

        //顺时针一圈四个角坐标分别为 a[k,k] a[k,column-1-k] a[row-1-k,column-1-k] a[row-1-k,k]
        {
            //输出第一行 
            i=k;
            j=k;
            while(j<column-k)
                cout<<*(a+i*column+(j++))<<" ";

            //输出除去第一行的最后一列  
            i=k+1;
            j=column-k-1;
            while(i<row-k)
                cout<<*(a+(i++)*column+j)<<" ";

            //输出再除去最后一列的最后一行  
            i=row-k-1;
            j=column-k-2;
            while(j>=0+k && row-k-1>k)
                cout<<*(a+i*column+(j--))<<" ";

            //输出再除去最后一列的第一列  
            i=row-k-2;
            j=k;
            while(i>=1+k && k<column-k-1)
                cout<<*(a+(i--)*column+j)<<" ";
        }
    }
}

int main ()
{
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    print(a,1,16);
}
