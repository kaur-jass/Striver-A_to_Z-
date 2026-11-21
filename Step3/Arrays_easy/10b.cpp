#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n= nums.size();
    for(int i = 0;i<n; i++)
    {
        int flg = 0;
        for(int j = 0; j<n; j++)
        {
            if(nums[j] == i)
            {
                flg = 1;
                break;
            }
        }
        if(flg == 0) return i;
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