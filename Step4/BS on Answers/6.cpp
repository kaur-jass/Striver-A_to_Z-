#include<bits/stdc++.h>
using namespace std;

int largest(vector<int>& weights)
{
    int maxx = 0; 
    for(int i = 0; i < weights.size(); i++)
    {
        maxx = max(maxx,weights[i]);
    }
    return maxx;
}
int ship(vector<int>& weights, int days, int mid)
{
    int n = weights.size();
    int day = 1, total = 0; 
    for (int i = 0; i<n; i++)
    {
        if(total+weights[i]> mid)
        {
            day++;
            total = weights[i];
        }
        else
        {
            total += weights[i];
        }
    }
    return day;
}
int shipWithinDays(vector<int>& weights, int days) {
        int s = largest(weights);
        int sum = 0;
        for(int i = 0; i<weights.size();i++)
        {
            sum += weights[i];
        }
        int e = sum;
        int day = 0;
        int ans = -1;
        while(s<=e)
        {
        int mid = s+(e-s)/2;
        day = ship(weights, days, mid);
        if (day <=days)
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
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
    cout << shipWithinDays(piles,m);
    return 0;
}