#include <iostream>
using namespace std;

void arraymerge(int *a1,int length1,int *a2, int length2)
{
    int *p1=a1+length1-1;
    int *p2=a2+length2-1;
    int *p3=a1+length1+length2-1;

    while(p1>=a1&&p2>=a2)
    {
        if(*p1>*p2)
            *(p3--)=*(p1--);
        else
            *(p3--)=*(p2--);
    }
    while(p1<a1&&p2>=a2)
        *(p3--)=*(p2--);
}


int main()
{
    int a1[9]={4,5,7,7,8};
    int a2[]={3,3,5,9};
    arraymerge(a1,5,a2,4);
    for(int i=0; i<9; i++)
        cout<<a1[i]<<" ";
}
