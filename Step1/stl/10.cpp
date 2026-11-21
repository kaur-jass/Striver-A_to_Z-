#include<bits/stdc++.h>
using namespace std;

void explain_multi_set()
{
    // Everything is same as set 
    // Only difference is that it allows duplicate elements and thus stores them in sorted order

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1); // all 1's are erased, now ms is empty

    int cnt = ms.count(1); // returns 0 as no 1's are present

    // only a single one erased 
    ms.erase(ms.find(1)); // now ms is {1,1}

    // ms.erase(ms.find(1), ms.find(1)+2); // WRONG // erases all 1's, now ms is empty
    for (int i = 0; i < 2; ++i) {
    auto it = ms.find(1);
    if (it != ms.end())
        ms.erase(it);
   }

    //rest all functions are same as set
}

int main()
{
    explain_multi_set();
    return 0;
}