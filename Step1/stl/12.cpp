#include<bits/stdc++.h>
using namespace std;

void explain_map()
{
    map<int, int> mpp;
    
    mpp[1] = 2;
    // mpp.emplace({3,1});  // can be store like that 
    mpp.insert({2,4});
    
    map<int, pair<int,int>> mpp;
    map<pair<int,int>, int> mpp;
    

    // mpp[{2,3}] = 10;
    

    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }
    // [{1,2},{2,4},{3,1}]
    cout << mpp[1];   //gives the value 2
    cout << mpp[5];   //5 is not present so it will return 0 as a value
    

    auto it = mpp.find(3);
    cout << (*it).second;  
     
    auto it = mpp.find(5);  // 5 is not there so it will return mpp.end()

    // This is the syntax 

    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    //erase, swap ,size, copy ,empty are same as above 


}

int main()
{
    explain_map();
    return 0;
}