#include <iostream>
using namespace std;

bool find(int *matri,int rows,int columns,int num)
{
    int i=rows-1;
    int j=0;
    if(matrix=nullptr||rows<0||columns<0)
    {
        cerr<<"error array."<<endl;
        return false;
    }
    while(i>=0&&j<colums)
    {
        int k=*(a+i*columns+j);
        if (k==num)
            return true;
        else if(k<num)
            j++;
        else if(k>num)
            i--;
    }
    return false;
}
