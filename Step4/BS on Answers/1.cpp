#include<bits/stdc++.h>
using namespace std;

int square_root(int n)
{
    int x;
    x = sqrt(n);
    int ans;
    ans = (int)x;
    return ans;
}
int main()
{
    int n; 
    cin >> n;
    cout << square_root(n) << " ";
    return 0;
}