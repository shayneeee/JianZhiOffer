#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsShunzi(int *pnum, int length)
{
    if(pnum==nullptr || length<1)
        return false;
    vector<int> v;
    for(int i=0; i<length; i++)
        v.push_back(pnum[i]);
    sort(v.begin(),v.end());
    int numofzero=0;
    for(auto i:v)                           //计算0的个数
        if(i==0)
            numofzero++;
    int numofgap=0;
    for(int i=v.size()-1; i>numofzero; i--) //计算空缺的个数
    {
        int gap=v.at(i)-v.at(i-1)-1;
        if(gap==-1)                         //如果出现两个一样的数，返回false
            return false;
        numofgap+=gap;
    }
    return numofgap>numofzero?false:true;
}

int main()
{
    int a[5]={0,0,2,5,6};
    cout<<IsShunzi(a,5)<<endl;

}
