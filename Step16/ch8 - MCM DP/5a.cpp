#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp; 
public:
    int minCost(int n, vector<int>& cuts) {
        //dp[i][j]=minimum cost to cut the segment [cuts[i],cuts[j]]
        sort(cuts.begin(), cuts.end());  
        cuts.insert(cuts.begin(), 0); 
        cuts.push_back(n); 
        int m = cuts.size();
        dp.resize(m, vector<int>(m, 0));
        for (int i = m - 2; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {
                if (j == i + 1) {
                    dp[i][j] = 0;
                    continue;
                }
                long long t_cost = LLONG_MAX;
                for (int k = i + 1; k < j; k++) {
                    long long cost = cuts[j] - cuts[i]
                                + dp[i][k]
                                + dp[k][j];

                    t_cost = min(cost, t_cost);
                }
                dp[i][j] = (int)t_cost;
            }
        }
        return dp[0][m-1]; 
    }
};

int main()
{
    int n, c; 
    cin >> n >> c; 
    vector<int> cuts(c);
    for(int i = 0; i < c; i++)
        cin >> cuts[i];
    Solution obj;
    cout << obj.minCost(n, cuts) << endl;
    return 0;
}