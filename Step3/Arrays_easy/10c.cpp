#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    // Using hashing 
    int hash[n+1] = {0};
    for(int i = 0; i<n; i++)
    {
        hash[nums[i]] = 1;
    }
    for(int i = 0; i <=n; i++)
    {
        if(hash[i] == 0) return i ;
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin >> n;
    }
    cout << "The missing number in the array is " << missingNumber(a) << endl;
    return 0;
}