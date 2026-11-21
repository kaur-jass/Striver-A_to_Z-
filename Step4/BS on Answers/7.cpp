#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int x = 1;
    int ans = -1;
    int i = 0;
    while(k>0)
    {
        if(i < n && arr[i] == x) 
        {
            i++;
        }
        else 
        {
            ans = x; 
            k--;
        }
        x++;
    }
    return ans;
}


int main()
{
    int n;
    cin >> n; 
    vector<int> piles(n);
    for(int i = 0; i<n; i++)
    {
        cin >> piles[i];
    }
    int m; 
    cin >> m;
    cout << findKthPositive(piles,m);
    return 0;
}