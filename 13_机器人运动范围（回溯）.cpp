#include <iostream>
using namespace std;

int movingcount(int m, int n, int k)
{
    if(m<0||n<0||k<0)
        return 0;

    bool *visited=new bool[m*n];
    for(int i=0; i<m*n; i++)
        visited[i]=false;

    movingcore(m, n, k, 0, 0, visited);

    int sum=0;
    for(int i=0; i<m*n; i++)
        if(visited[i])
            sum++;
    
    delete []visited;
    return sum;
}

int getdigitsum(int n)//计算数位之和
{
    int sum=0;
    while(tmp!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void movingcore(int m, int n, int k, int i, int j, bool *visited)   //判断第i行j列能否达到，并递归计算其四周的格子
{
    if(i>0&&i<m&&j>0&&j<n&&!visited[i*n+j]&&getdigitsum(i)+getdigitsum(j)<=k)
    {
        visited[i*n+j]=true;
        movingcore(m, n, k, i+1, j, visited);
        movingcore(m, n, k, i-1, j, visited);
        movingcore(m, n, k, i, j+1, visited);
        movingcore(m, n, k, i, j-1, visited);
    }
    return;
}
