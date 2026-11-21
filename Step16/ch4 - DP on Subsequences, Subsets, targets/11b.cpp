#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prev, curr;
    public:
        int rodcutting(int N, vector<int>& price) {
            prev.assign(N+1, 0);
            for(int n = 0; n <= N; n++) {
                prev[n] = n * price[0];
            }
            for(int idx = 1; idx < N; idx++) {
                curr.assign(N+1, 0);

                for(int n = 0; n <= N; n++) {
                    int dont_cut = prev[n];
                    int cut = INT_MIN;
                    int rod_length = idx + 1;
                    if(rod_length <= n) {
                        cut = price[idx] + curr[n - rod_length];
                    }
                    curr[n] = max(cut, dont_cut);
                }
                prev = curr;
            }
            return prev[N];
        }
};

int main(){
    int n; 
    cin >> n; 
    vector<int> price(n); 
    for(int i=0; i<n; i++) cin >> price[i]; 
    Solution obj; 
    cout << obj.rodcutting(n, price) << endl; 
    return 0; 
}
