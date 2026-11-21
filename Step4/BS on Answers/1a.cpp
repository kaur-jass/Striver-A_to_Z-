#include<bits/stdc++.h>
using namespace std;

int square_root(int n)
{
     int ans = 1;
     int s = 0, e = n-1;
     while(s<=e)
     {
        int mid = s+(e-s)/2;
        if(mid*mid == n)
        {
             return mid;
        }
        else if(mid*mid < n)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
     }
     return ans;
}
int main()
{
    int n; 
    cin >> n;
    cout << square_root(n) << " ";
    return 0;
}