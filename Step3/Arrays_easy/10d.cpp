#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n= nums.size();
    int xor1 = 0, xor2 = 0;
    // int N = n-1; if array starts from 1 do this
    for(int i = 0; i<n;i++)
    {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i+1);
    }
    // xor1 ^= n;
    return xor1  ^ xor2;
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