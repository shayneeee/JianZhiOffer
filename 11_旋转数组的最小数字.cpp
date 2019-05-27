#include <iostream>
#include <stdexcept>
using namespace std;

int minnum(int a[], int start, int end)
{
    if(a[start]<a[end])
        return a[start];

    int s=start;
    int e=end;
    while(a[s]>a[e])
    {
        int middle=(s+e)/2;
        if(e-s==1)
            break;
        if(a[middle]>a[start])
            s=middle;
        if(a[middle]<a[end])
            e=middle;
    }
    return a[e];

}

int Minnum(int a[], int length)
{
    if(a==nullptr||length<0)
    {
        logic_error ex("error parameters");
        throw exception(ex);
    }
    return minnum(a,0,length-1);
}


int main()
{
    int a[]={3,3,5,6,7,8};
    cout<<Minnum(a,6);
}
