#include <iostream>
using namespace std;

int GetMaxValue(const int *values, int row, int column)
{
    int length=row*column;
    int *maxvalues=new int[length];     //maxvalues保存从[i,j]开始到右下角的礼物最大值
    int maxvalue=0;                     //存放计算的maxvalues[i,j]值

    for(int i=row-1; i>=0; i--)
    {
        for(int j=column-1; j>=0; j--)
        {
            maxvalue=0;
            int right=0;                //存放maxvalues[i,j+1]
            int down=0;                 //存放maxvalues[i+1,j]

            if(j<column-1)
                right=maxvalues[i*column+j+1];
            if(i<row-1)
                down=maxvalues[(i+1)*column+j];
            
            //maxvalues[i,j]= values[i,j] + max( maxvalues[i,j+1], maxvalues[i+1,j] )
            maxvalue=right>down?right:down;

            maxvalue+=values[i*column+j];

            maxvalues[i*column+j]=maxvalue;
        }
    }
    delete []maxvalues;
    return maxvalue;
}

int main()
{
    int a[16]={1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
    int n=GetMaxValue(a,4,4);
    cout<<n<<endl;

}
