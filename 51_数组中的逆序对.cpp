#include <iostream>
using namespace std;

int InversePairsCore(int *data, int *tmp, int start, int end);
int InversePairs(int *data, int length)
{
    if(data==nullptr || length<0)
        return -1;

    int *tmp=new int[length];
    int count=InversePairsCore(data,tmp,0,length-1);
    delete[] tmp;
    return count;
}

int InversePairsCore(int *data, int *tmp, int start, int end)   //计算data数组中start到end中逆序对个数，并将其排序
{
    if(start==end)    //只有一个元素时递归结束
        return 0;

    int mid=(start+end)/2;

    //将data数组分为两段，递归计算
    int left=InversePairsCore(data,tmp,start,mid);          //返回左半部分逆序对个数
    int right=InversePairsCore(data,tmp,mid+1,end);         //返回右半部分逆序对个数

    int i=mid;              //data中前半段数组的最后一个下标
    int j=end;              //data中后半段数组的最后一个下标
    int k=end;              //tmp中该段最后一个下标
    int count=left+right;   //保存逆序对总个数
    
    while(i>=start && j>=mid+1) //遍历两段数组直到至少一个数组已遍历完
    {
        if(data[i]>data[j])     //如果第一个数组元素大于第二个数组元素，说明含有逆序对，个数为第二个数字剩余元素个数
        {
            count+=j-mid;       //更新逆序对个数
            tmp[k--]=data[i--]; //将较大值拷贝如临时数组，移动相应下标
        }
        else                    //如果第二个数组元素大于第一个数组元素，说明不是逆序对，拷贝较大元素到临时数组并更新下标
        {
            tmp[k--]=data[j--];
        }
    }
    //当两段数组一个遍历完一个未遍历完时，将未遍历完的数组剩余数组拷贝入tmp数组
    while(i>=start)
        tmp[k--]=data[i--];
    while(j>=mid+1)
        tmp[k--]=data[j--];
    //再将tmp内有序数组拷贝回data,此时k=-1
    for(int index=start; index<=end; index++)
        data[index]=tmp[++k];

    return count;
}

int main()
{
    int a[]={9,2,3,4,5,6,7};
    cout<<InversePairs(a,7);
}
