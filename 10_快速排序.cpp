#include <iostream>
using namespace std;

//快排思想：从给定数组中选取一个主元，将数组中比主元小的元素放在主元左边，比主元大的元素放在主元右边，然后对主元左右的数组递归
//主元选取：选择数组头，中，尾三个元素的中位数

void Swap(int *a,int *b)        //交换两个数组内的元素
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int Median3(int a[],int start,int end) 
{
    int center=(start+end)/2;
    if(a[start]>a[center])
        Swap(&a[start],&a[center]);
    if(a[start]>a[end])
        Swap(&a[start],&a[end]);
    if(a[center]>a[end])
        Swap(&a[center],&a[end]);
    //使得a[start]<a[center]<a[end]
    //将a[center]放入a[end-1],接下来只需将a[start+1]到a[end-2]与a[end-1]比较
    Swap(&a[center],&a[end-1]);
    return a[end-1];
}

void Qsort(int a[],int start,int end)
{
    if(end-start<1)
        return;

    int key=Median3(a,start,end);

    //将a[start+1]到a[end-2]与key比较，小的放前面，大的放后面
    int i=start;
    int j=end-1;
    while(1)              
    {
        while(a[++i]<key);      //i从前向后，遇到第一个大于key的则停住
        while(a[--j]>key);      //j从后向前，遇到第一个小于key的则停住
        if(i<j)
            Swap(&a[i],&a[j]);    
        else                //i>=j表示以扫描完所有元素
            break;
    }
    Swap(&a[i],&a[end-1]);    //将key放在i所指的位置
    //对其左右两边的序列递归
    Qsort(a,start,i-1);
    Qsort(a,i+1,end);


}
void QuickSort(int a[], int mlength)//统一接口
{
    Qsort(a,0,mlength-1);
}


int main()
{
    int a[]={10,15,8,8,7,5,20,50,1,5};
    int length=10;
    QuickSort(a,length);
    for(int i=0; i<length; i++)
        cout<<a[i]<<" ";
}
