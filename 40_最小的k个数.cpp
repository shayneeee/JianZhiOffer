#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef multiset<int,greater<int>>  intset;
typedef multiset<int,greater<int>>::iterator setiterator;

void GetLeastNumbers(const vector<int> &data,intset &leastnumber, int k)
{
    leastnumber.clear();

    if(k<1 || (int)data.size()<k)
        return;

    vector<int>::const_iterator iter=data.begin();
    while(iter!=data.end())
    {
        if((int)leastnumber.size()<k)
            leastnumber.insert(*iter);
        else
        {
            setiterator iterGreatest=leastnumber.begin();
            if(*iter<*iterGreatest)
            {
                leastnumber.erase(iterGreatest);
                leastnumber.insert(*iter);
            }
        }

    }

}
