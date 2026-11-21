#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size(); 
        long cnt = 0; 
        int xorr = 0;
        unordered_map<int, int> mp; 
        mp[0] = 1; 
        for(int x : arr){
            xorr ^= x; 
            int need = xorr ^ k; 
            cnt += mp[need]; 
            mp[xorr]++; 
        }
        return cnt; 
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    Solution obj;
    cout << obj.subarrayXor(arr, k) << endl;
    return 0;
}