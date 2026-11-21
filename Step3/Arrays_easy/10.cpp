#include<bits/stdc++.h>
using namespace std;
int missing(vector<int> &a) 
{
     int n = a.size();
     int asum = (n * (n + 1)) / 2;
     int sum = 0;
     for(int i = 0; i<n ; i++)
     {
        sum += a[i];
     }
     int no = (asum - sum);
     return no;
}

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n= nums.size();
//         for(int i = 0;i <= n-2;i++)
//         { 
//         int min = i;
//         for(int j = i; j<= n-1; j++)
//         {
//            if(nums[j]<nums[min]) min = j;
//         }
//         swap(nums[min], nums[i]);
//         }
//         int a;
//         for(int i = 0; i<n; i++)
//         {
//         if(nums[i] != i) {
//             a = i;
//             break;
//         }
//         }
//         return a;
//     }
// };
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin >> n;
    }
    cout << "The missing number in the array is " << missing(a) << endl;
    return 0;
}